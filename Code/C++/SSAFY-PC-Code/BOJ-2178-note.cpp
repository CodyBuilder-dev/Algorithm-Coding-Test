//���� : �̷� Ž��
//���� : �̷θ� Ž���ϴ� ���� BFS�� �����϶�

/*���̵�� : �� �̷�Ž���� DFS�� �ƴ� BFS�� ���ؾ� �ϴ��� �� ������ �˾ƾ� ��*/

//������ : BFS�� return�� �� Distance�� �ƴ϶� Distance+1����
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
	//1. ���� ��ġ�� visited�� �ִ´�.
	visited[y][x] = true;
	//2. ���� ��ġ�� �۾��� �����Ѵ�.(distance�� ����,��� �������Ѿ� �� �� �����ؾ� ��)
	//flag ����� 4���� Ȯ���� ������ ���� ������ �� �ѹ� cnt++ (X)
	//���ʿ� cnt�� ++�������� cnt�� ���� ����ؼ� �ִ´�? (X)
	//�Ÿ� ť�� ���� ���� (O)

	queue<int> distanceQue;
	//3.���� ��ġ�� ť�� �ִ´�.
	queue<pair<int, int>> route;

	route.push(make_pair(y, x));
	distanceQue.push(Distance);

	do {
		y = route.front().first;
		x = route.front().second;
		Distance = distanceQue.front();
		route.pop();
		distanceQue.pop();
		//���� ��ġ �ֺ��� 4���� Ž���Ѵ�.
		for (int i = 0; i < 4; ++i){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)//4�� ����� �˻�
			{
				if (ny == N - 1 && nx == M - 1) //�������̸� �ٷ� ��ȯ
					return Distance+1;
				if (visited[ny][nx] == false && maze[ny][nx] == 1) 
				{
					//4. �湮���� ���� ��� �湮ó��
					visited[ny][nx] = true;
					//5. ť�� �ֱ�
					route.push(make_pair(ny, nx));
					distanceQue.push(Distance+1);
				}
			}
		}
	} while (!route.empty());
	return Distance + 1;//�� Distance�� �ƴ϶� Distance+1�ϱ�?
	//return Distance; <--����
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

	//���⼭���� �������� �ڵ� ����
	cout << BFS(0, 0, 1);
}