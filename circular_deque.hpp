#include "circular_queue.hpp"

class CircularDeque : public CircularQueue
{
public:
	CircularDeque() {}
	void addRear(int val) { enqueue(val); }
	int deleteFront() { return dequeue(); }
	int getFront() { return peek(); }
	void addFront(int val)
	{
		if (isFull()) error4("덱이 포화 상태입니다.\n");
		else
		{
			m_data[m_front] = val;
			m_front = (m_front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	
	int deleteRear()
	{
		if (isEmpty())
			error4("덱이 공백 상태입니다\n");
		else
		{
			int ret = m_data[m_rear];
			m_rear = (m_rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return ret;
		}
	}

	int getRear()
	{
		if (isEmpty()) error4("덱이 공백 상태입니다.\n");
		else
		{
			return m_data[m_rear];
		}
	}

	void display() 
	{
		printf("덱의 내용: ");
		int maxi = (m_front < m_rear) ? m_rear : m_rear + MAX_QUEUE_SIZE;
		for (int i = m_front +1; i <= maxi; i++)
			printf("[%2d] ", m_data[i % MAX_QUEUE_SIZE]);
		printf("\n");
	}
	
};