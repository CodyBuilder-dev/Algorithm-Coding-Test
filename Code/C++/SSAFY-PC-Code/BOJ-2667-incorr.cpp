//���� : ������ȣ ���̱�
//���� : 2���� �迭�� ��ȸ�� �� BFS/DFS�� �� �� �ִ°�
/*���̵��
1.������ ������ �׷����μ� �ľ�
2. ������ �̵� ������ 4�����̹Ƿ� ��Ÿ��ȸ? �迭�� ����Ž���ϴ°� �ƴϹǷ� ��
3. �̰Ŵ� 4������ ��� ������ �ϹǷ� BFS�� �´µ�
*/

/*����
1. �迭�� 1�� �ִ´�
2. �迭 ���ۺκп��� ������, �ִ� 625�� for�� ������.
3. visited�� 2�����迭�� ����, visited�� �˻��Ѵ�.
*/

/* �ڵ� - BFS

*/
/*������
*/
#include <iostream>
#include <queue>

using namespace std;
//��������
int N;
int **graph;
int **visited;

queue<int> x_que;
queue<int> y_que;

//��Ÿ
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int apt_cnt = 0;
int danji_idx = 0;
int danji_cnt[63];


void BFS(int node_x,int node_y)
{
	if (visited[node_x][node_y] == 1) {
		x_que.pop();
		y_que.pop();
		return;
	}

	visited[node_x][node_y] = 1;
	apt_cnt++;


	int new_x;
	int new_y;

	for (int i = 0; i < 4; ++i) {
			
		if (node_x == 0 && dx[i] == -1) continue;
		else new_x = node_x + dx[i];
		
		if (node_y == 0 && dy[i] == -1) continue;
		else new_y = node_y + dy[i];
		
		cout << new_x << '\n';
		cout << new_y << '\n';

		if (graph[new_x][new_y] == 1) {
			x_que.push(new_x);
			y_que.push(new_y);


		}
	}
	
	while (!x_que.empty() && !y_que.empty())
		BFS(x_que.front(), y_que.front());

	if (x_que.empty() && y_que.empty()) {
		danji_cnt[danji_idx] = apt_cnt;
		apt_cnt = 0;
		danji_idx++;
	}
	
}

void graphcheck();

void visitcheck();

int main()
{
	scanf("%d",&N);
	graph = new int*[N];
	for (int i = 0; i < N; ++i) {
		graph[i] = new int[N]();
		for (int j = 0; j < N; ++j)
			scanf("%1d", &graph[i][j]);
	}

	visited = new int*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new int[N]();
	
	//cout << "bug1";������� �� ��
	//graphcheck();
	//visitcheck();

	//�迭 ó������ ��ȸ
	for (int i = 0; i < N; ++i)
		for (int j = 0; i < N; ++j)
			if (graph[i][j] == 1)
				BFS(i,j);
	cout << "bug2";
	
	for(int i = 0; i < danji_idx;++i)
		printf("%d",danji_cnt[i]);
	cout << "bug3";
	return 0;
}

void graphcheck() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cout << graph[i][j];
}

void visitcheck() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cout << visited[i][j];
}