//제목 : N-Queen
//목적 : N-Queen을 백트레킹을 이용해서 푼다.
//조건 : 체스판 크기는 NxN, 퀸은 N개

/*아이디어 : DFS이용 완전탐색 ㄱㄱ
1. 1번째 퀸을 놓고, 가로세로대각선 모두 visited << 쉽지 않음 ㄹㅇ
2. 2번째 퀸을 놓고, 
3. 3번째 퀸을 놓고, ...
4. N번째 퀸이 놓아지지 않으면 다시 처음으로 돌아감
*/

/*느낀점 :
1. 2차원배열 인자로 전달하는거 연습할 것 안되면 1차원배열로 넣는법 생각할 것
2. 2차원배열을 dx dy형식이 아니라 다른 방법으로 탐색하는법 생각할 것
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
		dfs(0, i, 0, board); //0행 0열부터 0행 N열까지 보기
	}
	cout << cnt;
	return 0;

}