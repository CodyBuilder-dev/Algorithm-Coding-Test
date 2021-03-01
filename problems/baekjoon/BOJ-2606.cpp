//제목 : 바이러스
//목적 : 네트워크는 그래프로 구현되어 있으므로, 탐색하여 감염된 컴퓨터 수 구하기
/*
아이디어 : DFS나 BFS 구현하고, 탐색할때마다 cnt +1하면 됨
1. DFS냐 BFS냐 - 네트워크 구조를 모르니 선뜻 선택 힘듬 - 둘다 해보기
2. 갯수 세는건, cnt +1하거나, defected중에 1인거 세면 됨
*/

#include <iostream>
#include <queue>

using namespace std;

//전역변수
int N, M;
int *defected;
int **graph;
queue<int> bfs_que;

void DFS(int node)
{
	if (defected[node] == 1)
		return;

	defected[node] = 1;
	for (int i = 1; i < N+1; ++i)
		if (graph[node][i] == 1) 
			DFS(i);
	
}
void BFS(int node)
{

}
int main()
{

	cin >> N >> M;

	defected = new int[N + 1]();
	graph = new int*[N + 1];
	for (int i = 0; i < N + 1; ++i)
		graph[i] = new int[N + 1]();

	for (int i = 1; i <= M; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(1);

	int cnt=0;
	for (int i = 1; i < N + 1; ++i)
		if (defected[i] == 1) {
			cnt++;
		}
	cout << cnt-1;
}