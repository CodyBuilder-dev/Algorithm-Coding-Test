//���� : �ּҺ�� ���ϱ�
//���� : ���ÿ��� �ٸ� ���÷� �̵��ϴµ� ��� �ּ� ���
/*���� : ���ô� �ִ� 1000��, ����� �ִ� 10����,
--���� �뼱�� ������ ���� �� ����!!--
*/

/*���̵��3 : ���ͽ�Ʈ�� �˰������� Ǯ��
*/

//���� : ó���̴� �׳� �迭 ��üŽ������ Ǯ��

#include <iostream>

using namespace std;

int currNode;
int nextNode;

int N, M;
int totalDist[1000][1000];
int currDist[1000];
bool* visited;

void dijkstra(int start)
{
	currNode = start;

}
int main()
{
	cin >> N >> M;

	visited = new bool[N];

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (totalDist[start - 1][end - 1] > cost) totalDist[start - 1][end - 1] = cost;
	}

	int start, end;
	cin >> start >> end;

	//���⼭���� �ڵ� ����
	
}
