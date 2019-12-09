//NxN�迭�̸� 1,1���� N-1,N-1����
//Ư�� ���Ĺ� �߰��ϸ�, �ű⼭���� dx dy �������� �Ǵ�
//4���� �� ������ ũ�� +1
//�� ���� ���ʹ� �Զ� ������ ��� ����
//�ѱ����� �ȵǸ� �ٷ� Ż��
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;

int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
int dirLength[4];

bool check_dir(int y, int x, int dir, char chr, vector<string> board)
{
	int ny = y + dy[dir]; int nx = x + dx[dir];
	if (ny >= 0 && ny < N && nx >= 0 && nx < M)
		if (board[ny][nx] == chr)
			return true;
	return false;
}

void find_dfs(int y, int x, int dir, vector<string> board)
{
	if (dir != -1) { //���� ������ �������� ���
		int ny = y + dy[dir]; int nx = x + dx[dir];
		if (check_dir(y, x, dir, board[y][x], board)) {
			dirLength[dir]++;
			find_dfs(ny, nx, dir, board);
		}
	}
	else { //���� ������ �������� ���
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];
			if (check_dir(y, x, i, board[y][x], board)) {
				dirLength[i]++;
				find_dfs(ny, nx, i, board);
			}
		}
	}
}

int solution(vector<string> board) {
	N = board.size(); //��
	M = board[0].size(); //��
	int answer = 0;

	for (int i = 1; i < N-1; ++i){
		for (int j = 1; j < M - 1; ++j)
		{
			find_dfs(i, j, -1, board);
			sort(dirLength, dirLength + 4);
			if (dirLength[0] != 0 && dirLength[0] + 1 > answer)
				answer = dirLength[0] + 1;
			for (int k = 0; k < 4; ++k)
				dirLength[k] = 0;
		}
	}
	return answer;
}

/////////main

int main()
{
	vector<string> board = { "ABCBA", "DABAG", "EBABH", "FAJAI", "AKLMA" };
	int answer = solution(board);
	cout << answer;

}