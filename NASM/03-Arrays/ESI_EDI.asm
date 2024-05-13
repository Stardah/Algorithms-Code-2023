extern io_get_dec
extern io_print_dec
section .data
    a dd 0 ; int *a
    n dd 10 ; int n = 10
section .bss
    b resd 10 ; int b[10]
    arr resd 10

section .text
global main
main:
    mov dword[a], arr ; *a = arr;

    mov esi, [a]    ; src (*a)
    mov edi, b      ; dest (b)
    mov ecx, 0      ; i = 0

.loop:    
    cmp ecx, dword[n] ; i < n
    jge .end
    
    mov eax, dword[esi]   ; eax = a[i]
    mov dword[edi], eax   ; b[i] = eax
    
    add esi, 4
    add edi, 4
    inc ecx ; i++
    jmp .loop 
.end:     
    ;call io_print_dec
    xor eax, eax
    ret