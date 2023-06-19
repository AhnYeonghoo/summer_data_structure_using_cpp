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
	printf("swap을 호출하기 전: a=%d, b=%d", a, b);
	swap(a, b);
	printf("swap을 호출한 다음: a=%d, b=%d", a, b);

	return 0;
}