extern malloc       ; объявляем внешнюю функцию malloc
extern free

section .data
    size dd 100         ; размер блока для выделения

section .text
    global main         ; объявляем главную функцию как глобальную

; _start:

main:
    enter 0, 0
    and esp, -16
    ; 0x10 -> EF + 1 -> F0
    
    ;push ebp            ; сохраняем старый базовый указатель стека
    ;mov ebp, esp        ; устанавливаем новый базовый указатель стека
    ;push ebx
    ;sub esp, 4

    push dword[size]    ; кладем на стек размер блока
    ;mov edx, dword[size]
    call malloc         ; вызываем функцию malloc
    add esp, 4          ; убираем аргумент со стека
    mov ebx, eax        ; сохраняем указатель на выделенный блок в ebx

    push ebx
    ;mov ecx, ebx
    call free
    add esp, 4

    ;mov esp, ebp
    ;pop ebp
    leave               ; восстанавливаем esp и извлекаем ebp (эквивалентно mov esp, ebp и pop ebp)
    ret                 ; возвращаемся из главной функции
