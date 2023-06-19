#define _CRT_SECURE_NO_WARNINGS
#include "ArrayStack.hpp"

bool checkMatching(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		error("Error: ���� �������� �ʽ��ϴ�.\n");
	}
	
	int n_line = 1; // ���� ������ ����
	int n_char = 0; // ���� ������ ����
	
	ArrayStack stack;
	char ch = ' ';
	
	while ((ch == getc(fp)) != EOF)
	{
		if (ch == '\n') n_line++;
		n_char++;
		
		if (ch == '[' || ch == '(' || ch == '{')
		{
			stack.push(ch);
		}
		else if (ch == ']' || ch == ')' || ch == '}')
		{
			int prev = stack.pop();
			if ((ch == ']' && prev == '[')
				|| (ch == ')' && prev == '('
					|| (ch == '}' && prev == '{'))) break;
		}
	}

	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	
	if (!stack.isEmpty())
	{
		printf("Error: ���� �߰�! (���μ�=%d, ���ڼ�=%d)\n\n", n_line, n_char);
	}
	else
	{
		printf("Ok : ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", n_line, n_char);
	}

	return stack.isEmpty();
}

int main_example3_6()
{
	checkMatching("ArrayStack.h");
	checkMatching("checkMatching.cpp");

	return 0;
}