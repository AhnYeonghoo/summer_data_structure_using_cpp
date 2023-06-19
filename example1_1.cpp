#include <iostream>
using namespace std;

int arrayMax(int score[], int n)
{
	int tmp = score[0];
	for (int i = 1; i < n; i++)
	{
		if (score[i] > tmp)
		{
			tmp = score[i];
		}
	}

	return tmp;
}

int main_example1_1()
{
	int i[] = { 1, 2, 3, 4, 5 };
	cout << arrayMax(i, 5) << endl;
	return 0;
}