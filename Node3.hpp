#pragma once;
#include <cstdio>

class Node3
{
private:
	Node3* link; // ���� ��带 ����Ű�� ������ ����
	int data; // ����� ������ �ʵ�

public:
	Node3(int val = 0) : data(val), link(nullptr) {}
	
	Node3* getLink() { return link; }
	void setLink(Node3* next) { link = next; }

	void display() { printf(" <%2d>", data); }
	bool hasData(int val) { return data == val; }
	
	void insertNext(Node3* n)
	{
		if (n != nullptr)
		{
			n->link = this->link;
			this->link = n;
		}
	}

	Node3* removeNext()
	{
		Node3* removed = this->link;
		if (removed != nullptr)
			this->link = removed->link;
		return removed;
	}
	
};