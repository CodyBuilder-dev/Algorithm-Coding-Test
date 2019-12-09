//제목 : 겉넓이 구하기
//목적 : 주어진 입체도형의 겉넓이를 구하여라
//조건 : 밑면의 넓이는 최대 100x100, 한 층의 높이는 최대 100

/*아이디어 : 
for문 돌림
왼쪽 위부터, 4방향으로 자기 위치랑 주변 놈들 위치 비교
자기위치 > 주변위치면 그 차이만큼 겉넓이
자기위치 =< 주변위치면 그쪽은 겉넓이 없음
*/

#include <iostream>

using namespace std;

int board[100][100];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int N, M;
int sum;

void check_face(int y,int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny >= N || ny < 0 || nx >= M || nx < 0)
			sum += board[y][x];
		else if(board[y][x] > board[ny][nx])
			sum +=  board[y][x] - board[ny][nx];
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			check_face(i, j);

	sum += 2 * N * M;
	cout << sum;
}