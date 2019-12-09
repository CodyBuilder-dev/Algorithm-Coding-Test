//���� : ���� �ִ� ���
//���� : '���� �ִ� ���'�� ã��
//���� : ������ ������ �ִ� 500��, ���δ� �ִ� 1����

/*���̵�� : '���� �ִ� ���'�� ����
���� �ִ� ��� = �ִܰ�ο� ���Ե� ��� ������ �� ����, �������� �ִܰ��
1. �׳� �ִܰ���� ���� ���ϱ�
2. �ִܰ�� ���� �� ����
3. �����ֵ�� �ִܰ�� ���ϱ�
*/

#include <iostream>
#include <vector>

#define INF 987654

using namespace std;

int N, M;

int graph[500][500];
int dist[500];

int route[500];

bool isShortest[500];

void dijkstra(int start, int end)
{
	/*�帧 ����
	1. dist�� �ʱ�ȭ(������ ����)
	2. �� ���ð�, ���� ª�� ���� ����
	3. ���õ� ������ �̿����� Ȯ��
	4. dist ����
	5. (��δ� ���� �߰��ϳ�?)
	*/

	//dist �ʱ�ȭ
	for (int i = 0; i < N; ++i) {
		if (i == start) dist[i] = 0;
		dist[i] = INF;
	}

	bool visited[500] = { 0, };
	
	while (!visited[end]) { //end�� üũ�Ǳ� ������ ��. üũ�Ǹ� Ż��
		//�� ���ð�, ���� ª�� ���� ����
		int min = INF, minidx;
		int order = 0;

		for (int i = 0; i < N; ++i)
		{
			if (dist[i] < min && !visited[i]) {
				min = dist[i];
				minidx = i;
			}
		}//���� ���� ª�� ���� ����

		//���� ª�� ������ �̿� ���� Ȯ��
		for (int i = 0; i < N; ++i)
		{
			if (graph[minidx][i] != 0) //������ �ֵ鸸
				if (dist[i] > dist[minidx] + graph[minidx][i]) //����� dist�� �ִܰŸ� �������� �Ÿ��� ��
					dist[i] = dist[minidx] + graph[minidx][i];
		}

		route.push_back(minidx);
		visited[minidx] = true;
		order++;
	}
}

int main()
{
	while (true)
	{
		cin >> N >> M; 
		if (N == 0 && M == 0) break;
		
		int start, end;
		cin >> start >> end;

		//������� ����
		for (int i = 0; i < M; ++i)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			graph[u][v] = cost;
		}
	}

	return 0;
}