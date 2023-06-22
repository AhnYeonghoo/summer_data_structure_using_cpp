#include "binarytree.hpp"

void main()
{
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', nullptr, nullptr);
	BinaryNode* e = new BinaryNode('E');
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F');
	BinaryNode* c = new BinaryNode('C', f);
	BinaryNode* a = new BinaryNode('A', b, c);
	tree.setRoot(a);
	tree.inorder();
	tree.preorder();
	tree.postorder();
	printf("\n");
}