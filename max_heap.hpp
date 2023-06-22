#include "heapnode.hpp"
const int MAX_ELEMENT = 200;

class MaxHeap
{
private:
	HeapNode node[MAX_ELEMENT]; // 요소의 배열
	int size; // 힙의 현재 요소의 개수
public:
	MaxHeap() : size(0) {}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }
	
	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }
	
	void insert(int key)
	{
		if (isFull()) return;
		int i = ++size;
		
		while (i != 1 && key > getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}

	HeapNode remove()
	{
		if (isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size)
		{
			if (child < size && getLeft(parent).getKey() < getRight(parent).getKey()) child++;
			if (last.getKey() >= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}
	
	HeapNode find() { return node[1]; }

	void display()
	{
		for (int i = 1, level = 1; i <= size; i++)
		{
			if (i == level)
			{
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n-------------------------");
	}
};