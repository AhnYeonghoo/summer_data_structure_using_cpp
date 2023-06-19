#define _CRT_SECURE_NO_WARNINGS
#include "ArrayStack.hpp"

// 객체의 우선순위 계산
inline int precedence(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1; // 우선순위 중간
	case '*': case '/': return 2; // 우선순위 높음
	}
	return -1;
}

// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
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