#include "location2d.hpp"
#include <queue>
using namespace std;
const int MAZE_SIZE2 = 6; // 미로 맵 크기 고정
char map2[MAZE_SIZE2][MAZE_SIZE2] =
{
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};



// (r,c)가 갈 수 있는 위치인지를 검사하는 함수
// (r,c)가 배열 안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구 'x'이어야 함
bool isValidLoc2(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE2 || c >= MAZE_SIZE2) return false;
	else return map2[r][c] == '0' || map2[r][c] == 'x';
}

void main_example4_7()
{
	queue<Location2D> queue;
	Location2D entry(1, 0);
	queue.push(entry);
	
	while (queue.empty() == false)
	{
		Location2D here = queue.front();
		queue.pop();
		int r = here.row;
		int c = here.col;
		printf(" (%d, %d) ", r, c);
		if (map2[r][c] == 'x')
		{
			printf(" 미로 탐색 성공\n ");
			return;
		}
		else
		{
			map2[r][c] = '.';
			if (isValidLoc2(r - 1, c)) queue.push(Location2D(r - 1, c));
			if (isValidLoc2(r + 1, c)) queue.push(Location2D(r + 1, c));
			if (isValidLoc2(r, c - 1)) queue.push(Location2D(r, c - 1));
			if (isValidLoc2(r, c + 1)) queue.push(Location2D(r, c + 1));
		}
	}
	printf("미로 탐색 실패\n");

}