#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

void copy_string(char *dst, const char *src, int length) {
    for (size_t i = 0; i < length; i++) {
        dst[i] = *(src++);
    }
}

int main(void) {
    // Разные спопобы задать строку
    const char *ptr;
    char *strLiteral = "последовательность символов"; // const char *
    char strArray[] = "ok";                         // s[0]='o', s[1]='k', s[2]= '\0'
    short a[] = {'o', 'k', '\0', 0x42F};
    strArray[2] = '!';
    
    // scanf("%2s", &strArray);
    // printf("%s", strArray);

    char *wrong = "wrong";
    // wrong[0] = "i"; // так не работает

    // "Широкие" символы
    wchar_t strWide[] = L"unicode string я";
    wprintf(L"%ls\n", strWide);

    // Длина строки
    const int length = sizeof(strArray) / sizeof(char);

    // Копирование
    // char *dst; // это const char *
    char dst[length];
    copy_string(dst, strArray, length);
    *dst = 'c';

    // Считывание строки
    char str[80];

    printf("Ввод с помощью fgets:\n"); // ввод заканчивается после EOF или
                                       // перевода строки
    fgets(str, sizeof(str), stdin);
    printf("%s\n\n", str);

    // scanf("%s", str) - опасно, так как размер вводимой строки не ограничивается
    printf("Ввод с помощью scanf:\n");
    scanf("%9s", str); // ввод происходит до символа пробел, переноса строки или
                       // достижения указанного лимита
    printf("%s\n\n", str);

    const length2 = strlen(str);
    const size = sizeof(str);
    fwrite(str, sizeof(char), sizeof(str), stdout);
    puts("!");
    puts(str);
    fputs(str, stdout);

    int num = 0;
    char in_str[] = "10";
    scanf("%d", &num);
    fscanf(stdin, "%d", &num);
    sscanf(in_str, "%d", &num);

    /*
    int fprintf(FILE * stream, const char *format, ...);
    int sprintf(char * str, const char *format, ...);
    int snprintf(char * str, size_t size, const char *format, ...);
    int fscanf(FILE *stream, const char *format, ...);
    int sscanf(const char * str, const char *format, ...)
    */

    return 0;
}