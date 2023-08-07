#include <iostream>
#include <cstdlib>
#include <thread>
#include <typeinfo>
#include <atomic>

using namespace std;

atomic<bool> atom { false };

// function
void fnPrint()
{
	static int calling_count = 0;
	while (!atom.load(memory_order_relaxed));
	for (int i = 0; i < 10; i++)
	{
		cout << __FUNCTION__ << ":" << ++calling_count << endl;
	}
}

struct FOPrint
{
	int calling_count;
	void operator() ()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << typeid(*this).name() << "::" << __FUNCTION__ <<
				++calling_count << endl;
		}
		atom.store(true, memory_order_relaxed);
	}
	FOPrint() : calling_count{0} {}
};

int mainThread()
{
	thread th1{ fnPrint };
	thread th2{ FOPrint() };
	th1.join();
	th2.join();


	return 0;
}