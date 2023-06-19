#include <cstdio>

int findMaxValue(int a[], int len)
{
	int max_value = a[0];
	for (int i = 0; i < len; i++)
	{
		if (max_value < a[i])
		{
			max_value = a[i];
		}
	}

	return max_value;
}

int main_example2_2()
{
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int max_value = findMaxValue(arr, 10);
	printf("배열의 최댓값 = %d\n", max_value);

	return 0;
}