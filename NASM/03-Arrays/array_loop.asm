extern io_get_dec
extern io_print_dec
section .data
    a dd 0 ; int *a
    n dd 10 ; int n = 10
section .bss
    b resd 10 ; int b[10]

section .text
global main
main:
    
    mov ecx, 0 ; i = 0
loop:    
    cmp ecx, dword[n] ; i < n
    jge end
    
    mov eax, dword[a + 4*ecx]   ; eax = a[i]
    mov dword[b + ecx], eax     ; b[i] = eax
    
    inc ecx ; i++
    jmp loop 
end:     
    ;call io_print_dec
    xor eax, eax
    ret