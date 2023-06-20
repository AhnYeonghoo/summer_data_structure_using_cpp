#include "location2d.hpp"
#include <deque>
using namespace std;

const int MAZE_SIZE3 = 6; // 미로 맵 크기 고정
char map3[MAZE_SIZE3][MAZE_SIZE3] =
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
bool isValidLoc3(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE3 || c >= MAZE_SIZE3) return false;
	else return map3[r][c] == '0' || map3[r][c] == 'x';
}

void main_example4_8()
{
	deque<Location2D> deque;
	Location2D entry(1, 0);
	deque.push_front(entry);

	while (deque.empty() == false)
	{
		Location2D here = deque.front();
		deque.pop_front();
		int r = here.row;
		int c = here.col;
		printf(" (%d, %d) ", r, c);
		if (map3[r][c] == 'x')
		{
			printf(" 미로 탐색 성공\n ");
			return;
		}
		else
		{
			map3[r][c] = '.';
			if (isValidLoc3(r - 1, c)) deque.push_front(Location2D(r - 1, c));
			if (isValidLoc3(r + 1, c)) deque.push_front(Location2D(r + 1, c));
			if (isValidLoc3(r, c - 1)) deque.push_front(Location2D(r, c - 1));
			if (isValidLoc3(r, c + 1)) deque.push_front(Location2D(r, c + 1));
		}
	}

	printf("미로 탐색 실패\n");
}