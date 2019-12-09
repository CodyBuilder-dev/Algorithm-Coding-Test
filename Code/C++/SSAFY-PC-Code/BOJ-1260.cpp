//���� : DFS�� BFS
//���� : DFS�� BFS�� �����϶�
/*
������ �� �ǹ���
1. ���������� visited �� graph, que,stack�� ��µ� �̰� �°���?
2. ���� ���������� ���ٸ�, �Լ��� ���ڷ� �־�� �ϴ��� �˾ƺ���
*/
#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int *visited;
int **graph;
queue<int> bfs_que;

//DFS������ �ؾߵǴµ�, ��� �����ұ�
//������ ����
//visited Ȯ��
//���� ������ ���� ����
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

//BFS������ �ؾ��ϵǴµ�, ��� �����ұ�
//���� ����
//visitedȮ��. visited�� pop�ϰ� ����
//�ϴ� push�����ֱ�
//���� ����
//while (!empty)�� �������� ����
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