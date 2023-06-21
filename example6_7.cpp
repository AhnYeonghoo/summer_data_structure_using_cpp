#include "linked_list.hpp"

void main_example6_7()
{
	LinkedList list;
	list.insert(0, new Node3(10));
	list.insert(0, new Node3(20));
	list.insert(1, new Node3(30));
	list.display();
	list.insert(list.size(), new Node3(40));
	list.insert(2, new Node3(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node3(90));
	list.display();
	list.clear();
	list.display();

}