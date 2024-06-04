#include <stdio.h>

extern int add(int a, int b);

int main(int argc, char **argv)
{
  printf("Hello, World!\n");
  printf("%d\n", add(22, 6));
  return 0;
}
