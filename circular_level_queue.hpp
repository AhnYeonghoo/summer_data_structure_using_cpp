#pragma once;
#include "binarynode.hpp"
#include <cstdlib>

inline void error6(const char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};

const int MAX_QUEUE_SIZE = 100;

class CircularLevelQueue
{
	int front;
	int rear;
	BinaryNode* data[MAX_QUEUE_SIZE];

public:
	CircularLevelQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	
	void enqueue(BinaryNode* n)
	{
		if (isFull()) error6("ť�� ��ȭ���� �Դϴ�.");
		else
		{
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	BinaryNode* dequeue()
	{
		if (isEmpty()) error6("ť�� ������� �Դϴ�");
		else
		{
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};