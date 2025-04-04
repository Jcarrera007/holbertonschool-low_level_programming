#include "main.h"

/**
 * main - Copies the content of a file to another file.
 * @argc: Quantity of arguments
 * @argv: Input arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd, fd_to, in, out;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"),
			exit(97);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argv[1]), exit(98);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]),
			exit(99);
	in = out = 1;
	while (in)
	{
		in = read(fd, buffer, 1024);
		if (in == -1)
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]),
				exit(98);
		if (in > 0)
		{
			out = write(fd_to, buffer, in);
			if (out == -1)
				dprintf(STDERR_FILENO,
						"Error: Can't write to %s\n", argv[2]),
					exit(99);
		}
	}
	out = close(fd);
	if (out == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd),
			exit(100);
	out = close(fd_to);
	if (out == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to),
			exit(100);
	return (0);
}
