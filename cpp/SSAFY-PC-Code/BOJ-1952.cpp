//���� : ������2
/*���� : 
���� �ε��� �� ���� ���� �����̸� �����,
�ᱹ �����ҋ����� ��� ������ ���*/

/*���̵�� : �����̴� �� �������θ� ����
1. �� �̵������� ���� 4�� delta��ķ� ����
2. ���϶����� dir++
3. dir%4 ���� ���� delta��Ŀ��� ������ ����
*/

//������ : Ż������ ���� ���� �� ���õ� �� ����?
#include <iostream>

using namespace std;

int** board;

int M, N;
int dir=0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void move(int y, int x)
{
	board[y][x] = 1; //������ 1�� ��ŷ
	int checkfail=0;
	while (checkfail !=4) // 4�� �Ǹ� ����
	{
		int ny = y + dy[dir%4];
		int nx = x + dx[dir%4];

		if (ny >= 0 && ny < M && nx >= 0 && nx < N
			&& board[ny][nx] == 0)
		{
			board[ny][nx] = 1;
			y = ny;
			x = nx;
			checkfail = 0;
		}
		else {
			dir++;
			checkfail++;
		}
	}
	if (checkfail == 4)
		dir -= 4;
}
int main()
{
	cin >> M >> N;
	board = new int* [M];
	for (int i = 0; i < M; ++i)
		board[i] = new int[N]();

	//���⼭���� ������ �Լ� ����
	move(0, 0);
	cout << dir;
}