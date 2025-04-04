#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Handles error messages and exits with a specific code.
 * @exit_code: The exit code.
 * @message: The error message to print.
 * @file_name: The file name to include in the error message.
 */
void error_exit(int exit_code, const char *message, const char *file_name)
{
    if (file_name)
        dprintf(STDERR_FILENO, "%s %s\n", message, file_name);
    else
        dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

int _putchar(int c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
