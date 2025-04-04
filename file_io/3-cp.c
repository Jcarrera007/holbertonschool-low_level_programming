#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Copies content of one file to another
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 on success, exit codes on error
 */
int main(int argc, char *argv[])
{
	int fd, rd, wr, fp;
	char buf[1024];

	if (argc != 3)
		dprintf(2, "Usage: cp file_from file_to\n"), exit(97);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(2, "Error: Can't read from file %s\n", argv[1]), exit(98);

	fp = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fp == -1)
		dprintf(2, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((rd = read(fd, buf, 1024)) > 0)
	{
		wr = write(fp, buf, rd);
		if (wr == -1)
			dprintf(2, "Error: Can't write to %s\n", argv[2]), exit(99);
	}
	if (rd == -1)
		dprintf(2, "Error: Can't read from file %s\n", argv[1]), exit(98);

	if (close(fd) == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd), exit(100);
	if (close(fp) == -1)
		dprintf(2, "Error: Can't close fd %d\n", fp), exit(100);

	return (0);
}

