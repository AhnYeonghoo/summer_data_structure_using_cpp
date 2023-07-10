#include <iostream>

class HeapEmpty {};
class HeapFull {};

template<class T>
class Heap
{
private:
	T* heapData_;
	int n_;
	int maxSize_;

public:
	Heap(int maxSize = 100) 
		: n_(0), maxSize_(maxSize), heapData_(new T(maxSize_)) {}
	~Heap() { delete heapData_; }

	void push(const T& data);
	void pop();
	T& top() const;
	int size() const;
	bool empty() const;
	void print() const;
};

template<class T>
void Heap<T>::push(const T& data)
{
	try
	{
		if (size() == maxSize_) throw HeapFull();
		heapData_[n_] = data;
		int parent = (n_ - 1) / 2;
		int child = n_;
		
		while (parent >= 0 && heapData_[parent] < heapData_[child])
		{
			T temp = heapData_[parent];
			heapData_[parent] = heapData_[child];
			heapData_[child] = temp;

			child = parent;
			parent = (child - 1) / 2;
		}
		++n_;
	}
	catch (HeapFull e)
	{
		std::cout << "Heap is Full\n";
		exit(2);
	}
}

template<class T>
void Heap<T>::pop()
{
	try
	{
		if (empty()) throw HeapEmpty();

		heapData_[0] = heapData_[--n_];

		int parent = 0;
		int child = parent * 2 + 1;
		bool placed = false;
		
		while (!placed && child < n_)
		{
			if (child < n_ - 1 && heapData_[child] < heapData_[child + 1])
			{
				child += 1;
			}
			
			if (heapData_[parent] >= heapData_[child])
			{
				placed = true;
			}
			else
			{
				T temp = heapData_[parent];
				heapData_[parent] = heapData_[child];
				heapData_[child] = temp;
			}
			
			parent = child;
			child = parent * 2 + 1;
		}
	}
	catch (HeapEmpty e)
	{
		std::cout << "Heap is Empty\n";
		exit(2);
	}
}

template<class T>
T& Heap<T>::top() const
{
	try
	{
		if (empty()) throw HeapEmpty();
		return heapData_[0];
	}
	catch (HeapEmpty e)
	{
		std::cout << "Heap is Empty\n";
		exit(2);
	}
}

template<class T>
int Heap<T>::size() const
{
	return n_;
}

template<class T>
bool Heap<T>::empty() const
{
	return (n_ == 0);
}

template<class T>
void Heap<T>::print() const
{
	std::cout << "[ ";
	for (int i = 0; i < n_; i++)
	{
		std::cout << heapData_[i] << " ";
	}
	std::cout << "]\n";
}

int main()
{
	Heap<int> heap;
	
	heap.push(8); heap.print();
	heap.push(19); heap.print();
	heap.push(23); heap.print();
	heap.push(32); heap.print();
	heap.push(45); heap.print();
	heap.push(56); heap.print();
	heap.push(78); heap.print();

	heap.pop(); heap.print();
	heap.pop(); heap.print();
	heap.pop(); heap.print();
	return 0;
}