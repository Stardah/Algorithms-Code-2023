extern io_print_string, io_print_hex
extern io_newline

section .text
global main
main:

; Task T1
    mov eax, dword[a]
    cmp eax, dword[b]
    cmovb eax, dword[b]
    mov dword[x], eax

; Task T2
    mov eax, dword[a]
    mov edx, dword[a + 4]
    add eax, dword[b]
    adc edx, dword[b + 4]
    sub eax, dword[c]
    sbb edx, dword[c + 4]
    mov dword[a], eax
    mov dword[a + 4], edx


; Task T3
    mov ecx, dword[n]
    inc ecx
    lea ebx, [a + 4*ecx - 4]
    xor eax, eax
L:
    imul eax, dword[x]
    add eax, dword[ebx]
    sub ebx, 4
    dec ecx
    jne L
    mov dword[f], eax


; Task T4
    cmp dword[a], 0
    je L1
    mov eax, dword[b]
    cdq
    idiv dword[a]
    jmp L2
L1:
    mov eax, 0
L2:
    mov dword[x], eax


; Task T5
    mov eax, dword[a]
    imul dword[b]
    idiv dword[c]
    mov dword[x], eax


; Task T6
    mov eax, 1
L:
    xchg eax, dword[s]
    cmp eax, 1
    je L
    
    
; Task T7   
    mov ebx, dword[b]
    test ebx, ebx
    je L
    cmp dword[ebx], 0
    jne L
    mov dword[ebx], 1
L:


; Task T8 
    movsx eax, word[a]
    movsx ebx, word[b]
    movsx ecx, word[c]
    cmp eax, ebx
    jl L1
    cmp eax, ecx
    jge L2
L1:
    add word[a], 10h
    jmp L3
L2:
    sub word[a], 10h
L3:


; Task T9
    mov eax, dword[a]
    mov ebx, dword[b]
    mov ecx, dword[c]
    cmp eax, ebx
    jg L0
    cmp ebx, ecx
    jle L1
L0:
    cmp eax, ebx
    jl L2
    cmp ebx, ecx
    jl L2
L1:
    mov dword[res], 1
    jmp L3
L2:
    mov dword[res], 0
L3:

    xor eax, eax
    ret