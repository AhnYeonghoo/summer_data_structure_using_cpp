#include <iostream>
using namespace std;

// Node ������ ���� SNode Ŭ������ �����Ѵ�
template<class T>
class SNode
{
public:
	T data_; // ���� ����Ǵ� ����
	SNode<T>* next_; // ���� ��带 ����Ű�� Link!
	
	SNode(const T data, SNode<T>* next) 
		: data_(data), next_(next) {}
};

// ���� ���Ḯ��Ʈ Ŭ������ �����Ѵ�
template<class T>
class SLinkedList
{
public:
	SNode<T>* head_; // head ������
	SNode<T>* tail_; // tail ������
	int count_; 
	
	SLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {}
	~SLinkedList();
	
	void insert(const T data, int index);
	
	void erase(int index);
	
	int search(const T data);
	
	bool isEmpty() const;
	
	T front() const;
};

template<typename T>
SLinkedList<T>::~SLinkedList()
{
	while (!isEmpty()) erase(0);
}

template<typename T>
void SLinkedList<T>::insert(const T data, int index)
{
	// �ùٸ� �ε������� �˻�
	if (index > count_ || index < 0)
	{
		cerr << "index ���� �ùٸ��� �ʽ��ϴ�!\n";
		return;
	}
	
	if (index == 0) // ���� �� �տ� �����Ѵٸ�
	{
		head_ = new SNode<T>(data, head_); 
		tail_ = head_;  // ��尡 �Ѱ��̹Ƿ� �� ���� ��尡 tail�� head�� ��
	}
	else
	{
		SNode<T>* preNode = head_; 
		for (int i = 0; i < index - 1; i++)
		{
			preNode = preNode->next_; // �ش��ϴ� �ε������� Ž���Ѵ�
		}
		
		preNode->next_ = new SNode<T>(data, preNode->next_);
		
		if (index == count_)
		{
			tail_ = preNode->next_;
		}
	}
	count_++;
}

template<typename T>
void SLinkedList<T>::erase(int index)
{
	if (index >= count_ || index < 0)
	{
		cerr << "index���� �ùٸ��� �ʽ��ϴ�\n";
		return;
	}
	
	SNode<T>* preNode = head_;
	
	if (index == 0)
	{
		head_ = head_->next_;
		delete preNode;
	}
	else
	{
		SNode<T>* delNode;
		
		for (int i = 0; i < index - 1; i++)
		{
			preNode = preNode->next_;
		}

		delNode = preNode->next_;
		preNode->next_ = preNode->next_->next_;
		delete delNode;

		if (index == count_ - 1)
			tail_ = preNode;
	}
	count_--;
}

template<typename T>
int SLinkedList<T>::search(const T data)
{
	SNode<T>* curNode = head_;
	
	for (int i = 0; i < count_; i++)
	{
		if (curNode->data_ == data)
		{
			return i;
		}
		curNode = curNode->next_;
	}
	return -1; // �� ã����
}

template<typename T>
bool SLinkedList<T>::isEmpty() const
{
	return (count_ == 0);
}

template<typename T>
T SLinkedList<T>::front() const
{
	if (isEmpty()) return -1;
	return head_->data_;
}

template<typename T>
ostream& operator<<(ostream& o, const SLinkedList<T>& list)
{
	SNode<T>* walNode = list.head_;
	o << "[ ";
	for (int i = 0; i < list.count_; i++)
	{
		o << walNode->data_;
		walNode = walNode->next_;
		if (i < list.count_ - 1)
			o << " -> ";
	}
	o << " ]\n";
	return o;
}


int main()
{
	SLinkedList<int> SList;
	SList.insert(10, 0), cout << SList;
	SList.insert(5, 1), cout << SList;
	SList.insert(3, 2), cout << SList;
	SList.insert(2, 3), cout << SList;
	SList.insert(1, 0), cout << SList;
	SList.insert(20, 5), cout << SList;
	SList.insert(6, 4), cout << SList;
	SList.insert(8, 5), cout << SList;
	SList.insert(7, 8), cout << SList;
	SList.erase(2), cout << SList;
	SList.erase(0), cout << SList;
	SList.erase(5), cout << SList;
	SList.insert(12, 4), cout << SList;
	SList.erase(1), cout << SList;
	return 0;
}