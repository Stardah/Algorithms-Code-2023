extern io_get_dec, io_print_dec, io_print_hex, io_newline

section .data
    a   db 0x40
        dw 0x81
        db 0xFE
        db 0x55
    b   dd 0

section .bss
    src resd 4

section .rodata
    hello_world: db "Hello world!", 0xA, 0x0

section .text
global main
main:   
    mov eax, DWORD [a] ; eax = 0x400081FE
    mov ebx, eax
    sub ebx, 1
    call io_print_hex
    
    mov DWORD [b], ebx
    call io_newline
    
    mov eax, DWORD [b]
    call io_print_hex
     
    xor eax, eax
    ret