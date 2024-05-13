extern io_print_hex, io_newline

section .data
    a dq 0x8833221188332211
    b dq 0x0833221188332211

section .text
global main
main:
    mov ebx, dword[a] 
    mov eax, dword[a + 4]
    
    dd ebx, dword[b]
    adc eax, dword[b + 4]
    
    jc carry
    
    call io_print_hex
    mov eax, ebx
    call io_print_hex
    
    carry: 
        mov eax, 0xA
        call io_print_hex
    
    xor eax, eax
    ret