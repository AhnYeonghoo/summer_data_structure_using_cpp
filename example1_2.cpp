#include <cstdio>
#include <cstdlib>
#include <ctime>

void main_example1_2(void)
{
	clock_t start, finish;
	double duration;
	
	start = clock();
	
	// ����ð��� �����ϰ��� �ϴ� �ڵ� ...
	
	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f ���Դϴ�.\n", duration);

	
}