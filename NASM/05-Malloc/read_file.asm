section .data
    mode db "r", 0          ; строка для режима чтения, rb для бинарников
    path db "input.txt", 0  ; строка для пути к файлу
    format db "%s", 0       ; строка для спецификатора формата

section .text
    global main
    extern fopen
    extern fgets
    extern printf
    extern fclose

main:
    enter 128, 0
    ;push ebp                ; сохраняем старый базовый указатель стека
    ;mov ebp, esp            ; устанавливаем новый базовый указатель стека
    ;sub esp, 120            ; выделяем 120 байт на стеке для буфера
    ;sub esp, 8              ; выделяем 8 байт на стеке для указателя на файл

                            ; open("filename.txt", "w");
    push mode               ; кладем на стек строку для режима чтения
    push path               ; кладем на стек строку для пути к файлу
    call fopen              ; вызываем функцию fopen для открытия файла
    add esp, 16             ; убираем аргументы со стека
    mov DWORD [ebp-12], eax ; сохраняем указатель на файл в [ebp-12]

                            ; fgets(char *str, int n, FILE *stream);
    sub esp, 4              ; выравниваем стек по границе 16 байт
    push DWORD [ebp-12]     ; кладем на стек указатель на файл
    push 100                ; кладем на стек максимальное количество символов для чтения
    lea eax, [ebp-112]      ; загружаем адрес буфера в eax
    push eax                ; кладем на стек адрес буфера
    call fgets              ; вызываем функцию fgets для чтения строки из файла в буфер
    add esp, 16             ; убираем аргументы со стека

    sub esp, 8              ; выравниваем стек по границе 16 байт
    lea eax, [ebp-112]      ; загружаем адрес буфера в eax
    push eax                ; кладем на стек адрес буфера
    push format             ; кладем на стек строку для спецификатора формата
    call printf             ; вызываем функцию printf для вывода содержимого буфера на экран
    add esp, 16             ; убираем аргументы со стека

    sub esp, 12             ; выравниваем стек по границе 16 байт
    push DWORD [ebp-12]     ; кладем на стек указатель на файл
    call fclose             ; вызываем функцию fclose для закрытия файла
    add esp, 16             ; убираем аргумент со стека

    nop
    nop   
    nop
    
    leave                   ; восстанавливаем esp и извлекаем ebp (эквивалентно mov esp, ebp и pop ebp)
    ret                     ; возвращаемся из главной функции
