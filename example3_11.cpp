#include "location2d.hpp"
#include <stack>
#include <cstdio>
using namespace std;

const int MAZE_SIZE = 6; // �̷� �� ũ�� ����
char map[MAZE_SIZE][MAZE_SIZE] =
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
bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}
void main_example3_11()
{
	stack<Location2D> stack;
	Location2D entry(1, 0); // �Ա� ��ü == e
	stack.push(entry); // ���ÿ� �Ա� ��ġ ����
	
	while (stack.empty() == false) // ������ ������� ���� ����
	{
		Location2D here = stack.top(); // ���ÿ� �ֻ�� ��ü ����
		stack.pop();
		
		int r = here.row;
		int c = here.col;
		printf(" (%d, %d) ", r, c);
		if (map[r][c] == 'x')
		{
			printf(" �̷� Ž�� ����\n ");
			return;
		}
		else
		{
			map[r][c] = '.'; // �ⱸ�� �ƴϸ� ���� ��ġ�� ������ ó��
			if (isValidLoc(r - 1, c)) stack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) stack.push(Location2D(r + 1, c));
			if (isValidLoc(r , c-1)) stack.push(Location2D(r , c-1));
			if (isValidLoc(r , c+1)) stack.push(Location2D(r , c+1));
		}


	}
	printf("�̷� Ž�� ����\n");

}