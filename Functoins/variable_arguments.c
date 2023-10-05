#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...)
{
    int result = 0;
    va_list arg_list; // указатель на va_list (typedef char* va_list;)

    va_start(arg_list, n); // стартуем

    for (int *ptr = &n; n > 0; n--)
    {
        result += va_arg(arg_list, int); // получаем аргумент
    }

    va_end(arg_list); // заканчиваем работу с аргументами
    return result;
}

int main(void)
{
    printf("%d \n", sum(4, 1, 2, 3, 4));
    return 0;
}
