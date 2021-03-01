//���� : ���� ū ���簢��
//���� : N*M�迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϱ�
/*���� : �ִ� 1000x1000. �� �ѹ��� �� ���µ� 100��
�ѹ����� �� ���鼭, �ִ� 100���� �� ã�ƾ� ��
�� �ð����⵵ = 100��*100�� = 1��
*/
/*���̵�� : �ð����⵵�� DFS�� �Ұ���
-> 2�����迭���� DP�� ����� �� �ƴ°�?
1. ������ �Ʒ��� �������鼭 0 ���������� üũ
2. 0�� ������, ���� ������ ���簢���� �ִ� ũ��� �װŸ� �� �������� ���� �˼�����
3. �κ� �簢���� ���� �ִ�簢�� ã�� �Լ� ����
---------------------
0�� ���� ���� ��, ���� ������ Ž��
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> LU,RD,RU,LD;

int N, M;
bool board[1000][1000];

int find_nemo(pair<int,int>start,pair<int,int>RD)
{
	//���� ������ ����
	//0���������� ����������. 0������ �Ʒ���
	//�ݺ�
	//���������� ������ ����,���� ���̿��� ª���� ����
	int right=987654, down=987654;
	int i = 0, j = 0;
	while (start.first <= RD.first && start.second <= RD.second)
	{
		if (board[start.first + i][start.second + j] == false) {
			if (j == 0) {//�� ���� ���
				down = i-1;
				break;
			}
			right = min(right, j);
			j = 0;
			i++;
		}
		j++;
	}
	
	return right * down;
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &board[i][j]);
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << board[i][j];
		cout << '\n';
	}*/

	int y = 0, x = 0;
	while (y != N - 1 || x != M - 1) {

	}
			
}

