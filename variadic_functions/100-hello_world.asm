section .data
    message db "Hello, World!", 10  ; Message string with newline
    len equ $ - message             ; Calculate string length

section .text
    global _start                   ; Entry point

_start:
    ; sys_write (syscall number 1)
    mov rax, 1         ; syscall: sys_write
    mov rdi, 1         ; file descriptor 1 (stdout)
    mov rsi, message   ; pointer to message
    mov rdx, len       ; message length
    syscall            ; invoke system call

    ; sys_exit (syscall number 60)
    mov rax, 60        ; syscall: sys_exit
    xor rdi, rdi       ; exit code 0
    syscall            ; invoke system call
