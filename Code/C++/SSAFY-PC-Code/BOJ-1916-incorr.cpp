//���� : �ּҺ�� ���ϱ�
//���� : ���ÿ��� �ٸ� ���÷� �̵��ϴµ� ��� �ּ� ���
/*���� : ���ô� �ִ� 1000��, ����� �ִ� 10����,
--���� �뼱�� ������ ���� �� ����!!--
*/

/*���̵��1 : �÷��̵� �ͼ� �˰������� ������� �� ���ϱ�
*/

/*������ : ���ð� 10^3���̹Ƿ�
�÷��̵� �ͼ��� O(10^9)�� CPU���� ���� fail
*/

#include <iostream>

using namespace std;

int N, M;
int dist[1000][1000];

void inf()
{
	for (int i = 0; i<N;++i)
		for(int j = 0; j<N;++j)
			if(i!=j) dist[i][j] = 987987987;
}

void floyd()
{
	for (int m = 0; m < N; ++m)
		for (int s = 0; s < N; ++s)
			for (int e = 0; e < N; ++e)
				dist[s][e] = (dist[s][m] + dist[m][e] > dist[s][e]) ? dist[s][e] : dist[s][m] + dist[m][e];
}

int main()
{
	cin >> N >> M;

	inf();

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if(dist[start-1][end-1]>cost) dist[start - 1][end - 1] = cost;	
	}

	//dist �� ���� ����
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < N; ++j)
	//		cout << dist[i][j] << ' ';
	//	cout << '\n';
	//}


	floyd();

	int start, end;
	cin >> start >> end;

	cout << dist[start - 1][end - 1];

}