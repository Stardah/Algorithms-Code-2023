section .text
global main
main:

push 10
call pcount_r
add esp, 4
xor eax, eax
ret

pcount_r:                   ; рекурсивная функция для подсчета количества единиц в двоичном представлении числа
    push ebp                ; сохраняем базовый указатель стека
    mov ebp, esp            ; устанавливаем базовый указатель стека равным вершине стека
    push ebx                ; сохраняем регистр ebx
    sub esp, 4              ; выделяем 4 байта в стеке для локальной переменной
    mov ebx, dword [ebp + 8] ; копируем аргумент функции (число) в регистр ebx
    mov eax, 0              ; обнуляем регистр eax (результат функции)
    test ebx, ebx           ; проверяем, равно ли число нулю
    je .L3                  ; если да, то переходим к метке .L3
    mov eax, ebx            ; копируем число в регистр eax
    shr eax, 1              ; сдвигаем число на один бит вправо (деление на 2)
    mov dword [esp], eax    ; сохраняем число в стеке
    call pcount_r           ; вызываем функцию рекурсивно с новым аргументом
    mov edx, ebx            ; копируем число в регистр edx
    and edx, 1              ; применяем побитовое И с 1 (остаток от деления на 2)
    lea eax, [edx + eax]    ; добавляем остаток к результату функции
    
.L3:                        ; метка для выхода из рекурсии
    add esp, 4              ; освобождаем 4 байта из стека
    pop ebx                 ; восстанавливаем регистр ebx
    pop ebp                 ; восстанавливаем базовый указатель стека
    ret                     ; возвращаемся из функции
