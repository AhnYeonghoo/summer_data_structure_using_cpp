#include <cstdio>

const int MAX_SIZE = 10;

void sub(int x, int arr[])
{
	x = 10;
	arr[0] = 10;
}

int main_example2_1()
{
	int var;	// ���� ������ ����
	int list[MAX_SIZE]; // ���� �迭�� ����

	var = 0;
	list[0] = 0;
	sub(var, list);
	printf("var=%d, list[0]=%d\n", var, list[0]);
	return 0;

}