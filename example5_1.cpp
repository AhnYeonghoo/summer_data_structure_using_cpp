#include <cstdio>
using namespace std;

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

void main_example5_1()
{
	int a = 1, b = 2;
	printf("swap을 호출하기 전: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap을 호출한 후: a=%d, b=%d\n", a, b);
}