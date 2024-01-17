section .data
    a dq 2.5
    b dq 3

section .text
global f
f:
    push ebp
    mov ebp, esp
    finit
    fld qword[a]
    fld qword[ebp+8]
    fmulp
    fild qword[b]
    faddp
    leave
    ret