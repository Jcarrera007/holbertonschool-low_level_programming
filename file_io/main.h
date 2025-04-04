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


int _putchar(int c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void copy_file(const char *file_from, const char *file_to);
void error_exit(int code, const char *message, const char *arg);

#endif /* MAIN_H */
