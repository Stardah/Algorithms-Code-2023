#include <stdio.h>
#include <string.h>

void print_array(const int *a, int length) {
    for (size_t i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/**
 * Предполагается, что и строка, и префикс функция начинаются с индекса 1
 * @param str - входная строка
 * @param prefix - массив для значений префикс функции
 */
void prefix_function(const char *str, int *prefix) {
    int prefix_index = 0; // индекс префикса
    prefix[0] = 0;        // нулевой индекс не учитывается
    prefix[1] = 0;        // первое значение префикс функции

    for (size_t i = 2; i <= strlen(str); i++) // Что не так?
    {
        while (prefix_index > 0 && str[prefix_index + 1] != str[i]) {
            prefix_index = prefix[prefix_index];
        }

        if (str[prefix_index + 1] == str[i]) {
            prefix_index++;
        }

        prefix[i] = prefix_index;
    }
}

int main(int argc, char const *argv[]) {
    char str[] = "_ababc"; // символ "_" просто заполняет нулевой индекс
    int pi[strlen(str)];

    prefix_function(str, pi);
    print_array(pi, sizeof(pi) / sizeof(int));

    return 0;
}
