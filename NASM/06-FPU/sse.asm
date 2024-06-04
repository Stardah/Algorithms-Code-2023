extern printf, io_print_hex, io_print_dec, io_newline
global main

section .data
    a: dd 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8
    b: dd 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8
    c: dd 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8
    size: dd 8
    fmt: db "%f ", 0
    result: dq 0
    
section .text
main:
    mov ebp, esp; for correct debugging
    enter 0, 0
    
    mov ecx, 0
    
.loop:
    movups xmm0, [a + 4 * ecx]
    movups xmm1, [b + 4 * ecx]
    
    addps xmm0, xmm1
    movups [c + 4 * ecx], xmm0
    
    add ecx, 4
    cmp ecx, [size]
    jl .loop
    
   
    and esp, -16
    sub esp, 8
    mov esi, 0
    finit
.print:
    mov eax, [c + 4 * esi]
    fld dword[c + 4 * esi]
    fst qword[result]
    
    push dword[result + 4]
    push dword[result]
    push fmt
    call printf
    add esp, 4
    inc esi
    cmp esi, [size]
    jl .print
    
    leave
    ret