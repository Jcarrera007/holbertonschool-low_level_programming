section .data
    msg db "Hello, World", 10  ; Message with newline character
    len equ $ - msg             ; Calculate message length

section .text
    global _start               ; Entry point for the linker

_start:
    mov rax, 1                  ; syscall: write
    mov rdi, 1                  ; file descriptor: stdout
    mov rsi, msg                ; pointer to message
    mov rdx, len                ; message length
    syscall                     ; invoke system call

    mov rax, 60                 ; syscall: exit
    xor rdi, rdi                ; status: 0
    syscall                     ; invoke system call

