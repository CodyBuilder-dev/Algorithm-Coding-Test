//제목 : 미로 탐색
//목적 : 미로를 탐색하는 것을 BFS로 구현하라

/*아이디어 : 왜 미로탐색을 DFS가 아닌 BFS로 구해야 하는지 그 이유를 알아야 함*/

//느낀점 : BFS의 return이 왜 Distance가 아니라 Distance+1인지
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int **maze;
bool **visited;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};


int BFS(int y, int x,int Distance)
{
	//1. 현재 위치를 visited에 넣는다.
	visited[y][x] = true;
	//2. 현재 위치의 작업을 수행한다.(distance를 언제,어떻게 증가시켜야 할 지 결정해야 함)
	//flag 만들어 4방향 확인후 움직일 방향 있으면 딱 한번 cnt++ (X)
	//애초에 cnt를 ++하지말고 cnt를 직접 계산해서 넣는다? (X)
	//거리 큐를 만들어서 넣자 (O)

	queue<int> distanceQue;
	//3.현재 위치를 큐에 넣는다.
	queue<pair<int, int>> route;

	route.push(make_pair(y, x));
	distanceQue.push(Distance);

	do {
		y = route.front().first;
		x = route.front().second;
		Distance = distanceQue.front();
		route.pop();
		distanceQue.pop();
		//현재 위치 주변의 4점을 탐색한다.
		for (int i = 0; i < 4; ++i){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)//4점 보드안 검사
			{
				if (ny == N - 1 && nx == M - 1) //도착점이면 바로 반환
					return Distance+1;
				if (visited[ny][nx] == false && maze[ny][nx] == 1) 
				{
					//4. 방문하지 않은 경우 방문처리
					visited[ny][nx] = true;
					//5. 큐에 넣기
					route.push(make_pair(ny, nx));
					distanceQue.push(Distance+1);
				}
			}
		}
	} while (!route.empty());
	return Distance + 1;//왜 Distance가 아니라 Distance+1일까?
	//return Distance; <--에러
}

int main()
{
	scanf("%d %d", &N, &M);

	maze = new int*[N];
	for (int i = 0; i < N; ++i)
		maze[i] = new int[M]();

	visited = new bool*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new bool[M]();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &maze[i][j]);

	//여기서부터 본격적인 코딩 시작
	cout << BFS(0, 0, 1);
}