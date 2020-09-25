//���� : �̷� Ž��
//���� : �̷θ� Ž���ϴ� ���� BFS�� �����϶�
/*���� 
1.���� ���ΰ� �ٸ�.  NxM. 2x2-100x100. ���� 1, ���� 0
2. ������� �������� �־����� ���Ե�.
*/
/* ���̵�� :
1. BFS�� ���϶� ������ ���غ�.
BFS���� �� ������ �������� ��� �� ���� �Ÿ��� �ּҰ����
2. �ٵ� �� �Ÿ��� ��� ��°�...
2. ���������� ���� ��δ� �������� ���� �� ������ ����. �� min������ ������ ��
3. ���������� ���ٰ� �ٸ����� Ƣ����� �ʵ��� if�� �߰��ؾ� �� ��
4. ��ĭ�� �̵��ϹǷ� dx, dy��� ����
*/

/*����
1. �̷δ� 2�����迭�� �ص� ��
2. �������� ��ǥ (x,y)�� �迭������ ��� (x-1,y-1)�ӿ� ����
*/

/*
������ : x��ǥ y��ǥ�� �� queue�� 2�� ��ߵǳ�?
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
//BFS�� ��ͷ� © �ʿ�...�� ����.��ͷ� ¥�� ����
void BFS(int y, int x)
{

	//�������� : 1.�̷� ���� 0�϶�, 2. ���� 1�ε� �湮������
	//3. �̷� �ۿ� ������
	//4.������ ����������

	visited[y][x] = 1;
	cnt++;

	 //���� �� ��ƾ���
	//1. �ֺ� �͵� �ֱ�
	//2. ���ο�� �ϳ� pop�ϱ�
	//3. ���ο�� �ֺ� �͵� �ֱ�
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
	//������� BFS ����
	BFS(0, 0);
	cout << "bug_end";
	cout << cnt_min;
	return 0;
}