#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *a, int length) {
    for (size_t i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void forgotten_pointer() {
    long long *array = malloc(100 * sizeof(long long));

    long long *p = realloc(array, 200 * sizeof(long long));

    // Теперь использование array - UB
    *array = 10;
    free(p);
}

void classic_memory_leak() {
    char *str = malloc(1000000 * sizeof(char)); // ~1мб

    // После завершения выполнения процедуры
    // указатель очистится
    // а зарезервированная на куче память останется
    // free(str);
}

void nested_memory_leak() {
    // 1 000 000 000 байт = 954 мб
    const int array_size = 100000;
    const int sub_array_size = 10000; // 100000
    int **array2d = malloc(array_size * sizeof(int *));

    for (size_t i = 0; i < array_size; i++) {
        array2d[i] = calloc(sub_array_size, sizeof(int));
    }

    free(array2d);
    // array2d освобождена
    // а вот все выделения для sub_array
    // до сих пор зарезервированы в памяти
    // for (int i = 0; i < array_size; i++) {
    //     free(x[i]);
    // }
}

// Процедуры, которые не подчищают за собой память, опасны
char *fill(char value) {
    char *p = malloc(100 * sizeof(char));
    for (size_t i = 0; i < 100; i++) {
        p[i] = value;
    }
    return p; // кто будет чистить p?
}

void function_leak() {
    char *str[1];
    str[0] = fill('F'); // Утечка (´。＿。｀)
    // free(str[0]);
}

bool return_leak(int value) {
    char *p = malloc(100 * sizeof(char));

    if (value)
        return true;

    free(p);
    return false;
}

int main(void) {
    // forgotten_pointer();
    // classic_memory_leak();
    nested_memory_leak();
    // function_leak();
    // return_leak(true);

    int input;
    scanf("%d", &input);
    return 0;
}
