#include "linked_stack.hpp"
void main_example5_11()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
	stack.push(new Node(2015130100, "이순신", "기계공학과"));
	stack.push(new Node(2015130135, "황희", "법학과"));
	stack.display();
	
	Node* node = stack.pop();
	printf("[pop 항목]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
}