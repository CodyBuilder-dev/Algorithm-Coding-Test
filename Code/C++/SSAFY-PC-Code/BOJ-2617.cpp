//���� : ���� ã��
//���� : �߰��� �� �� ���� ������ ����

/* ���̵�� :
������ �������⿡ ���� ������
2���� �迭�� �׸���, ū�� ������ ���ϱ�
i ���� ������ -1, 1���� ũ�� 1, �𸣸� 0
1�� ������ -1�̶� �Ȱ����� �߰� �ƴұ�
1�� ������ -1���� ũ�� ��(��Ȯ����  1�� ������ (n-1)/2)
-1�� ������ 1���� ũ�� ��...
(�ſ� ��ư� ������)
*/

/* ���̵��2 :Ʈ���� ����� �� ���ε� ����
1. Ʈ���� ��� ���� ���̴°�?
2. ���ٺ����� ����Ǽ� Ž��
*/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int **graph;
	graph = new int*[N+1];
	for (int i = 0; i < N+1; ++i)
		graph[i] = new int[N+1]();

	int heavy, light;
	for (int i = 1; i <= M; ++i)
	{
		cin >> heavy >> light;
		graph[heavy][light] = 1;
		graph[light][heavy] = -1;
	}
	//�� �̰� ���� ����Ž���ΰ�
	//������� 1,-1�� ä�������鼭 ã�°��� ����
	//�׷��� ���� �߰��� ���� �ʴ� �͵� ���� ���ݾ�
	int *middle;
	middle = new int[N + 1];

	int cnt=0, sum_heavy,sum_light;
	for (int i = 0; i < N+1; ++i){
		sum_heavy= sum_light = 0;
		for (int j = 0; j < N + 1; ++j) {
			if (graph[i][j] == 1) sum_heavy++;
			else if (graph[i][j] == -1) sum_light++;
		}
		if (sum_heavy > (N-1)/2 || sum_light > (N-1)/2 ) cnt++;

	}
	cout << cnt;

}