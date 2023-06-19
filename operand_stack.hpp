#pragma once;
#include <cstdio>
#include <cstdlib>

const int MAX_STACK_SIZE = 100;

inline void error3(const char* str)
{
	printf("%s\n", str);
	exit(1);
}

class OperandStack
{
private:
	double m_data[MAX_STACK_SIZE];
	int m_top;
	
public:
	OperandStack() { m_top = -1; }
	bool isEmpty() { return m_top == -1; }
	bool isFull() { return m_top == MAX_STACK_SIZE - 1; }
	void push(const double& e)
	{
		if (isFull()) error3("스택 포화 에러");
		m_data[++m_top] = e;
	}
	double pop()
	{
		if (isEmpty()) error3("비어있습니다");
		return m_data[m_top--];
	}
};