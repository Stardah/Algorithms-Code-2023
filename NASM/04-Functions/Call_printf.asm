extern io_print_hex, io_newline

section .data
msg db 'Hello, %s, %x!\n', 0
s db 'World', 0xFFFF, 0x0
d db 0xFFFF, 0xAA, 0xBB, 0xCC

section .text
global main ; делает метку main видимой для других модулей
extern printf ; объявляет, что функция printf определена в другом модуле

; main: - метка начала функции main
main:
    push ebp        ; сохраняет значение регистра ebp (указатель на базу стека) на вершине стека
    mov ebp, esp    ; копирует значение регистра esp (указатель на вершину стека) в регистр ebp
    
    mov eax, dword[d-1]
    call io_print_hex 
    call io_newline
    
    ;sub esp, 8 ; уменьшает значение регистра esp на 4 байта, чтобы выделить место для локальных переменных в стеке
    ;mov dword [esp], msg ; копирует адрес переменной msg в стек (пишет 4 байта по адресу esp)
    push d
    push s
    push msg 
    ; push делает sub esp, 4 и mov [esp], r32
    
    call printf     ; вызывает функцию printf с аргументом, который лежит на вершине стека (адрес строки "Hello, world!")
    
    mov esp, ebp    ; восстанавливает значение регистра esp из регистра ebp, освобождая место в стеке
    pop ebp         ; восстанавливает значение регистра ebp из вершины стека
    ; pop делает mov r32, [esp] и add esp, 4
    
    ret             ; возвращает управление из функции main в вызывающую программу
