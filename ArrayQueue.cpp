#include <iostream>
using namespace std;

class QueueFull {};
class QueueEmpty {};

template<class T>
class ArrayQueue
{
private:
	int N_;
	int n_;
	int front_, rear_;
	T* data_;

public:
	ArrayQueue(int capacity = 100)
		: N_(capacity), n_(0), front_(0), rear_(0),
		  data_(new T[capacity]) {}
	~ArrayQueue();
	
	void push(const T& data);
	void pop();
	T& front() const;
	bool empty() const;
	int size() const;
	void print() const;
};

template<typename T>
ArrayQueue<T>::~ArrayQueue()
{
	delete data_;
}

template<typename T>
void ArrayQueue<T>::push(const T& data)
{
	try
	{
		if (size() == N_) throw QueueFull();

		data_[rear_] = data;
		rear_ = (rear_ + 1) % N_;
		++n_;
	}
	catch (QueueFull e)
	{
		cout << "Queue is Full\n";
		exit(2);
	}
}

template<typename T>
void ArrayQueue<T>::pop()
{
	try
	{
		if (empty()) throw QueueEmpty();
		front_ = (front_ + 1) % N_;
		--n_;
	}
	catch (QueueEmpty e)
	{
		cout << "Queue is Empty\n";
		exit(2);
	}
}

template<typename T>
T& ArrayQueue<T>::front() const
{
	try
	{
		if (empty()) throw QueueEmpty();
		return data_[front_];
	}
	catch (QueueEmpty e)
	{
		cout << "Queue is Empty\n";
		exit(2);
	}
}

template<typename T>
bool ArrayQueue<T>::empty() const
{
	return (n_ == 0);
}

template<typename T>
int ArrayQueue<T>::size() const
{
	return n_;
}

template<typename T>
void ArrayQueue<T>::print() const
{
	cout << "front [ ";
	for (int i = front_; i != rear_; i = (i + 1) % N_)
	{
		cout << data_[i] << " ";
	}
	cout << "] rear\n";
}

int mainArrayQueue()
{
	ArrayQueue<int> q;
	q.push(5), q.print();
	q.push(3), q.print();
	q.push(7), q.print();
	q.push(15), q.print();
	q.pop(), q.print();
	q.push(9), q.print();
	q.push(2), q.print();
	q.front(), q.print();
	q.pop(), q.print();
	q.pop(), q.print();
	return 0;

}