//제목 : 로봇 청소기
//목적 : 주어진 메뉴얼대로 동작하는 로봇청소기 구현
/*조건 : 
방위 : 0북 1동 2남 3서.
벽은 1 빈칸은 0 청소된 곳은 2 등으로 선택 가능
*/

/*아이디어 : 시뮬레이션 + 완탐
0. 전형적인 보드 완탐이므로 보드는 2차원 배열, visited 생성
1.방향의 구현 = 현재 보고있는 방향에 따라 다음 '왼쪽'이 정해짐
(dx dy로 구현가능)
2. dx dy 에 따라 순차적으로 검사
3. 더 움직일 수 있으면 FS 재귀로 계속
4. 더 못움직이면 return;
*/

#include <iostream>

using namespace std;

int N, M;

int dx[] = { -1,0,1,0 }; //서북동남
int dy[] = { 0,-1,0,1 };
int nowDir;

int **board;

void DFS(int y, int x)
{
	/*강제 return조건 설정
	1. 도착한 곳이 밖으로 나가려고 할 떄
	2. 도착한 곳이 벽일때
	
	return조건 설정
	1. 4방향 다 치웠고 더 치울곳 없을 때
	2. 4방향 다 치웠는데 후진이 안될 때
	*/
	if (y < 0 || x < 0 || y == N || x == M) return;
	if (board[y][x] == 1) return;

	board[y][x] = 2; //일단 청소된 구간은 2로 표시하겠음

	//우선 for 돌려서 DFS부터 고고
	int nextDir;
	for (int i = 0; i < 4; ++i){
		if (nowDir == 0) nextDir = 3;
		else nextDir = nowDir - 1;

		if (board[y + dy[nextDir]][x + dx[nextDir]] != 0) nowDir = (nowDir+1)%4;
		else DFS(y + dy[nextDir],x + dx[nextDir]);
	}
	
	for (int i = 0; i < 4; ++i) {
		if (nowDir == 0) nextDir = 3;
		else nextDir = nowDir - 1;
		if (board[y + dy[nextDir]][x + dx[nextDir]] != 0) {

		}
	}
	switch (nowDir)
	{
	case 0: 
		if (board[y + dy[3]][x + dx[3]] == 2) nowDir
		
	case 1:
	case 2:
	case 3:
	}

	int openDir;
	for (int i = 0; i < 4; ++i)
	{
		if (board[y + dy[i]][x + dx[i]] != 1) openDir++;
	}
	if (openDir == 0)
	{
		switch (nowDir)
		{
		case 0: 
			if (board[y + dy[3]][x + dx[3]] == 1) break;
			else DFS(y + dy[0], x + dx[0]);
		case 1:
			if (board[y + dy[0]][x + dx[0]] == 1) break;
			else DFS(y + dy[1], x + dx[1]);
		case 2:
			if (board[y + dy[1]][x + dx[1]] == 1) break;
			else DFS(y + dy[2], x + dx[2]);
		case 3:
			if (board[y + dy[2]][x + dx[2]] == 1) break; //동작 정지
			else DFS(y + dy[3], x + dx[3]);
		}
	}

	

}
int main()
{
	
}