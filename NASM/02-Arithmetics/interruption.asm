extern io_print_hex, io_newline

section .data
    hello dq "Hello", 0

section .text
global main
main:
    mov eax, 1      ; The system call for write (sys_write)
    mov ebx, 1      ; File descriptor 1 - stdout
    mov ecx, hello  ; Address
    mov edx, 5      ; Length
    
    int 080h
    
    xor eax, eax
    ret