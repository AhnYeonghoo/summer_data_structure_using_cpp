#define _CRT_SECURE_NO_WARNINGS
#include "operand_stack.hpp"

double calcPostfixExpr(FILE* fp = stdin)
{
	char c;
	OperandStack st;
	
	while ((c = getc(fp)) != '\n')
	{
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c)
			{
			case '+': st.push(val1 + val2); break;
			case '-': st.push(val1 - val2); break;
			case '*': st.push(val1 * val2); break;
			case '/': st.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9')
		{
			ungetc(c, fp);
			double val;
			fscanf(fp, "%lf", &val);
			st.push(val);
		}
	}
	return (st.pop());
}

int main_example3_8()
{

	return 0;
}