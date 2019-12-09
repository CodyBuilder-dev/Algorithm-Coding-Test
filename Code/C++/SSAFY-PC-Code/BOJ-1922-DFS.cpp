//���� : ��Ʈ��ũ ����
//���� : ��� ��ǻ�͸� �����ϴ� ��� �� ���� �ּҰ� �Ǵ� ���� �����϶�
//���� : ��ǻ�� �ִ� 1000��, ���� �� �ִ� 10����, ����� ���, 

/*���̵�� :
��� ��带 �� �����ϴ� �� = �ּ� ���д� Ʈ��
�ּ� ���д� Ʈ�� = BFS,DFS/ũ�罺Į(�ƴ°� �̰Ż�)/����
���⼭�� BFS���
*/

/*���� : ��� ������ ���������� �ؼ� ��� �����ϴ� ���д� Ʈ�� Ž�� ����
���д�Ʈ���� �ϼ��Ǹ� �� �Ÿ� üũ
�Ÿ��� �ּҰ��� ��
������!! �ּ� ���д� Ʈ���� ���� ��尡 ������ ���õǵ� �� �̤�
������ �����ϰ� ������ ���տ� ���� �� ������ ũ�Ⱑ 4���� �˻��ϴ°� �³�?
->�׷����� visited�� �������迭 1000�� �ƴ϶�, 1000x1000���� ������ ��
*/


#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int N, M;
int graph[1000][1000];
bool edgeVisited[1000][1000];
bool nodeVisited[1000];

set<int> nodeSet;
priority_queue<int,vector<int>,greater<int>> minDist;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if (graph[start - 1][end - 1] == 0 ) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
		}
		else if (graph[start - 1][end - 1] > cost) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
		}
	}
}
//DFS�� ���д� Ʈ�� ã��
void find_spanning(int start , bool edge[][1000],bool node[],int cnt, int sum) 
{
	if (cnt == N-1) { //���� n�� ������ ���
		minDist.push(sum);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (graph[start][i] != 0 && edge[start][i] == false) { //������ �Ǿ� �ְ� ���� ���� �ȵ�
			if (node[i] == false) { //��嵵 ���� �ȵ�

			}
			int newsum = sum + graph[start][i];
			bool newvisit[1000];
			memcpy(&newvisit[0], &visit[0], 1000);
			newvisit[i] = true;
			find_spanning(i, newvisit, cnt + 1, newsum);
		}
	}
}
//���д� Ʈ�� �� �ּҰ� ã��
void find_min()
{
	//��� ����� ���� �� �����鼭 ���д� Ʈ�� �����
	for (int i = 0; i < N; ++i) {//��� ������ ����������
		visited[i] = true;
		find_spanning(i, visited, 1, 0);
	}
	cout << minDist.top();
}

int main()
{
	input();
	//�׷��� �˻�
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << graph[i][j];
		cout << '\n';
	}*/
	find_min();


}

