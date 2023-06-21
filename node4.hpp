#pragma once;
#include <cstdio>

class Node4
{
private:
	Node4* prev; // 이전 노드를 가리키기 위한 포인터
	Node4* next; // 앞선 노드를 가리키기 위한 포인터
	int data;
	
public:
	Node4(int val = 0) : data(val), prev(nullptr), next(nullptr) {}
	Node4* getPrev() { return prev; }
	Node4* getNext() { return next; }
	void setPrev(Node4* p) { prev = p; }
	void setNext(Node4* n) { next = n; }
	void display() { printf(" <%2d>", data); }
	bool hasData(int val) { return val == data; }
	
	void insertNext(Node4* n)
	{
		if (n != nullptr)
		{
			n->prev = this;
			n->next = next;
			if (next != nullptr) next->prev = n;
			next = n;
		}
	}

	Node4* remove()
	{
		if (prev != nullptr) prev->next = next;
		if (next != nullptr) next->prev = prev;
		return this;
	}

};