#include "binary_search_tree.hpp"

void main_example9_9()
{
	BinarySearchTree tree;
	
	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));
	
	printf(" ����� ����=%d\n", tree.getCount());
	printf(" ������ ����=%d\n", tree.getLeafCount());
	printf(" Ʈ���� ����=%d\n", tree.getHeight());

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();

	tree.search(26);
	tree.search(25);
	

}