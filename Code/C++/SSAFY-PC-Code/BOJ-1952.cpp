//제목 : 달팽이2
/*목적 : 
벽에 부딪힐 때 마다 꺾는 달팽이를 만들고,
결국 정지할떄까지 몇번 꺾는지 계산*/

/*아이디어 : 달팽이는 한 방향으로만 진행
1. 각 이동방향을 원소 4개 delta행렬로 만듬
2. 꺾일때마다 dir++
3. dir%4 값에 따라 delta행렬에서 방향을 선택
*/

//느낀점 : 탈출조건 변수 말고 좀 세련된 건 없나?
#include <iostream>

using namespace std;

int** board;

int M, N;
int dir=0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void move(int y, int x)
{
	board[y][x] = 1; //시작점 1로 마킹
	int checkfail=0;
	while (checkfail !=4) // 4가 되면 종료
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

	//여기서부터 움직임 함수 구현
	move(0, 0);
	cout << dir;
}