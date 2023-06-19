#define _CRT_SECURE_NO_WARNINGS
#include "ArrayStack.hpp"

bool checkMatching(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		error("Error: 파일 존재하지 않습니다.\n");
	}
	
	int n_line = 1; // 읽은 라인의 개수
	int n_char = 0; // 읽은 문자의 개수
	
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
	printf("[%s] 파일 검사결과:\n", filename);
	
	if (!stack.isEmpty())
	{
		printf("Error: 문제 발견! (라인수=%d, 문자수=%d)\n\n", n_line, n_char);
	}
	else
	{
		printf("Ok : 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", n_line, n_char);
	}

	return stack.isEmpty();
}

int main_example3_6()
{
	checkMatching("ArrayStack.h");
	checkMatching("checkMatching.cpp");

	return 0;
}