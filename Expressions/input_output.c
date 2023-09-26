#include <stdio.h>

int main(void)
{
    int c = 'i';
    putchar(c);

    long x;
    double y;
    char z;

    if (scanf("%ld-%lf-%c", &x, &y, &z) != 3)
    {
        printf("no");
    }
    else
    {
        printf("%ld %.2f %c", x, y, z);
    }

    while ((c = getchar()) != EOF && c != 'a')
    {
        putchar(c);
    }
    printf("hi");

    return 0;
}