# File Handling and System Calls in C

This document provides an overview of file handling in C, focusing on system calls for file operations,
 file descriptors, standard file descriptors, file access flags, file permissions, and the distinction between functions and system calls.

---

## 1. Creating, Opening, Closing, Reading, and Writing Files in C

In C, file operations can be performed using system calls that interact directly with the operating system's kernel. The primary system calls for file handling are:

- **`open()`**: Opens or creates a file.
- **`close()`**: Closes an open file descriptor.
- **`read()`**: Reads data from a file descriptor.
- **`write()`**: Writes data to a file descriptor.

### Example:

```c
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Open a file for reading
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        // Handle error
        return 1;
    }

    // Read from the file
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        // Handle error
        close(fd);
        return 1;
    }

    // Write to standard output
    ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
    if (bytesWritten == -1) {
        // Handle error
        close(fd);
        return 1;
    }

    // Close the file
    if (close(fd) == -1) {
        // Handle error
        return 1;
    }

    return 0;
}
```

---

## 2. File Descriptors

A **file descriptor** is a non-negative integer that uniquely identifies an open file within a process. When a file is opened,
 the operating system returns a file descriptor that can be used for subsequent operations on the file.

---

## 3. Standard File Descriptors

There are three standard file descriptors in POSIX systems:

- **Standard Input (`STDIN_FILENO`)**: File descriptor 0, used for input operations.
- **Standard Output (`STDOUT_FILENO`)**: File descriptor 1, used for output operations.
- **Standard Error (`STDERR_FILENO`)**: File descriptor 2, used for error messages and diagnostics.

These constants are defined in `<unistd.h>`.

---

## 4. Using `open()`, `close()`, `read()`, and `write()`

- **`open()`**: Opens a file and returns a file descriptor.

```c
int fd = open(const char *pathname, int flags, mode_t mode);
```

- **`close()`**: Closes the file descriptor.

```c
int result = close(int fd);
```

- **`read()`**: Reads from the file descriptor into a buffer.

```c
ssize_t bytesRead = read(int fd, void *buf, size_t count);
```

- **`write()`**: Writes from a buffer to the file descriptor.

```c
ssize_t bytesWritten = write(int fd, const void *buf, size_t count);
```

---

## 5. File Access Flags

Flags used with `open()`:

- `O_RDONLY`: Open for reading only.
- `O_WRONLY`: Open for writing only.
- `O_RDWR`: Open for reading and writing.
- `O_CREAT`: Create file if it does not exist.
- `O_EXCL`: Used with O_CREAT, fail if the file exists.
- `O_TRUNC`: Truncate file to zero length if it exists.
- `O_APPEND`: Append new data to the end of the file.

Flags are combined using the bitwise OR operator (`|`).

---

## 6. File Permissions

When creating a file using `open()` and `O_CREAT`, you specify permissions using an octal value:

| Octal | Meaning               |
|-------|------------------------|
| 0400  | Read by owner          |
| 0200  | Write by owner         |
| 0100  | Execute by owner       |
| 0040  | Read by group          |
| 0020  | Write by group         |
| 0010  | Execute by group       |
| 0004  | Read by others         |
| 0002  | Write by others        |
| 0001  | Execute by others      |

Example:

```c
int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
```

This creates the file with `rw-r--r--` permissions (owner can read/write; group and others can read).

---

## 7. What is a System Call?

A **system call** is a request from a program to the kernel to perform an operation that requires elevated privileges — such as reading from or writing to files, creating processes, or communicating over the network.

System calls transfer control from user mode to kernel mode.

Examples: `read()`, `write()`, `open()`, `close()`, `fork()`, `execve()`

---

## 8. Function vs. System Call

| Aspect           | Function                          | System Call                           |
|------------------|-----------------------------------|----------------------------------------|
| Runs in          | User space                        | Kernel space                           |
| Called from      | Code/libraries                    | Code via library wrappers              |
| Example          | `printf()`                        | `write()`                              |
| Performance      | Faster (no kernel switch)         | Slower (context switch to kernel)      |
| Error handling   | May be abstracted or checked      | Must check return values (`-1`, `errno`) |

In C, most I/O functions like `fopen()` or `fprintf()` are higher-level functions that **wrap system calls** like `open()` and `write()`.

---

## 9. Pro Tips for Learning More

- Use `man 2 open`, `man 2 read`, `man 2 write` to explore system call documentation.
- Use `strace ./program` to see which system calls your program is making.
- Explore documentation on [man7.org](https://man7.org) or [linux.die.net](https://linux.die.net/man).

---

## ✅ Summary

By understanding how file descriptors, system calls, permissions, and standard I/O operations work, you gain direct control over how your C programs interact with the underlying operating system. This is critical for building robust, low-level software and for mastering UNIX-like environments.

Happy coding! 🚀
