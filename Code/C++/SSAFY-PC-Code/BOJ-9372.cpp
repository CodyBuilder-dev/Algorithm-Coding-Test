//���� : ������� ����
//���� : N������ ������ ��, ���� ���� ������ ������ �����ϴ� ��Ʈ ���ϱ�

/*���̵�� : �׷����� ��尣 ������°� �־��� ��, �̷κ��� ��� ��Ʈ�湮 ���� �ּ� �湮��
�ּ������� ���ϴ� ���̹Ƿ� BFS �����
1. ������� �׸���
2. BFS�� ���ϱ�
3. 
*/
/*���� :
1.�������� 1,2,3...N�ӿ� ����
*/
/*������ : 
1. �׷����� BFS�� ������ ���� ���� visited�� 2�������� ���� �ʿ� ���� 1�������� ���
2. �̰� DFS�� ���ϴ� ���� ����?? ���� �ʿ�
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int T;
int N, M;
bool **graph;
bool *visited;


int BFS(int y)
{
	visited[y] = true;
	int time = 0;
	queue<int> route;
	queue<int> timeQue;
	route.push(y);
	timeQue.push(time);

	while (!route.empty()) {
		y = route.front();
		time = timeQue.front();

		route.pop();
		timeQue.pop();

		for(int i =0;i<N;++i)
			if(visited[i] == false && graph[y][i] == true){
				visited[i] = true;
				route.push(i);
				timeQue.push(time + 1);
			}
	}
	return time;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i){
		cin >> N >> M;

		graph = new bool*[N];
		visited = new bool[N];

		for (int j = 0; j < N; ++j){
			graph[j] = new bool[N];
		}

		for (int j = 0; j < M; ++j) {
			int start, end;
			cin >> start >> end;
			graph[start-1][end-1] = true;
			graph[end-1][start-1] = true;
		}
		int minimum=10000;
		for(int k = 0 ; k<N;++k)
			minimum = min(minimum,BFS(k));
		cout << minimum << '\n';
	}
	return 0;
}