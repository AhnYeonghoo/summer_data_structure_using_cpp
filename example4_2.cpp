#include "circular_queue.hpp"

void main_example4_2()
{
	CircularQueue que;
	for (int i = 1; i < 10; i++)
		que.enqueue(i);
	
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
}