#include <stdio.h>

int main(void) {
    short p_val[] = {10, 20};
    short q_val[] = {30, 40};

    short *p = p_val;
    short *q = q_val;

    *p++ = *++q;
    *p++ = --*q;

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