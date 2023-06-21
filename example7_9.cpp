#include <cstdio>

const int WIDTH = 20;
const int HEIGHT = 9;

// 순환 호출 함수 (다중 순환의 예)
void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) return;
	
	if (img[y][x] == 9) // 처리가 안 된 전경 화소이면
	{
		img[y][x] = label;
		labelComponent(img, x - 1, y, label);
		labelComponent(img, x, y - 1, label);
		labelComponent(img, x + 1, y, label);
		labelComponent(img, x, y + 1, label);
	}
}

// 이진 영상의 영역 채색(blob coloring) 함수
void blobColoring(unsigned char img[HEIGHT][WIDTH])
{
	int label = 1;
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (img[y][x] == 9) labelComponent(img, x, y, label++);
		}
	}
}

// 이진 영상의 영역 채색(blob coloring) 함수
void printImage(unsigned char img[HEIGHT][WIDTH], char* msg)
{
	printf("%s\n", msg);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (img[y][x] == 0) printf(".");
			else printf("%-1d", img[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}