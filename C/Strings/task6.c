#include <stdio.h>
#include <stdint.h>
#include <string.h>

void remove_first_char(char *dst, const char *src)
{
    for (size_t i = 0; i < strlen(src); i++)
    {
        dst[i] = src[i+1];
    }
}

int main()
{
    const char str[] = "COG,dog,frog,fog,blog,log,string";
    printf("Initial string: %s\n", str);

    // Task 2 Напишите функцию, которая дописывает к строке восклицательный знак в конце
    char new_str[strlen(str)+2];
    size_t i = 0;
    while (str[i]) {
        new_str[i] = str[i];
        i++;
    } 
    new_str[i++] = '!';
    new_str[i] = '\0';
    printf("Added '!': %s\n", new_str);

    // Task 3 Напишите функцию, которая удаляет из строки первый символ.
    //strcpy(str, (str+1));
    char dst[strlen(str)];
    remove_first_char(dst, str);
    printf("Removed the first char: %s\n", dst);

    // Task 6
    const char *delimiters = ",";
    const char *words[100];
    // strtok возвращает указатель на последнюю найденную лексему
    char *token = strtok(str, delimiters);

    i = 0;
    while (token != NULL)
    {
        words[i] = token;

        // strtok хранит внутри static char* (указатель на строку)
        // далее можно передавать просто NULL pointer
        token = strtok(NULL, delimiters);

        printf("%s\n", words[i]);
        i += 1;
    }

    return 0;
}