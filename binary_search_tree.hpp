#pragma once;
#include "binarytree.hpp"


class BinarySearchTree : public BinaryTree
{
	BinaryNode* root;
public:
	BinarySearchTree(void) {}
	~BinarySearchTree(void) {}
	
	// ���� Ž�� Ʈ���� Ž�� ����
	BinaryNode* searchRecur(BinaryNode* n, int key)
	{
		if (n == nullptr) return nullptr;
		if (key == n->getData()) return n;
		else if (key < n->getData()) return searchRecur(n->getLeft(), key);
		else return searchRecur(n->getRight(), key);
	}

	BinaryNode* searchIter(BinaryNode* n, int key)
	{
		while (n != nullptr)
		{
			if (key == n->getData()) return n;
			else if (key < n->getData()) n = n->getLeft();
			else n = n->getRight();
		}
		return nullptr;
	}

	void insertRecur(BinaryNode* r, BinaryNode* n)
	{
		if (n->getData() == r->getData()) return;
		else if (n->getData() < r->getData()) {
			if (r->getData() == NULL)
			{
				r->setLeft(n);
			}
			else
			{
				insertRecur(r->getLeft(), n);
			}
		}
		else
		{
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}

	// ���� Ž�� Ʈ���� Ž�� ����
	BinaryNode* search(int key)
	{
		BinaryNode* node = searchRecur(root, key);
		if (node != nullptr)
		{
			printf("Ž�� ����: Ű ���� %d�� ��� = 0x%x\n", node->getData(), node);
		}
		else
		{
			printf("Ž�� ����: Ű ���� %d�� ��� ����\n", key);
		}
		return node;
	}

	// ���� Ž�� Ʈ���� ���� ����
	void insert(BinaryNode* n)
	{
		if (n == nullptr) return;
		if (isEmpty()) root = n;
		else insertRecur(root, n);
	}

	void remove(int key)
	{
		if (isEmpty()) return;
		BinaryNode* parent = NULL;
		BinaryNode* node = root;
		
		while (node != nullptr && node->getData() != key)
		{
			parent = node;
			node = (key < node->getData()) ? node->getLeft() : node->getRight();
		}

		if (node == NULL)
		{
			printf(" Error: key is not in the tree!\n");
			return;
		}
		else remove(parent, node);
	}

	void remove(BinaryNode* parent, BinaryNode* node)
		{
			if (node->isLeaf())
			{
				if (parent == nullptr)
				{
					root = nullptr;
				}
				else
				{
					if (parent->getLeft() == node)
					{
						parent->setLeft(NULL);
					}
					else
					{
						parent->setRight(NULL);
					}
				}
			}
			else if (node->getLeft() == nullptr || node->getRight() == nullptr)
			{
				BinaryNode* child = (node->getLeft() != nullptr) ? node->getLeft() : node->getRight();

				if (node == root) root = child;
				else
				{
					if (parent->getLeft() == node)
					{
						parent->setLeft(child);
					}
					else
					{
						parent->setRight(child);
					}
				}
			}
			else
			{
				BinaryNode* succp = node;
				BinaryNode* succ = node->getRight();
				while (succ->getLeft() != nullptr)
				{
					succp = succ;
					succ = succ->getLeft();
				}
				if (succp->getLeft() == succ) succp->setLeft(succ->getRight());
				else succp->setRight(succ->getRight());

				node->setData(succ->getData());
				node = succ;
			}
			delete node;
		}
	
	
	

};