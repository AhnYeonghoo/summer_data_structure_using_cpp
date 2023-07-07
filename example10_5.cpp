#include "max_heap.hpp"
#include <cstdlib>

void heapSort(int a[], int n)
{
	MaxHeap h;
	for (int i = 0; i < n; i++)
	{
		h.insert(a[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = h.remove().getKey();
	}
}

void main_example10_5()
{
	MaxHeap heap;
	
	int data[10];
	
	for (int i = 0; i < 10; i++) data[i] = rand() % 100;
	printf("정렬 전\n");
	
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);
	
	heapSort(data, 10);
	
	printf("정렬 후\n");
	for (int i = 0; i < 10; i++) printf("%3d", data[i]);
	printf("\n");

}