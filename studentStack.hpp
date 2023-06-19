#pragma once;
#include "student.hpp"

const int MAX_STACK_SIZE2 = 100; //������ �ִ� ũ�� ����

inline void error2(const char* str)
{
	printf("%s\n", str);
	exit(1);
}

class StudentStack
{
private:
	int m_top;
	Student m_data[MAX_STACK_SIZE2];
	
public:
	StudentStack() { m_top = -1; }
	bool isEmpty()
	{
		return m_top == -1;
	}
	
	bool isFull()
	{
		return m_top == MAX_STACK_SIZE2 - 1;
	}
	
	void push(const Student& e)
	{
		if (isFull()) error2("���� ��ȭ ����");
		m_data[++m_top] = e;
	}

	Student pop()
	{
		if (isEmpty()) error2("������ ����ֽ��ϴ�");
		return m_data[m_top--];
	}

	Student peek()
	{
		if (isEmpty()) error2("������ ����ֽ��ϴ�");
		return m_data[m_top];
	}
	
	void display()
	{
		printf("[��ü �л��� �� = %2d]\n", m_top + 1);
		for (int i = 0; i <= m_top; i++)
		{
			m_data[i].display();
		}
		printf("\n");
	}
};
