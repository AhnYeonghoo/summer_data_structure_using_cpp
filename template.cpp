#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector
{
	T* data_;
	int capacity_;
	int length_;
	
public:

	typedef T value_type;

	// constructor
	Vector(int n = 1)
		: data_(new T[n]), capacity_(n), length_(0) {}
	
	// �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
	void push_back(T s)
	{
		if (capacity_ <= length_)
		{
			T* temp = new T[capacity_ * 2];
			for (int i = 0; i < length_; i++)
			{
				temp[i] = data_[i];
			}

			delete[] data_;
			data_ = temp;
			capacity_ *= 2;
		}
		data_[length_] = s;
		length_++;
	}

	// ������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[](int i) { return data_[i]; }

	// x��° ��ġ�� ���Ҹ� �����Ѵ�
	void remove(int x)
	{
		for (int i = x + 1; i < length_; i++)
		{
			data_[i - 1] = data_[i];
		}
		length_--;
	}

	// ���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length_; }

	void swap(int i, int j)
	{
		T temp = data_[i];
		data_[i] = data_[j];
		data_[j] = temp;
	}
	
	~Vector()
	{
		if (data_) delete[] data_;
	}
};

template<>
class Vector<bool>
{
	unsigned int* data_;
	int capacity_;
	int length_;
	
public:
	typedef bool value_type;
	
	// ������
	Vector(int n = 1)
		: data_(new unsigned int[n / 32 + 1]), capacity_(n / 32 + 1), length_(0)
	{
		for (int i = 0; i < capacity_; i++)
		{
			data_[i] = 0;
		}
	}

	// �� �ڿ� ���Ҹ� �߰��Ѵ�.
	void push_back(bool s)
	{
		if (capacity_ * 32 <= length_)
		{
			unsigned int* temp = new unsigned int[capacity_ * 2];
			for (int i = 0; i < capacity_; i++)
			{
				temp[i] = data_[i];
			}

			for (int i = capacity_; i < 2 * capacity_; i++)
			{
				temp[i] = 0;
			}
			delete[] data_;
			data_ = temp;
			capacity_ *= 2;
		}

		if (s)
		{
			data_[length_ / 32] |= (1 << (length_ % 32));
		}
		length_++;
	}

	// ������ ��ġ�� ���ҿ� �����Ѵ�.
	bool operator[](int i) { return (data_[i / 32] & (1 << (i % 32))) != 0; }

	// x��° ��ġ�� ���Ҹ� �����Ѵ�
	void remove(int x)
	{
		for (int i = x + 1; i < length_; i++)
		{
			int prev = i - 1;
			int curr = i;
			
			if (data_[curr / 32] & (1 << (curr % 32)))
			{
				data_[prev / 32] |= (1 << (prev % 32));
			}
			else
			{
				unsigned int all_onew_except_prev = 0xFFFFFFFF;
				all_onew_except_prev ^= (1 << (prev % 32));
				data_[prev / 32] &= all_onew_except_prev;
			}
		}

		length_--;
	}
	
	// ���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length_; }
	~Vector()
	{
		if (data_)
			delete[] data_;
	}
};

template<typename T>
T max(T& a, T& b)
{
	return a > b ? a : b;
}

template<typename Cont>
void bubbleSort(Cont& cont)
{
	for (int i = 0; i < cont.size(); i++)
	{
		for (int j = i + 1; j < cont.size(); j++)
		{
			if (cont[i] > cont[j])
			{
				cont.swap(i, j);
			}
		}
	}
}

struct Comp1
{
	bool operator()(int a, int b) { return a > b; }
};

struct Comp2
{
	bool operator()(int a, int b) { return a < b; }
};

template<typename Cont, typename Comp>
void bubbleSort(Cont& cont, Comp& comp)
{
	for (int i = 0; i < cont.size(); i++)
	{
		for (int j = i + 1; j < cont.size(); j++)
		{
			if (!comp(cont[i], cont[j]))
			{
				cont.swap(i, j);
			}
		}
	}
}


template<typename T>
struct Compare
{
	bool operator()(const T& a, const T& b) const { return a < b; }
};

template<typename T, typename Comp = Compare<T>>
T Min(T a, T b)
{
	Comp comp;
	if (comp(a, b))
	{
		return a;
	}
	return b;
}
int mainTemplate()
{
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);

	std::cout << "--------int vector ----------" << std::endl;
	std::cout << "ù��° ���� : " << int_vec[0] << std::endl;
	std::cout << "�ι�° ���� : " << int_vec[1] << std::endl;
	
	Vector<std::string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");
	std::cout << "--------------std::string vector------------" << std::endl;
	std::cout << "ù��° ���� : " << str_vec[0] << std::endl;
	std::cout << "�ι�° ���� : " << str_vec[1] << std::endl;

	Vector<bool> bool_vec;
	bool_vec.push_back(true);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);

	std::cout << "-----------bool vector-----------" << std::endl;
	for (int i = 0; i < bool_vec.size(); i++)
	{
		std::cout << bool_vec[i];
	}
	std::cout << std::endl;

	Vector<int> vec;
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(8);
	vec.push_back(5);
	vec.push_back(3);


	cout << "--- ���� ���� ---" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << "���� ���� ---" << endl;
	bubbleSort(vec);
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	int a = 3, b = 5;
	cout << "Min: " << a << ", " << b << " :: " << Min(a, b) << endl;
	string s1 = "abc", s2 = "def";
	cout << "Min " << s1 << ", " << s2 << " :: " << Min(s1, s2) << endl;
	return 0;
}