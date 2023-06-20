#pragma once;
#include <cstdio>

class Node
{
private:
	Node* link;
	int data;

public:
	Node(int val = 0) : data(val), link(nullptr) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf(" <%2d>", data); }

};
