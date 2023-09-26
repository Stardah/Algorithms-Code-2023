#include <stdio.h>

long long sum(const int *a, int length)
{
    long long sum = 0;

    for (size_t i = 0; i < length; i++)
    {
        sum += a[i];
    }

    return sum;
}

void print_array(int a[], int length)
{
    // Вывод элементов массива
    for (size_t i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void read_array(int *array, int length)
{
    // Ввод элементов массива
    for (size_t i = 0; i < length; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]); // &a[i] - адрес i-го элемента массива
    }
}

int main(void)
{
    /* Разные способы объявить/инициализировать массив */
    int array[5] = {10, 20, 30, 40, 50};
    int b[5];
    int c[10] = {[0] = 1, [3] = 2, [5] = -3};

    /* sizeof */
    int *ptr;
    int len_ptr = sizeof(ptr); // = 8
    int len_int = sizeof(int); // = 4

    /* Вычисляем размер массива */
    int array_length = sizeof(array) / sizeof(int);

    printf("A[1] = %d\n", *(array + 1)); // A[1] => 20.

    printf("size of array a = %d\n", array_length);
    printf("sum of the elements = %d\n", sum(array, array_length));
    print_array(array, array_length);

    /* Массив переменной длины */
    unsigned int n;
    scanf("%u", &n);

    int h[n];

    read_array(h, n);  // считываем массив
    print_array(h, n); // печатаем массив

    return 0;
}