#include "binarynode.hpp"
#include "circular_level_queue.hpp"
class BinaryTree
{
	BinaryNode* root;
	
public:
	BinaryTree() : root(nullptr) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == nullptr; }
	
	void inorder() { printf("\n  inorder: "); inorder(root); }
	void inorder(BinaryNode* node)
	{
		if (node != nullptr)
		{
			if (node->getLeft() != nullptr) inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != nullptr) inorder(node->getRight());
		}
	}

	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode* node)
	{
		if (node != nullptr)
		{
			printf(" [%c] ", node->getData());
			if (node->getLeft() != nullptr) preorder(node->getLeft());
			if (node->getRight() != nullptr) preorder(node->getRight());
		}
	}

	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode* node)
	{
		if (node != nullptr)
		{
			if (node->getLeft() != nullptr) postorder(node->getLeft());
			if (node->getRight() != nullptr) postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}
	
	void levelorder()
	{
		printf("\nlevelorder: ");
		if (!isEmpty())
		{
			CircularLevelQueue q;
			q.enqueue(root);
			while (!q.isEmpty())
			{
				BinaryNode* n = q.dequeue();
				if (n != nullptr)
				{
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
			printf("\n");
		}
	}

	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		if (node->isLeaf()) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node)
	{
		if (node == nullptr) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
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