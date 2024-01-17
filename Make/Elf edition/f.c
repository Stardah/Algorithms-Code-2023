#include <stdio.h>

extern double f(double);

int main (int argc, char **argv) {
	double x;
	scanf("%lf\n", &x);
	printf("%lf\n", f(x));
	return 0;
}
