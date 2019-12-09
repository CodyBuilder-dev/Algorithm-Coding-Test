//���� : �÷��̵�
//���� : �� ���÷κ��� �ٸ� ���÷� �ּҺ������ �̵��ϴ� �� ã��
//���� : ���ô� 100��, ������ 10����, 

/*���̵�� :
1. ����ġ�� �ִ� ������ ���ϱ�
2. �����Ŀ� BFS�Ἥ Ž���ϱ�
3. �����ϴ� ���õ��� ����� ����迭�� �ֱ�
*/

/*���� :
1.Queue�� Vector�� ������?!(X)
2.�÷��̵�-�ͼ� �˰����� ����
*/

/*������ :
1.���� �ڵ带 ������ ����, �� ���� �ڵ�� ������ �浹 ���� �����Ұ�
2.�÷��̵�ͼ� �˰����� ������ �����Ű�����?
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int costArray[100][100];

void Floyd_Warshall() {
	for (int m = 0; m < N; m++)
		for (int s = 0; s < N; s++)
			for (int e = 0; e < N; e++)
				costArray[s][e] = costArray[s][e] > costArray[s][m] + costArray[m][e] ? costArray[s][m] + costArray[m][e] : costArray[s][e];
}

int main()
{
	cin >> N >> M;

	//������� �ּҷ� �ޱ�
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if(costArray[start - 1][end - 1] == 0)
			costArray[start - 1][end - 1] = cost;
		else 
			costArray[start - 1][end - 1] = min(costArray[start - 1][end - 1],cost);
	}

	/*
	//0�� �κ� ���� 987987987
	for(int i = 0;i<N;++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;
			else if (costArray[i][j] == 0) costArray[i][j] = 987987987;
		}
		*/
	//���⼭���� �ڵ� ����
	Floyd_Warshall();

	/*
	//987987987�� �κ� ���� 0
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;
			else if (costArray[i][j] == 987987987) costArray[i][j] = 0;
		}
	*/

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << costArray[i][j] << ' ';
		cout << '\n';
	}

}

