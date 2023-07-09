#include <queue>
#include <iostream>
using namespace std;

const int MAX_DEGREE = 2;

template<class T>
class BNode
{
public:
	T data_;
	BNode* parent_, * left_, * right_;
	
	BNode(const T& data)
		: data_(data), left_(nullptr), right_(nullptr), parent_(nullptr)
	{}
	~BNode();
};

template<class T>
BNode<T>::~BNode()
{
	delete left_, right_, parent_;
}

template<class T>
class BTree
{
private:
	void _insert(BNode<T>* root, BNode<T>* newNode); // 삽입
	void _preOrder(BNode<T>* root) const; // 전위순회
	void _inOrder(BNode<T>* root) const; // 중위순회
	void _postOrder(BNode<T>* root) const; // 후위순회
	void _dfs(BNode<T>* root) const; // BFS

	int count_;
	BNode<T>* root_;

public:
	BTree() : count_(0), root_(nullptr) {}
	void insert(const T& data);
	bool empty() const;
	int size() const;
	void traversal() const;
	void DFS() const;
	void BFS() const;
};

template<class T>
void BTree<T>::insert(const T& data) // 삽입 연산
{
	if (empty())
	{
		root_ = new BNode<T>(data);
		++count_;
	}
	else
	{
		BNode<T>* newNode = new BNode<T>(data);
		_insert(root_, newNode);
	}
}

template<class T>
void BTree<T>::_insert(BNode<T>* root, BNode<T>* newNode)
{
	std::queue<BNode<T>*> q;
	
	if (!root) return;
	
	q.push(root);
	
	while (!q.empty())
	{
		BNode<T>* curNode = q.front();
		q.pop();
		
		if (curNode->left == nullptr)
		{
			curNode->left = newNode;
			return;
		}
		else
		{
			q.push(curNode->left_);
		}

		if (curNode->right_ == nullptr)
		{
			curNode->right_ = newNode;
			return;
		}
		else
		{
			q.push(curNode->right_);
		}
	}
	return;
}

template<class T>
bool BTree<T>::empty() const
{
	return (count_ == 0);
}

template<class T>
int BTree<T>::size() const
{
	return count_;
}

template<class T>
void BTree<T>::traversal() const
{
	if (root_)
	{
		cout << "Preorder: ";
		_preOrder(root_);
		cout << "Inorder: ";
		_inOrder(root_);
		cout << "postorder: ";
		_postOrder(root_);
		cout << "\n";
	}
}

template<class T>
void BTree<T>::_preOrder(BNode<T>* root) const
{
	cout << root->data_ << " ";
	if (root->left_)
	{
		_preOrder(root->left_);
	}
	if (root->right_)
	{
		_preOrder(root->right_);
	}
}

template<class T>
void BTree<T>::_inOrder(BNode<T>* root) const
{
	if (root->left_)
	{
		_inOrder(root->left_);
	}
	cout << root->data_ << " ";
	if (root->right_)
	{
		_inOrder(root->right_);
	}
}

template<class T>
void BTree<T>::_postOrder(BNode<T>* root) const
{
	if (root->left_)
	{
		_postOrder(root);
	}
	if (root->right_)
	{
		_postOrder(root);
	}
	cout << root->data_ << " ";
}

template<class T>
void BTree<T>::DFS() const
{
	if (root_)
	{
		cout << "DFS: ";
		_dfs(root_);
		cout << "\n";
	}
	return;
}

template<class T>
void BTree<T>::_dfs(BNode<T>* root) const
{
	cout << root->data_ << " ";
	if (root->left_)
	{
		_dfs(root);
	}
	if (root->right_)
	{
		_dfs(root);
	}
}

template<class T>
void BTree<T>::BFS() const
{
	queue<BNode<T>*> q;
	
	if (!root_)
		return;
	
	cout << "BFS: ";
	q.push(root_);
	
	while (!q.empty())
	{
		BNode<T>* curNode = q.front();
		q.pop();
		cout << curNode->data_ << " ";
		if (curNode->left_)
		{
			q.push(curNode->left_);
		}
		if (curNode->right_)
		{
			q.push(curNode->right_);
		}
	}
	cout << "\n";
}

int mainBTree()
{

	return 0;
}