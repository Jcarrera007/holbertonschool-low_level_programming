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
 * check_elf - Check if file is an ELF file
 * @e_ident: ELF identification bytes
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
 * print_osabi - Print OS/ABI name
 * @osabi: ELF OS/ABI field
 */
void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:                            ");
	switch (osabi)
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default:
			printf("Unknown: %x>\n", osabi);
			break;
	}
}

/**
 * main - Entry point: display ELF header
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
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
		lseek(fd, 0, SEEK_SET);
		if (read(fd, &h32, sizeof(h32)) != sizeof(h32))
			print_error("Failed to read 32-bit ELF header");

		printf("  Type:                              ");
		switch (h32.e_type)
		{
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;
			case ET_DYN: printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default: printf("Unknown type\n"); break;
		}

		printf("  Entry point address:               %#x\n", h32.e_entry);
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr h64;
		lseek(fd, 0, SEEK_SET);
		if (read(fd, &h64, sizeof(h64)) != sizeof(h64))
			print_error("Failed to read 64-bit ELF header");

		printf("  Type:                              ");
		switch (h64.e_type)
		{
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;
			case ET_DYN: printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default: printf("Unknown type\n"); break;
		}

		printf("  Entry point address:               %#lx\n", (unsigned long)h64.e_entry);
	}
	else
	{
		print_error("Unsupported ELF class");
	}

	close(fd);
	return (0);
}


