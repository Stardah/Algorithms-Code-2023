#include <stdio.h>

extern void hello() __asm__("hello_c");

extern void __cdecl hello() {
    printf("Hello, World!\n");
    //return 0;
}
