#include <iostream>
using namespace std;

class QueueEmpty{};

// 노드를 만들어 연결리스트를 통해 큐를 구현
template<class T>
class Node
{
public:
	T data_;
	Node<T>* next_;
	
	Node() : next_(nullptr) {}
	Node(T data, Node<T>* next) : data_(data), next_(next) {}
};

template<class T>
class LinkedQueue
{
private:
	int n_;
	Node<T>* head_;
	Node<T>* tail_;

public:
	LinkedQueue() : n_(0), head_(nullptr), tail_(nullptr) {}
	~LinkedQueue();
	
	void push(const T& data);
	T& front() const;
	void pop();
	int size() const;
	bool empty() const;
	void print() const;
};

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	Node<T>* delNode = head_;
	while (head_ != nullptr)
	{
		head_ = head_->next_;
		delete delNode;
	}
}

template<class T>
void LinkedQueue<T>::push(const T& data)
{
	if (empty())
	{
		head_ = new Node<T>(data, nullptr);
		tail_ = head_;
	}
	else
	{
		tail_->next_ = new Node<T>(data, nullptr);
		tail_ = tail_->next_;
	}
	
	++n_;
}

template<class T>
T& LinkedQueue<T>::front() const
{
	try
	{
		if (empty()) throw QueueEmpty();
		return head_->data_;
	}
	catch (QueueEmpty e)
	{
		cout << "Queue is empty\n";
		exit(2);
	}
}

template<class T>
void LinkedQueue<T>::pop()
{
	try
	{
		if (empty()) throw QueueEmpty();
		
		Node<T>* delNode = head_;
		head_ = head_->next_;
		delete delNode;
		--n_;

		if (n_ == 0) tail_ = nullptr;
	}
	catch (QueueEmpty e)
	{
		cout << "Queue is empty\n";
		exit(2);
	}
}

template<class T>
int LinkedQueue<T>::size() const
{
	return n_;
}

template<class T>
bool LinkedQueue<T>::empty() const
{
	return (n_ == 0);
}

template<class T>
void LinkedQueue<T>::print() const
{
	Node<T>* walk = head_;
	cout << "Front [ ";
	while (walk != nullptr)
	{
		cout << walk->data_ << " ";
		walk = walk->next_;
	}
	cout << "] rear\n";
}

int mainLinkedQueue()
{
	return 0;
}