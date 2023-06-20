#include "location2d.hpp"
#include <deque>
using namespace std;

const int MAZE_SIZE3 = 6; // �̷� �� ũ�� ����
char map3[MAZE_SIZE3][MAZE_SIZE3] =
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
			printf(" �̷� Ž�� ����\n ");
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

	printf("�̷� Ž�� ����\n");
}