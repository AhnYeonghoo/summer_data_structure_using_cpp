#include <cstdio>
void main_example5_4()
{
	char* str = new char[1000];
	if (str == nullptr)
	{
		printf("Insufficient memory available\n");
	}
	else
	{
		printf("Allocated 1000 bytes\n");
		delete[] str;
		printf("Memory freed\n");
	}
}