#include "location2d.hpp"
#include <stack>
#include <cstdio>
using namespace std;

const int MAZE_SIZE = 6; // 미로 맵 크기 고정
char map[MAZE_SIZE][MAZE_SIZE] =
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
bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}
void main_example3_11()
{
	stack<Location2D> stack;
	Location2D entry(1, 0); // 입구 객체 == e
	stack.push(entry); // 스택에 입구 위치 삽입
	
	while (stack.empty() == false) // 스택이 비어있지 않은 동안
	{
		Location2D here = stack.top(); // 스택에 최상단 객체 복사
		stack.pop();
		
		int r = here.row;
		int c = here.col;
		printf(" (%d, %d) ", r, c);
		if (map[r][c] == 'x')
		{
			printf(" 미로 탐색 성공\n ");
			return;
		}
		else
		{
			map[r][c] = '.'; // 출구가 아니면 현재 위치를 지나옴 처리
			if (isValidLoc(r - 1, c)) stack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) stack.push(Location2D(r + 1, c));
			if (isValidLoc(r , c-1)) stack.push(Location2D(r , c-1));
			if (isValidLoc(r , c+1)) stack.push(Location2D(r , c+1));
		}


	}
	printf("미로 탐색 실패\n");

}