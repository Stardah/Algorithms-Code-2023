#include <stdio.h>
#include <string.h>

void str_token_test() {
    char *tokens[50];

    char str[] = "- This, a sample string.";
    char *token;
    printf("Splitting string \"%s\" into tokens:\n", str);
    token = strtok(str, " ,.-");
    tokens[0] = token;
    int i = 1;
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,.-");
        tokens[i] = token;
        i++;
    }
}

int main(void) {

    str_token_test();

    char str1[80] = "test string";
    char str2[80] = "test string1";

    printf("длина str1: %d\n", strlen(str1));

    if (!strcmp(str1, str2)) { // сравнение строк; 0 при s1 == s2; -1 при s1 < s2; 1 при s1 > s2
        printf("строки равны\n");
    } else {
        printf("строки разные\n");
    }

    strcat(str1, str2); // конкатенация строк str1 = str1 + str2

    char *entryChar = strchr(str1, 's');     // вхождение символа в строку
    char *entryStr = strstr(str1, "string"); // вхождение строки в строку
    char *token = strtok(str1, "s,.! i");    // токен, разделённый одним из символов
    // strtok сохраняет str в буффер
    // записывает \0 на место разделителя
    // и возвращает указатель на первый токен
    // str1[2] = '?';

    printf("%s\n", str1);

    char str[80];
    sprintf(str, "Так и запишем: %s", str1);
    puts(str);
    return 0;
}