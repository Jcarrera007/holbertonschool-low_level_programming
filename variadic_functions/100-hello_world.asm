section .data
    msg db "Hello, World", 10  ; Message to print, 10 is newline (\n)
    len equ $ - msg            ; Calculate length of message

section .text
    global _start              ; Entry point

_start:
    mov rax, 1                 ; syscall: sys_write (1)
    mov rdi, 1                 ; file descriptor: stdout (1)
    mov rsi, msg               ; pointer to message
    mov rdx, len               ; message length
    syscall                    ; invoke system call

    mov rax, 60                ; syscall: sys_exit (60)
    xor rdi, rdi               ; exit code 0
    syscall                    ; invoke system call

