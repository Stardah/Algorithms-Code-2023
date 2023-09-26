#include <stdio.h>

int sum(const int *a, const int *b)
{
    //*a = 10; // error: cannot change constant value

    return *a + *b;
}

int main(void)
{
    int first_value = 5, second_value = 15;
    int *pointer1;
    int* pointer2;

    pointer1 = &first_value;  // pointer1 = адрес first_value
    pointer2 = &second_value; // pointer2 = адрес second_value

    *pointer1 = 10;        // значение по адресу pointer1 = 10
    *pointer2 = *pointer1; // значение по адресу pointer2 = значение по адресу pointer1

    pointer1 = pointer2; // копируем значение указателя
    *pointer1 = 20;      // значение по адресу pointer1 = 20

    printf("first value is %d\n", first_value);   // 10
    printf("second value is %d\n", second_value); // 20

    printf("a + b = %d\n", sum(&first_value, &second_value));

    return 0;
}