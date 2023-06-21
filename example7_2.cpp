#include <cstdio>
int factorial2(int n)
{
	printf("factorial2(%d)\n", n);
	if (n == 1) return 1;
	else return (n * factorial2(n - 1));
	
}