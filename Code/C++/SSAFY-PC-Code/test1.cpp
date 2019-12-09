#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, K, L;
	int apl_x, apl_y;
	int X;
	char C;
	char dir = 1; //��1 ��2 ��3 ��4
	int time = 0;
	char **board;

	//NxN ������ �����
	cin >> N;
	board = new char*[N + 2];
	for (int i = 0; i < N + 2; ++i)
	{
		board[i] = new char[N + 2]();
		if (i == 0) memset(board[i], -1, N + 2);
		else if (i == N + 1) memset(board[i], -1, N + 2);
		else {
			board[i][0] = -1; board[i][N + 1] = -1;
		}
	}

	for (int i = 0; i < N + 2; ++i)
	{
		for (int j = 0; j < N + 2; ++j)
			cout << (int)board[i][j];
		cout << endl;
	}

	//��� ��ġ �ޱ�
	cin >> K;
	for (int i = 1; i <= K; ++i)
	{
		cin >> apl_x >> apl_y;
		board[apl_x][apl_y] = 1;
	}

	for (int i = 0; i < N + 2; ++i)
	{
		for (int j = 0; j < N + 2; ++j)
			cout << (int)board[i][j];
		cout << endl;
	}
}