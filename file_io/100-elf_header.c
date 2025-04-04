#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

/**
 * print_error - Print error and exit with code 98
 * @msg: The error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * check_elf - Verify ELF file signature
 * @e_ident: Identifier bytes
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
			e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 ||
			e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");
}

/**
 * swap16 - Swap byte order for 16-bit values
 * @val: value to swap
 * Return: swapped value
 */
unsigned short swap16(unsigned short val)
{
	return (val << 8) | (val >> 8);
}

/**
 * swap32 - Swap byte order for 32-bit values
 * @val: value to swap
 * Return: swapped value
 */
unsigned int swap32(unsigned int val)
{
	return ((val >> 24) & 0xFF) |
		((val >> 8) & 0xFF00) |
		((val << 8) & 0xFF0000) |
		((val << 24) & 0xFF000000);
}

/**
 * swap64 - Swap byte order for 64-bit values
 * @val: value to swap
 * Return: swapped value
 */
unsigned long swap64(unsigned long val)
{
	return ((val >> 56) & 0x00000000000000FFUL) |
		((val >> 40) & 0x000000000000FF00UL) |
		((val >> 24) & 0x0000000000FF0000UL) |
		((val >> 8)  & 0x00000000FF000000UL) |
		((val << 8)  & 0x000000FF00000000UL) |
		((val << 24) & 0x0000FF0000000000UL) |
		((val << 40) & 0x00FF000000000000UL) |
		((val << 56) & 0xFF00000000000000UL);
}

/**
 * print_osabi - Print OS/ABI name
 * @osabi: ELF OS/ABI field
 */
void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:                            ");
	switch (osabi)
	{
		case ELFOSABI_SYSV:     printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX:     printf("UNIX - HP-UX\n"); break;
		case ELFOSABI_NETBSD:   printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX:    printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS:  printf("UNIX - Solaris\n"); break;
		case ELFOSABI_IRIX:     printf("UNIX - IRIX\n"); break;
		case ELFOSABI_FREEBSD:  printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64:    printf("UNIX - TRU64\n"); break;
		case ELFOSABI_ARM:      printf("ARM\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
		default: printf("<unknown: %x>\n", osabi); break;
	}
}

/**
 * main - Display ELF header
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd, i;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno));

	if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
		print_error("Failed to read ELF identifier");

	check_elf(e_ident);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid class\n");

	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");

	printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
	print_osabi(e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;
		unsigned short type;
		unsigned int entry;
		int is_be = (e_ident[EI_DATA] == ELFDATA2MSB);

		if (lseek(fd, 0, SEEK_SET) == -1)
			print_error("Failed to seek in ELF file");
		if (read(fd, &h32, sizeof(h32)) != sizeof(h32))
			print_error("Failed to read 32-bit ELF header");

		type = is_be ? swap16(h32.e_type) : h32.e_type;
		entry = is_be ? swap32(h32.e_entry) : h32.e_entry;

		printf("  Type:                              ");
		switch (type)
		{
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_REL:  printf("REL (Relocatable file)\n"); break;
			case ET_DYN:  printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default:      printf("Unknown type\n"); break;
		}

		printf("  Entry point address:               %#x\n", entry);
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr h64;
		unsigned short type;
		unsigned long entry;
		int is_be = (e_ident[EI_DATA] == ELFDATA2MSB);

		if (lseek(fd, 0, SEEK_SET) == -1)
			print_error("Failed to seek in ELF file");
		if (read(fd, &h64, sizeof(h64)) != sizeof(h64))
			print_error("Failed to read 64-bit ELF header");

		type = is_be ? swap16(h64.e_type) : h64.e_type;
		entry = is_be ? swap64(h64.e_entry) : h64.e_entry;

		printf("  Type:                              ");
		switch (type)
		{
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_REL:  printf("REL (Relocatable file)\n"); break;
			case ET_DYN:  printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default:      printf("Unknown type\n"); break;
		}

		printf("  Entry point address:               %#lx\n", entry);
	}
	else
	{
		print_error("Unsupported ELF class");
	}

	close(fd);
	return (0);
}

