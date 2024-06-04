
section .text
    global main
    extern hello_c

main:
    ; Вызываем функцию hello из библиотеки C
    mov eax, ~15 ; 11111..110000
    and ebp, eax
    sub ebp, 16

    call hello_c
    ; Завершаем программу
    mov eax, 1
    xor ebx, ebx
    int 0x80
