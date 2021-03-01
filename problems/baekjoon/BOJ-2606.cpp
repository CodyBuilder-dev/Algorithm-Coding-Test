//���� : ���̷���
//���� : ��Ʈ��ũ�� �׷����� �����Ǿ� �����Ƿ�, Ž���Ͽ� ������ ��ǻ�� �� ���ϱ�
/*
���̵�� : DFS�� BFS �����ϰ�, Ž���Ҷ����� cnt +1�ϸ� ��
1. DFS�� BFS�� - ��Ʈ��ũ ������ �𸣴� ���� ���� ���� - �Ѵ� �غ���
2. ���� ���°�, cnt +1�ϰų�, defected�߿� 1�ΰ� ���� ��
*/

#include <iostream>
#include <queue>

using namespace std;

//��������
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