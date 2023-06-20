#pragma once;
#include <cstdio>
#include <cstdlib>
const int MAX_LIST_SIZE = 100;

inline void error5(const char* str)
{
	printf("%s\n", str);
	exit(1);
}

class ArrayList
{
private:
	int data[MAX_LIST_SIZE];
	int length;
	
public:
	ArrayList(void) { length = 0; }
	void insert(int pos, int e)
	{
		if (!isFull() && pos >= 0 && pos <= length)
		{
			for (int i = length; i > pos; i--)
			{
				data[i] = data[i - 1];
			}
			data[pos] = e;
			length++;
		}
		else error5("��ȭ���� ���� �Ǵ� ���� ��ġ ����");
	}

	void remove(int pos)
	{
		if (!isEmpty() && pos >= 0 && pos < length)
		{
			for (int i = pos + 1; i < length; i++)
			{
				data[i - 1] = data[i];
			}
			length--;
		}
		else error5("������� ���� �Ǵ� ���� ��ġ ����");
	}

	int getEntry(int pos) { return data[pos]; }
	bool isEmpty() { return length == 0; }
	bool isFull() { return length == MAX_LIST_SIZE; }

	bool find(int item)
	{
		for (int i = 0; i < length; i++)
		{
			if (data[i] == item) return true;
		}
		return false;
	}

	void replace(int pos, int e)
	{
		data[pos] = e;
	}

	int size() { return length; }
	
	void display()
	{
		printf("[�迭�� ������ ����Ʈ ��ü �׸� �� = %2d] : ", size());
		for (int i = 0; i < size(); i++)
			printf("[%2d] ", data[i]);
		printf("\n");
	}
	
	void clear() { length = 0; }
};