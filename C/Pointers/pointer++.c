#include <stdio.h>

int main(void)
{

    char *mychar;
    short *myshort;
    long *mylong;

    ++mychar;
    ++myshort;
    mylong = mylong + 1;

    int value = 5;
    int *pointer;
    pointer = &value;
    (*pointer)++;
    printf("pointer value is %d\n", *pointer);

    *pointer++; // что произойдёт?


    printf("*pointer value is %d\n", *pointer);
    printf("pointer value is %d\n", pointer);

    return 0;
}