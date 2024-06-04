extern printf, io_print_hex, io_newline
global main

section .data
    x: dq 9
    y: dq 0.5
    result: dq 0
    fmt: db "%f", 10, 0
    fmti: db "%d", 10, 0
    control_word: dw 0
    num: dq 3.0
    
    
    
section .text
main:
    mov ebp, esp; for correct debugging
    ; x^y
    enter 0, 0
    
    finit
    ; set round rule
    fstcw word[control_word]
    ;and word[control_word], 0xF3FF
    or word[control_word], 0x0c00
    fldcw word[control_word]
       
    
    fld qword[y]
    fild qword[x]
    ; st0 x
    ; st1 y
    fyl2x
    fld st0
    fld st0
    
    ;fist dword[result]
    ;fild dword[result]
    ;fisttp
    frndint
    ; st0 = truc(yl2x)
    ; st1 = yl2x
    
    fsub st1, st0
    ; st0 = truc(yl2x)
    ; st1 = frac(yl2x)
    fxch
    f2xm1
    fld1
    faddp
    ; st0 = 2xm1(frac(yL2x)) + 1
    ; st1 = truc(yl2x)
    fscale
    
    fst qword[result]
    
    push 0
    push dword[result+4]
    push dword[result]
    push fmt 
    call printf
    
    mov eax, dword[result+4]
    call io_print_hex
    mov eax, dword[result]
    call io_print_hex
    call io_newline
    
    mov eax, dword[num+4]
    call io_print_hex
    ;call io_newline
    mov eax, dword[num]
    call io_print_hex
    call io_newline
    ; 400800003
    ; 1000_ ... _ 11
    ; 1,1000... 11 * 2^1
    ; 11,0000000...00 110
    
    ; ieee 754
    ; 40052a7fa9d2f8e9
    ; 0 100_0000_0000 0101
    ; exp = e - 1023 = 2^10 - 2^10 + 1 = 1
    ; m = 52a7fa9d2f8e9 * 2^-52 + 1 = 1,52a7fa9d2f8e9
    ; m * 2^e = 1,52a7fa9d2f8e9 * 2^1 =
    ; 10,101[2a7fa9d2f8e9]
    ; 2,
    
    
    ; st0 = 2xm1(frac(yL2x)) + 1
    ; st1 = yL2x
    ; fscale st0 * 2^truc(st1)
    
    ; fyl2x st1 * log_2(st0)
    ; f2xm1 st0 = 2^st0 - 1 : st0 = [-1, +1]
    
    leave
    ret