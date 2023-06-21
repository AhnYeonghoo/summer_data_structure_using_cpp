#pragma once;
#include "double_linked_list.hpp"

class LinkedDeque : public DoubleLinkedList
{
public:
	void addFront(Node4* n) { insert(0, n); }
	Node4* deleteFront() { return remove(0); }
	Node4* getFront() { return getEntry(0); }
	void addRear(Node4* n) { insert(size(), n); }
	Node4* deleteRear() { return remove(size() - 1); }
	Node4* getRear() { return getEntry(size() - 1); }
	
};