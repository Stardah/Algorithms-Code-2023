#include "sub.h"

extern int add(int a, int b);

int main()
{
    int x = 10;
    add(x, x);
    return sub(x, x);
}