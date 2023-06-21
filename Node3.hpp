#pragma once;
#include <cstdio>

class Node3
{
private:
	Node3* link; // 다음 노드를 가리키는 포인터 변수
	int data; // 노드의 데이터 필드

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