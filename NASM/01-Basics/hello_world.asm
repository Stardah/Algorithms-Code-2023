extern io_print_string
extern io_newline

section .data
    str : db `Hello, world!`, 0

section .text
global main
main:
    ; comment
    mov eax, str
    call io_print_string
    call io_newline
    
    xor eax, eax
    ret
    
    
    