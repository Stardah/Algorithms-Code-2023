#include <stdio.h>

#ifdef CAT
#define VOICE "Meow!"
#else /* DOG */
#define VOICE "Woof!"
#endif

int main(void) {
	printf(VOICE "\n");
	return 0 ;
}
