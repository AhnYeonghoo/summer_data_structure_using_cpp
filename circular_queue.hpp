#pragma once;
#include <cstdio>
#include <cstdlib>
const int MAX_QUEUE_SIZE = 100;

inline void error4(const char* str)
{
	printf("%s\n", str);
	exit(1);
}

class CircularQueue
{
protected:
	int		m_front; // ���� ����
	int		m_rear; // ���� ����
	int		m_data[MAX_QUEUE_SIZE]; // ���
	
public:
	CircularQueue() { m_front = m_rear = 0; }
	bool isEmpty() { return m_front == m_rear; }
	bool isFull() { return (m_rear + 1) % MAX_QUEUE_SIZE == m_front; }

	void enqueue(int val)
	{
		if (isFull()) error4("ť�� ��ȭ �����Դϴ�\n");
		else
		{
			m_rear = (m_rear + 1) % MAX_QUEUE_SIZE;
			m_data[m_rear] = val;
		}
	}

	int dequeue()
	{
		if (isEmpty()) error4("ť�� ���� �����Դϴ�\n");
		else
		{
			m_front = (m_front + 1) % MAX_QUEUE_SIZE;
			return m_data[m_front];
		}
	}
	
	int peek()
	{
		if (isEmpty()) error4("ť�� ���� �����Դϴ�.\n");
		else
		{
			return m_data[(m_front + 1) % MAX_QUEUE_SIZE];
		}
	}

	void display()
	{
		printf("ť ����: ");
		int maxi = (m_front < m_rear) ? m_rear : m_rear + MAX_QUEUE_SIZE;
		for (int i = m_front + 1; i <= maxi; i++)
		{
			printf("[%2d] ", m_data[i % MAX_QUEUE_SIZE]);
		}
		printf("\n");
	}

};