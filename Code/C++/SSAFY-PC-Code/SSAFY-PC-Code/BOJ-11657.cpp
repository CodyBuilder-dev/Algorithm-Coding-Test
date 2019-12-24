//���� : Ÿ�Ӹӽ�
//���� : 1�� ���ÿ��� Ÿ�Ӹӽ��� Ÿ�� �ٸ� ���÷� �̵��ϴ� ���
/*���� : ���ô� �ִ� 500��, ���� �뼱�� �ִ� 6õ��, �ð����� �ִ� -1��~1��
�ð����⵵ : �÷��̵�ͼ� = 500^3 = 1��2500��(�ָ�?)
ũ�罺Į = 500*6000 = 3�鸸 (����)
�������⵵ = ��簣�� �� 1���̸� 1��*500 = 500��(����)
*/

/*���̵��2 : ����-���� ����
1.�⺻���� ����-���� ����
2.����Ŭ �߻��� ��ó
3. �������� ���� ��� ��ó
*/

#include <iostream>
#define INF 987654321

using namespace std;

int N, M;
int graph[500][500];
int dist[500];

void init_inf()
{
	for(int i=0 ; i<N;++i)
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			graph[i][j] = INF;
		}

}
void input()
{
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;

		if (graph[start - 1][end - 1] > cost) graph[start - 1][end - 1] = cost;
	}
}

void bellman(int start)
{
	//��߳�� ����
	//���� ����
	//�����Ÿ� ��
	for (int i = 0; i < N; ++i) {
		if (i == start) continue;
		dist[i] = INF; //�Ÿ� �ʱ�ȭ
	}

	//for (int i = 1; i < N; ++i)
	//	cout << dist[i] << '\n';

	for(int s = 0; s<N;++s)
		for (int e = 0; e < N; ++e) {
			if (s != e && graph[s][e] != INF) {
				if (dist[e] > dist[s] + graph[s][e]) dist[e] = dist[s] + graph[s][e];
			}
		}
}
int main()
{
	cin >> N >> M;
	init_inf();
	input();
	bellman(0);
	for (int i = 1; i<N;++i)
		cout << dist[i] << '\n';

}