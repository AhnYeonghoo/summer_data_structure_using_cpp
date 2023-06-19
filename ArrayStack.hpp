#pragma once;
#include <cstdio>
#include <cstdlib>

// 에러 처리 함수
inline void error(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20; // 스택의 최대 크기 설정

class ArrayStack
{
private:
	int m_top;
	int m_data[MAX_STACK_SIZE];

public:
	ArrayStack() { m_top = -1; }
	~ArrayStack() {}
	
	bool isEmpty()
	{
		return m_top == -1;
	}
	
	bool isFull()
	{
		return m_top == MAX_STACK_SIZE - 1;
	}

	void push(int e)
	{
		if (isFull()) error("스택 포화 에러!");
		m_data[++m_top] = e;
	}
	
	int pop()
	{
		if (isEmpty()) error("스택이 비어있습니다.");
		return m_data[m_top--];
	}

	int peek()
	{
		if (isEmpty()) error("스택이 비어있습니다.");
		return m_data[m_top];
	}

	void display()
	{
		printf("[스택 항목의 수 = %2d ==> ", m_top + 1);
		for (int i = 0; i <= m_top; i++)
		{
			printf("<%2d>", m_data[i]);
		}
		printf("\n");
	}
	
};