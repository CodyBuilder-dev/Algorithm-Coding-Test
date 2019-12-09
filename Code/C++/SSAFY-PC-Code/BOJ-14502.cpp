//제목 : 연구소
//목적 : 2차원배열에서 벽 3개를 세워 바이러스를 막았을 때 안전영역 최대
//조건 :가로세로가 3-8이므로 다 따져볼만 함
/*
아이디어 : 벽 3개이므로 재귀함수 짜거나 for문 돌릴만 함
1. 모든 벽 세우는 경우에 대해 브루트 포스 수행
2. 벽을 세운 이후 2로부터 DFS써서 2를 채워 나가기
*/

#include <iostream>

using namespace std;

int N, M;
int **lab;
int **visited;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int wall_cnt=0;

int safe_sum = 0;
int max = 0;

//재귀로 구현
void DFS(int y, int x)
{
	/*정지조건
	1.경계 밖으로 넘어갈 때
	2.벽일 때
	3.똑같은 2일 떄
	*/
	if (y < 0 || x < 0 || y == N || x == M) return;
	if (lab[y][x] != 0) return;
	if (visited[y][x] == 1) return;

	visited[y][x] = 1;
	lab[y][x] = 2;

	for (int i = 0; i < 4; ++i)
	{
		DFS(y + dy[i], x + dx[i]);
	}

}

void cal_safe()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (lab[i][j] == 0) safe_sum++;
	if (safe_sum > max) max = safe_sum;
	safe_sum = 0;
	return;
}

void build_wall()
{
	if (wall_cnt >= 3) {
		for (int ii = 0; ii < N; ++ii)
			for (int jj = 0; jj < N; ++jj)
				if (lab[ii][jj] == 2 && visited[ii][jj] != 1)
					DFS(ii, jj);
		cal_safe();
		return;
	}
		
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (lab[i][j] == 2 || lab[i][j] == 1) continue;
			else {
				lab[i][j] = 1;
				wall_cnt++;
				build_wall();
			}
		}
			
}


int main()
{
	cin >> N >> M;
		
	lab = new int*[N];
	for (int i = 0; i < N; ++i)
		lab[i] = new int[M];

	//랩 받아들이기
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> lab [i][j];

	build_wall();

	cout << max;


}