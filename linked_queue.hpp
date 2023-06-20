#pragma once;
#include "node2.hpp"

class LinkedQueue
{
private:
	Node* front;
	Node* rear;
	
public:
	LinkedQueue() : front(nullptr), rear(nullptr) {}
	~LinkedQueue()
	{
		while (!isEmpty())
			delete dequeue();
	}
	bool isEmpty() { return front == nullptr; }

	void enqueue(Node* p)
	{
		if (isEmpty()) front = rear = p;
		else
		{
			rear->setLink(p);
			rear = p;
		}
	}

	Node* dequeue()
	{
		if (isEmpty()) return nullptr;
		Node* p = front;
		front = front->getLink();
		if (front == nullptr) rear = nullptr;
		return p;
	}

	Node* peek() { return front; }

	void display() 
	{
		printf("[Å¥ ³»¿ë] : ");
		for (Node* p = front; p != nullptr; p = p->getLink())
			p->display();
		printf("\n");
	}
};
