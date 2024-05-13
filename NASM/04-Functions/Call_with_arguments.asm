extern io_print_dec, io_get_string, io_print_string

section .text
global main
main:
    mov ebp, esp; for correct debugging

; STACK:
; 20
; 10
; EIP
; old EBP <- EBP = ESP
; ----  

    ; передаем два аргумента 10 и 20 в функцию add
    push 20                     ; кладем второй аргумент на стек
    push 10                     ; кладем первый аргумент на стек
    call add                    ; вызываем функцию add, call сделает PUSH EIP 
    add esp, 8 ; !!! cdecl
    ; здесь можно использовать результат функции, который будет в регистре EAX
    ;add esp, 8 ; освобождаем память из стека
   
    call io_print_dec
    
    ; определение функции add
    add:
        push ebp                ; сохраняем базовый указатель стека
        mov ebp, esp            ; устанавливаем базовый указатель стека равным вершине стека
        mov eax, [ebp + 8]      ; получаем первый аргумент из стека
        add eax, [ebp + 12]     ; прибавляем к нему второй аргумент из стека
        pop ebp                 ; восстанавливаем базовый указатель стека
        ret ;8                  ; !!! stdcall
    
    xor eax, eax
    ret