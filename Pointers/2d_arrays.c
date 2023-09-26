#include <stdio.h>

#define ROWS 3
#define COLS 2

int main(void)
{
    /*
    ROW = 5;
    COLS = 10;
    
    a[ROWS][COLS];
    
    Выражение               Тип           Значение
    &a[i] = (a + i)         int (*)[20]   &a[0][0] + i * COLS * sizeof(int)
    a[i] = *(a + i)         int[20]
    &a[i][j] = a[i] + j     int*          &a[0][0] + i * COLS * sizeof(int) + j
    a[i][j] = *(a[i] + j)   int

    */

    int matrix[ROWS][COLS] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    int(*one_row)[2]; // Указатель на массив из 2-х значений типа int
    int *all_rows[3]; // Указатель на массив из 3-х значений типа int* (указателей на int)
    int *p; 

    one_row = matrix;
    one_row = matrix + 1;
    p = matrix[0];

    // matrix[] это int (*)[];
    // *(int (*)[]) это int[];
    // &(int[]) это int*
    all_rows[0] = &*matrix[0];

    // Вывод содержимого массива
    int *a = *matrix;
    for (size_t i = 0; i < ROWS; i++) {   
        for (size_t j = 0; j < COLS; j++) {
            printf("%d", *a++);
        }
    }
    return 0;
}
