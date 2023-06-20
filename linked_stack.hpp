#pragma once;
#include "node.hpp"

class LinkedStack
{
private:
	Node* top; // head pointer

public:
	LinkedStack() { top = nullptr; }
	~LinkedStack() 
	{ 
		while (!isEmpty())
			delete pop();
	}

	bool isEmpty() { return top == nullptr; }
	
	void push(Node* p)
	{
		if (isEmpty()) top = p;
		else
		{
			p->setLink(top);
			top = p;
		}
	}
	
	Node* pop()
	{
		if (isEmpty()) return nullptr;
		Node* p = top;
		top = top->getLink();
		return p;
	}

	Node* peek() { return top; }
	
	void display()
	{
		printf("[LinkedStack]\n");
		for (Node* p = top; p != nullptr; p = p->getLink())
		{
			p->display();
		}
		printf("\n");
	}
	
};