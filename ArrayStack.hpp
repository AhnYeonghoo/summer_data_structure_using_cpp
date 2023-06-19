#pragma once;
#include <cstdio>
#include <cstdlib>

// ���� ó�� �Լ�
inline void error(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20; // ������ �ִ� ũ�� ����

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
		if (isFull()) error("���� ��ȭ ����!");
		m_data[++m_top] = e;
	}
	
	int pop()
	{
		if (isEmpty()) error("������ ����ֽ��ϴ�.");
		return m_data[m_top--];
	}

	int peek()
	{
		if (isEmpty()) error("������ ����ֽ��ϴ�.");
		return m_data[m_top];
	}

	void display()
	{
		printf("[���� �׸��� �� = %2d ==> ", m_top + 1);
		for (int i = 0; i <= m_top; i++)
		{
			printf("<%2d>", m_data[i]);
		}
		printf("\n");
	}
	
};