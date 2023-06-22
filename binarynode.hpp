#pragma once;
#include <cstdio>

class BinaryNode
{
protected:
	int data; // 트리에 저장할 데이터
	BinaryNode* left; // 왼쪽 자식노드의 포인터
	BinaryNode* right; //오른쪽 자식노드의 포인터
	
public:
	BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
		: data(val), left(l), right(r) {}
	
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isLeaf() { return left == nullptr && right == nullptr; }

	BinaryNode* search(int key)
	{
		if (key == data) return this;
		else if (key < data && left != nullptr) return left->search(key);
		else if (key > data && right != nullptr) return right->search(key);
		else return nullptr;
	}


};