#include "node3.hpp"

class LinkedList
{
private:
	Node3 org; // 헤드 노드
	
public:
	LinkedList() : org(0) {}
	~LinkedList() { clear(); }

	void clear()
	{
		while (!isEmpty()) delete remove(0);
	}
	Node3* getHead() { return org.getLink(); }
	bool isEmpty() { return getHead() == nullptr; }

	Node3* getEntry(int pos)
	{
		Node3* n = &org;
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == nullptr) break;
		return n;
	}

	void insert(int pos, Node3* n)
	{
		Node3* prev = getEntry(pos - 1);
		if (prev != nullptr)
			prev->insertNext(n);
	}
	
	Node3* remove(int pos)
	{
		Node3* prev = getEntry(pos - 1);
		return prev->removeNext();
	}
	
	Node3* find(int val)
	{
		for (Node3* p = getHead(); p != nullptr; p = p->getLink())
		{
			if (p->hasData(val)) return p;
		}
		return nullptr;
	}
	
	void replace(int pos, Node3* n)
	{
		Node3* prev = getEntry(pos - 1);
		if (prev != nullptr)
		{
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}
	
	int size()
	{
		int count = 0;
		for (Node3* p = getHead(); p != nullptr; p = p->getLink())
			count++;
		return count;
	}
	
	void display()
	{
		printf("[전체 항목 수= = %2d] : ", size());
		for (Node3* p = getHead(); p != nullptr; p = p->getLink())
			p->display();
		printf("\n");
	}
	
	
};