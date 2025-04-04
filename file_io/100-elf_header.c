#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * print_error - Prints an error message and exits with code 98
 * @msg: The error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * check_elf - Checks if file is an ELF file
 * @e_ident: Identifier bytes from the ELF header
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
 * print_class - Print ELF class
 * @class: class type
 */
void print_class(unsigned char class)
{
	printf("  Class:                             ");
	if (class == ELFCLASS32)
		printf("ELF32\n");
	else if (class == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid class\n");
}

/**
 * print_data - Print ELF data encoding
 * @data: encoding type
 */
void print_data(unsigned char data)
{
	printf("  Data:                              ");
	if (data == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (data == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");
}

/**
 * main - Display the ELF header of a file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd, i;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(strerror(errno));

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		print_error("Failed to read ELF header");
	}

	check_elf(header.e_ident);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);

	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		default: printf("Unknown\n"); break;
	}

	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("Unknown type\n"); break;
	}

	printf("  Entry point address:               %#lx\n", (unsigned long)header.e_entry);

	close(fd);
	return (0);
}

