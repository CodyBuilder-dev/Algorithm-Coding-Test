//���� : ��Ƽ
//���� : ��Ƽ�� �����ϴ� �л��� �� ���� �� �ð��� �ɸ��� �л� ã��
//���� : ������ �ִ� 1000��, ���� �ִ� 1����,

/*���̵�� : ��� ��忡�� �� ������ ���� ��� ��
1. ������ 1000���̹Ƿ� �÷��̵�ͼ��� �� �׷�
2. ��� ������ �� ������ ���� �ִܰ��  ���ϱ�
3. �ݴ�� �� ������ ��� ������ ���� �ִܰ�� ���ϱ�
4. ���ؼ� ������ ����
*/

/*���̵�� 2 : �ƴϸ� �� �׳� ������ �÷��̵�� Ǯ��?
*/

#include <iostream>

#define INF 987987987

using namespace std;

int N, M, X;
int graph[1000][1000];

void inf()
{
	for(int i = 0 ; i<N;++i)
		for (int j = 0; j < N; ++j)
		{
			if (i != j) graph[i][j] = INF;
		}
}
void floyd()
{
	for (int m = 0; m < N; ++m)
		for (int s = 0; s < N; ++s)
			for (int e = 0; e < N; ++e)
				graph[s][e] = (graph[s][e] > graph[s][m] + graph[m][e]) ?
					graph[s][m] + graph[m][e] : graph[s][e];
}

int main()
{
	cin >> N >> M >> X;

	inf();

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start - 1][end - 1] = cost;

	}

	floyd();

	//���⼭���� �ִ�ð� ã��
	//? >> X >> ?�� ���°� ã���� ��
	int max = -123123123;
	for (int i = 0; i < N; ++i)
	{
		int dist = graph[i][X - 1] + graph[X - 1][i];
		max = (dist > max) ? dist : max;
	}

	cout << max;

	return 0;
}