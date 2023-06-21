#include "double_linked_list.hpp"

void main_example6_10()
{
	DoubleLinkedList list;

	list.insert(0, new Node4(10));
	list.insert(0, new Node4(20));
	list.insert(1, new Node4(30));
	list.insert(list.size(), new Node4(40));
	list.insert(2, new Node4(50));
	list.display();

	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node4(90));
	list.display();
	
	list.clear();
	list.display();

}