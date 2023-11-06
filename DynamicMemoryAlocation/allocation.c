#include <stdlib.h>
#include <string.h>

int main(void) {
    // void *malloc (size_t size); - memory-alloc
    // void *calloc (size_t n, size_t size); - clear-alloc - заполняет выделяемую область нулями
    // void *realloc (void *ptr, size_t size);
    // void free (void *p);

    // Герантии выделения памяти нет
    // Все переменные могут оказаться равны NULL
    long long *array = malloc(100 * sizeof(long long)); // ~ realloc(NULL, _Size);
    long long *same_array1 = malloc(sizeof(long long[100]));
    long long *same_array2 = malloc(100 * sizeof(array));

    long long *clear_array = calloc(100, sizeof(long long));

    // По возможности realloc выделит дополнительную память там же
    // иначе выделит память в новой области кучи,
    // гарантий нет
    long long *ptr = realloc(array, 200 * sizeof(long long));
    if (ptr != NULL)
        array = ptr;

    free(array); // ~ realloc(_Block, 0);
    free(same_array1);
    free(same_array2);
    free(clear_array);

    // void memset(void *dest, int ch, size_t count); Заполняет память байтом ch
    char str[5];
    memset(str, 'G', 9);

    // void memcpy(void *dst, const void *src, size_t n); Копирует содержимое памяти
    char str_cpy[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    memcpy(str_cpy + 1, str_cpy, 3);

    // void memmove(void *dst, const void *src, size_t n); - memcpy with memory overlapping check
    char str_move[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    memmove(str_move + 1, str_move, 3);
    return 0;
}
