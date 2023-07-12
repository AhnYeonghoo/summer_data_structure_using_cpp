#include <iostream>

class Resource
{
	int* data;
	
public:
	Resource()
	{
		data = new int[100];
		std::cout << "���ҽ� ŉ��\n";
	}
	~Resource()
	{
		std::cout << "�Ҹ��� ȣ��\n";
		delete[] data;
	}

	void doSomething()
	{
		std::cout << "Do Something!\n";
	}
};

class Foo
{
private:
	int a, b;
	
public:
	Foo(int a, int b) : a(a), b(b)
	{
		std::cout << "������\n";
	}

	void print()
	{
		std::cout << "a: " << a << ", b: " << b << "\n";
	}

	~Foo()
	{
		std::cout << "Destructor\n";
	}
};

void f()
{
	std::unique_ptr<Resource> pRsc(new Resource());
	std::cout << "pRsc: ";
	pRsc->doSomething();
	
	std::unique_ptr<Resource> pRsc2 = std::move(pRsc);
	std::cout << "pRsc2: ";
	pRsc2->doSomething();
}

int main()
{
	f();
	auto ptr = std::make_unique<Foo>(3, 3);

	return 0;
}