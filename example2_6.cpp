#include <cstdio>

void swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main_example2_6()
{
	int a = 1, b = 2;
	printf("swap�� ȣ���ϱ� ��: a=%d, b=%d", a, b);
	swap(a, b);
	printf("swap�� ȣ���� ����: a=%d, b=%d", a, b);

	return 0;
}