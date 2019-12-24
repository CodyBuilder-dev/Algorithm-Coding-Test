//제목 : DFS와 BFS
//목적 : DFS와 BFS를 구현하라
/*
느낀점 및 의문점
1. 전역변수로 visited 와 graph, que,stack를 썼는데 이게 맞겠지?
2. 만약 지역변수로 쓴다면, 함수에 인자로 넣어야 하는지 알아보기
*/
#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int *visited;
int **graph;
queue<int> bfs_que;

//DFS구현을 해야되는데, 어떻게 구현할까
//정점에 도달
//visited 확인
//제일 작은놈 향해 가기
void DFS(int node)
{
	if (visited[node] == 1)
		return;
	visited[node] = 1;
	cout << node << ' ';
	for (int i = 1; i < N + 1; ++i)
		if (graph[node][i] == 1) {
			DFS(i);
		}
}

//BFS구현을 해야하되는데, 어떻게 구현할까
//정점 도착
//visited확인. visited면 pop하고 리턴
//일단 push때려넣기
//동작 수행
//while (!empty)로 빌때까지 돌기
void BFS(int node)
{

	if (visited[node] == 1) {
		bfs_que.pop();
		return;
	}

	for (int i = 1; i < N + 1; ++i)
		if (graph[node][i] == 1) {
			bfs_que.push(i);
		}
	visited[node] = 1;
	cout << node<<' ';


	while(!bfs_que.empty())
			BFS(bfs_que.front());

}
int main()
{

	cin >> N >> M >> V;

	graph = new int*[N+1];
	for (int i = 0; i < N+1; ++i)
		graph[i] = new int[N+1]();
	
	visited = new int[N + 1]();


	for (int i = 1; i <= M; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	DFS(V);
	cout << '\n';
	
	visited = new int[N + 1]();

	BFS(V);
	


}