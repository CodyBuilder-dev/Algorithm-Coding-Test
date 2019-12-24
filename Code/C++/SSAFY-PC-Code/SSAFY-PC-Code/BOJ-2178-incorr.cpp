//제목 : 미로 탐색
//목적 : 미로를 탐색하는 것을 BFS로 구현하라
/*조건 
1.가로 세로가 다름.  NxM. 2x2-100x100. 길은 1, 벽은 0
2. 출발점과 도착점이 주어지고 포함됨.
*/
/* 아이디어 :
1. BFS로 구하라 했으니 구해봄.
BFS에서 각 정점에 도달했을 경우 그 까지 거리는 최소경로임
2. 근데 그 거리를 어떻게 재는가...
2. 도착점으로 가는 경로는 여러개가 있을 수 있음을 이해. 즉 min변수를 만들어야 함
3. 도착점으로 갔다가 다른데로 튀어나가지 않도록 if문 추가해야 할 듯
4. 한칸씩 이동하므로 dx, dy사용 가능
*/

/*구현
1. 미로는 2차원배열에 해도 됨
2. 도착점의 좌표 (x,y)는 배열에서는 사실 (x-1,y-1)임에 주의
*/

/*
느낀점 : x좌표 y좌표를 꼭 queue를 2개 써야되나?
*/
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int **maze;
int **visited;
queue<int> route_x,route_y; 

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int cnt = 0;
int cnt_min = 0;
//BFS는 재귀로 짤 필요...는 없음.재귀로 짜면 꼬임
void BFS(int y, int x)
{

	//정지조건 : 1.미로 값이 0일때, 2. 값은 1인데 방문했을때
	//3. 미로 밖에 나갈때
	//4.도착점 도착했을때

	visited[y][x] = 1;
	cnt++;

	 //순서 잘 잡아야함
	//1. 주변 것들 넣기
	//2. 새로운거 하나 pop하기
	//3. 새로운거 주변 것들 넣기
	for (int i = 0; i < 4; ++i)
	{
		if (y + dy[i] < 0 || x + dx[i] < 0 || y + dy[i] >= N || x + dx[i] >= N)
			continue;
		else if (maze[y + dy[i]][x + dx[i]] == 1 &&
			visited[y + dy[i]][x + dx[i]] != 1) {
			route_x.push(x + dx[i]);
			route_y.push(y + dy[i]);
		}
	}

	int next_x, next_y;
	next_x = route_x.front();
	next_y = route_y.front();
	route_x.pop(); route_y.pop();
	
	while (!route_x.empty() || !route_y.empty())
	{
		for (int i = 0; i < 4; ++i)
		{
			if (next_y + dy[i] < 0 || next_x + dx[i] < 0 || next_y + dy[i] >= N || next_x + dx[i] >= N)
				continue;
			else if (maze[y + dy[i]][x + dx[i]] == 1 &&
				visited[y + dy[i]][x + dx[i]] != 1) {
				route_x.push(x + dx[i]);
				route_y.push(y + dy[i]);
			}
		}
		visited[next_y][next_x] = 1;
		next_x = route_x.front(); next_y = route_y.front();
		route_x.pop(); route_y.pop();

	}

}
int main()
{
	scanf("%d %d", &N, &M);
	
	maze = new int*[N];
	for (int i = 0; i < N; ++i)
		maze[i] = new int[M]();
	
	visited = new int*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new int[M]();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			printf("%d", maze[i][j]);
		printf("\n");
	}
	*/
	//여기부터 BFS 구현
	BFS(0, 0);
	cout << "bug_end";
	cout << cnt_min;
	return 0;
}