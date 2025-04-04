#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_error - print error message and exit
 * @code: exit code
 * @message: error format
 * @arg: string to insert
 */
void print_error(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - copies content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exit with appropriate error code
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r_bytes, w_bytes;
	char buffer[BUF_SIZE];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error(99, "Error: Can't write to %s\n", argv[2]);
	}

	while (1)
	{
		r_bytes = read(fd_from, buffer, BUF_SIZE);
		if (r_bytes == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error(98, "Error: Can't read from file %s\n", argv[1]);
		}
		if (r_bytes == 0)
			break;

		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes == -1 || w_bytes != r_bytes)
		{
			close(fd_from);
			close(fd_to);
			print_error(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

