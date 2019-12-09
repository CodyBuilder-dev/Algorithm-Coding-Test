//���� : N-Queen
//���� : N-Queen�� ��Ʈ��ŷ�� �̿��ؼ� Ǭ��.
//���� : ü���� ũ��� NxN, ���� N��

/*���̵�� : DFS�̿� ����Ž�� ����
1. 1��° ���� ����, ���μ��δ밢�� ��� visited << ���� ���� ����
2. 2��° ���� ����, 
3. 3��° ���� ����, ...
4. N��° ���� �������� ������ �ٽ� ó������ ���ư�
*/

/*������ :
1. 2�����迭 ���ڷ� �����ϴ°� ������ �� �ȵǸ� 1�����迭�� �ִ¹� ������ ��
2. 2�����迭�� dx dy������ �ƴ϶� �ٸ� ������� Ž���ϴ¹� ������ ��
*/

#include <iostream>

using namespace std;

int N;

int cnt;

void dfs(int y, int x, int queen, bool** chessboard)
{
	for (int i = 0; i < N; ++i)
	{
		chessboard[y][i] = true;
		chessboard[i][x] = true;
		if(y+i>=0 && y+i <N && x+i >=0 && x+i<N) chessboard[y+i][x+i] = true;
		if (y - i >= 0 && y - i < N && x + i >= 0 && x + i < N) chessboard[y - i][x + i] = true;
		if (y + i >= 0 && y + i < N && x - i >= 0 && x - i < N) chessboard[y + i][x - i] = true;
		if (y - i >= 0 && y - i < N && x - i >= 0 && x - i < N) chessboard[y - i][x - i] = true;
	}

	if (queen == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		int ny = y + 1; int nx = i;
		if (ny < N && nx < N && chessboard[y][nx] == false) {
			dfs(ny, nx, queen + 1, chessboard);
		}
	}

}

int main()
{
	cin >> N;

	bool **board;

	board = new bool*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new bool[N]();

	for (int i = 0; i < N; ++i)
	{
		dfs(0, i, 0, board); //0�� 0������ 0�� N������ ����
	}
	cout << cnt;
	return 0;

}