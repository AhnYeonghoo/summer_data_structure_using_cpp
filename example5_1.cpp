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
	printf("swap�� ȣ���ϱ� ��: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap�� ȣ���� ��: a=%d, b=%d\n", a, b);
}