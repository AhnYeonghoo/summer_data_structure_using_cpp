#include "node4.hpp"

class DoubleLinkedList
{
private:
	Node4 org; // 헤드 노드

public:
	DoubleLinkedList() : org(0) {}
	~DoubleLinkedList() { while (!isEmpty()) delete remove(0); }
	
	Node4* getHead() { return org.getNext(); }
	bool isEmpty() { return getHead() == nullptr; }

	void clear()
	{
		while (!isEmpty()) delete remove(0);
	}

	Node4* getEntry(int pos)
	{
		Node4* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == nullptr) break;
		return n;
	}
	
	void insert(int pos, Node4* n)
	{
		Node4* prev = getEntry(pos - 1);
		if (prev != nullptr) prev->insertNext(n);
	}

	Node4* remove(int pos)
	{
		Node4* n = getEntry(pos);
		return n->remove();
	}

	Node4* find(int val)
	{
		for (Node4* p = getHead(); p != nullptr; p = p->getNext())
			if (p->hasData(val)) return p;
		return nullptr;
	}

	void replace(int pos, Node4* n)
	{
		Node4* prev = getEntry(pos - 1);
		if (prev != nullptr)
		{
			delete prev->getNext()->remove();
			prev->insertNext(n);
		}
	}

	int size()
	{
		int count = 0;
		for (Node4* p = getHead(); p != nullptr; p = p->getNext())
			count++;
		return count;
	}

	void display()
	{
		printf("[이중연결리스트 항목 수 = %2d] : ", size());
		for (Node4* p = getHead(); p != nullptr; p = p->getNext())
			p->display();
		printf("\n");
	}
	
};