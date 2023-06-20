#define _CRT_SECURE_NO_WARNINGS
#include "ArrayStack.hpp"

// ��ü�� �켱���� ���
inline int precedence(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1; // �켱���� �߰�
	case '*': case '/': return 2; // �켱���� ����
	}
	return -1;
}

// ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� �Լ�
void infix2Postfix(FILE* fp = stdin)
{
	char c, op;
	double val;
	ArrayStack st;
	
	while ((c = getc(fp)) != '\n')
	{
		if ((c >= '0' && c <= '9'))
		{
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			printf("%4.1f", val);
		}
		else if (c = '(') st.push(c);
		else if (c == ')')
		{
			while (!st.isEmpty())
			{
				op = st.pop();
				if (op == '(') break;
				else printf("%c ", op);
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!st.isEmpty())
			{
				op = st.peek();
				if (precedence(c) <= precedence(op))
				{
					printf("%c ", op);
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}

	while (!st.isEmpty())
		printf("%c ", st.pop());
	printf("\n");
}

int main_example3_9()
{

	return 0;
}