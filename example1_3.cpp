#include <iostream>
using namespace std;

int sequentialSearch(int list[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i] == key)
			return list[i];
	}
	return -1;
}

int main_example1_3()
{
	int data[] = { 3, 5, 10, 7, 2 };
	int key = 3;
	cout << sequentialSearch(data, sizeof(data), key);

	return 0;
}