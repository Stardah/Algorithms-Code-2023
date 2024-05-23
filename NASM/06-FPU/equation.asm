; This program divides two numbers using FPU in NASM
; It takes two numbers as command line arguments and prints the quotient
; It assumes that the arguments are valid floating point numbers

section .data
    fmt db "%f", 0         ; format string for printf
    input_a db "5.0", 0  
    
    a dq 5.0
    b dq 3.0

section .text
    global main
    extern printf, atof, exit

main:
    finit

    sub esp, 16
    push input_a            ; push a string with the first arg
    call atof               ; returns float in st0
    add esp, 16

    fld qword[b]            ; push b to the FPU stack (st0 = b, st1 = a)
                            
    fdivp st1, st0          ; st1 = st1/st0, pop st0 ; (st0 = a/b!)
                            
    sub esp, 16             ; print the result using printf
    fstp qword[esp + 4]     ; store the result
    mov dword[esp], fmt     ; push format string to the stack
    call printf             ; call printf function
    add esp, 16             ;

                            ; exit the program
    push dword 0            ; push exit code to the stack
    call exit               ; call exit function

