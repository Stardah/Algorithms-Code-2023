#include <stdio.h>

#define ROWS 3
#define COLS 2

void print_size(int n, int m, int a[n][m]) {
    printf("Size: %d\n", sizeof(a));
}

int main(void) {
    /*
    ROW = 5;
    COLS = 10;

    a[ROWS][COLS];

    int * != int (*)[20]

    Выражение               Тип           Значение
    a[i] = *(a + i)         int[20]
    &a[i] = (a + i)         int (*)[20]   &a[0][0] + i * COLS * sizeof(int)
    &a[i][j] = a[i] + j     int*          &a[0][0] + i * COLS * sizeof(int) + j
    a[i][j] = *(a[i] + j)   int

    */

    int matrix[ROWS][COLS] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    printf("%d\n", matrix[0][2]); // выводит 3

    int(*row)[2];     // Указатель на массив из 2-х значений типа int
    int *all_rows[3]; // Указатель на массив из 3-х значений типа int* (указателей на int)
    int *p;

    row = matrix;     // matrix[0]
    row = matrix + 1; // на следующую строку
    p = matrix[0];

    print_size(ROWS, COLS, row);

    // matrix[0]    vs  matrix
    // int[] (int*) vs  int (*)[]

    // matrix[i] это int (*)[];
    // *(int (*)[]) это int[];
    // &(int[]) это int*
    all_rows[0] = &*matrix[0]; // так не надо
    all_rows[0] = matrix[0];   // а вот так надо

    // Вывод содержимого массива
    int *a = *matrix;
    printf("  matrix: %x\n", matrix);   // указатель на массив первой строки
    printf(" *matrix: %x\n", *matrix);  // адрес первого элемента строки
    printf("**matrix: %x\n", **matrix); // первый элемент строки
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            printf("%d ", *a++);
            // printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
