#include "location2d.hpp"
#include <queue>
using namespace std;
const int MAZE_SIZE2 = 6; // �̷� �� ũ�� ����
char map2[MAZE_SIZE2][MAZE_SIZE2] =
{
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};



// (r,c)�� �� �� �ִ� ��ġ������ �˻��ϴ� �Լ�
// (r,c)�� �迭 �ȿ� �ְ�, ���� �� �� �ִ� ��ġ '0'�̰ų� �ⱸ 'x'�̾�� ��
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
			printf(" �̷� Ž�� ����\n ");
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
	printf("�̷� Ž�� ����\n");

}