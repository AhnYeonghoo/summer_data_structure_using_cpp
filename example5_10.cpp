#include "linked_stack.hpp"
void main_example5_11()
{
	LinkedStack stack;
	stack.push(new Node(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	stack.push(new Node(2015130100, "�̼���", "�����а�"));
	stack.push(new Node(2015130135, "Ȳ��", "���а�"));
	stack.display();
	
	Node* node = stack.pop();
	printf("[pop �׸�]\n");
	node->display();
	printf("\n");
	delete node;
	stack.display();
}