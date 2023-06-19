#include <cstdio>

/*
* 픽셀값 중 가장 큰 값을 찾아 반환하는 함수
*/
int findMaxPixel(int a[][5], int h, int w)
{
	int max_val = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (max_val < a[i][j])
			{
				max_val = a[i][j];
			}
		}
	}

	return max_val;
}

int main_example2_3()
{
	int img[4][5] = {
		{ 3, 24, 82, 12, 22},
		{34, 7, 12, 19 ,21},
		{99, 7, 65, 73, 58},
		{20, 7, 9, 48, 29},
					};
	
	int max_pixel = findMaxPixel(img, 4, 5);
	printf("영상의 최대 밝기 = %d\n", max_pixel);
	return 0;
}