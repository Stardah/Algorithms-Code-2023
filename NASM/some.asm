; int *a;
; int n = 10;
; int b[10];
; for(int i = 0; i < n; i++) {
;   b[i] = a[i]
; }

section .data
    n dd 10
    
section .bss
    a resd 1 ; int *a
    src resd 10 ; int
    b resd 10 ; int
     
section .text 
global main
main:
    mov dword[a], src

    mov esi, dword[a]
    mov edi, b
    mov ecx, dword[n] ; i = n
    rep movsd
    
    mov esi, dword[a]
    mov edi, b
    mov ecx, dword[n] ; i = 0
    dec ecx
    je .end
.loop:
    mov eax, dword[esi] 
    mov dword[edi], eax
    
    add esi, 4
    add edi, 4
    dec ecx
    jnz .loop

.end:    
    xor eax, eax
    ret

    
    
    
    
    
    
    
    
    
    
    