#include <iostream>
using namespace std;

// Node 역할을 해줄 SNode 클래스를 정의한다
template<class T>
class SNode
{
public:
	T data_; // 값이 저장되는 변수
	SNode<T>* next_; // 다음 노드를 가리키는 Link!
	
	SNode(const T data, SNode<T>* next) 
		: data_(data), next_(next) {}
};

// 단일 연결리스트 클래스를 구현한다
template<class T>
class SLinkedList
{
public:
	SNode<T>* head_; // head 포인터
	SNode<T>* tail_; // tail 포인터
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
	// 올바른 인덱스인지 검사
	if (index > count_ || index < 0)
	{
		cerr << "index 값이 올바르지 않습니다!\n";
		return;
	}
	
	if (index == 0) // 만약 맨 앞에 삽입한다면
	{
		head_ = new SNode<T>(data, head_); 
		tail_ = head_;  // 노드가 한개이므로 한 개의 노드가 tail과 head가 됨
	}
	else
	{
		SNode<T>* preNode = head_; 
		for (int i = 0; i < index - 1; i++)
		{
			preNode = preNode->next_; // 해당하는 인덱스까지 탐색한다
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
		cerr << "index값이 올바르지 않습니다\n";
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
	return -1; // 못 찾으면
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