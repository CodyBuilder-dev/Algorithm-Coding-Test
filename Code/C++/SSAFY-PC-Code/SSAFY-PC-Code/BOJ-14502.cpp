//���� : ������
//���� : 2�����迭���� �� 3���� ���� ���̷����� ������ �� �������� �ִ�
//���� :���μ��ΰ� 3-8�̹Ƿ� �� �������� ��
/*
���̵�� : �� 3���̹Ƿ� ����Լ� ¥�ų� for�� ������ ��
1. ��� �� ����� ��쿡 ���� ���Ʈ ���� ����
2. ���� ���� ���� 2�κ��� DFS�Ἥ 2�� ä�� ������
*/

#include <iostream>

using namespace std;

int N, M;
int **lab;
int **visited;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int wall_cnt=0;

int safe_sum = 0;
int max = 0;

//��ͷ� ����
void DFS(int y, int x)
{
	/*��������
	1.��� ������ �Ѿ ��
	2.���� ��
	3.�Ȱ��� 2�� ��
	*/
	if (y < 0 || x < 0 || y == N || x == M) return;
	if (lab[y][x] != 0) return;
	if (visited[y][x] == 1) return;

	visited[y][x] = 1;
	lab[y][x] = 2;

	for (int i = 0; i < 4; ++i)
	{
		DFS(y + dy[i], x + dx[i]);
	}

}

void cal_safe()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (lab[i][j] == 0) safe_sum++;
	if (safe_sum > max) max = safe_sum;
	safe_sum = 0;
	return;
}

void build_wall()
{
	if (wall_cnt >= 3) {
		for (int ii = 0; ii < N; ++ii)
			for (int jj = 0; jj < N; ++jj)
				if (lab[ii][jj] == 2 && visited[ii][jj] != 1)
					DFS(ii, jj);
		cal_safe();
		return;
	}
		
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (lab[i][j] == 2 || lab[i][j] == 1) continue;
			else {
				lab[i][j] = 1;
				wall_cnt++;
				build_wall();
			}
		}
			
}


int main()
{
	cin >> N >> M;
		
	lab = new int*[N];
	for (int i = 0; i < N; ++i)
		lab[i] = new int[M];

	//�� �޾Ƶ��̱�
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> lab [i][j];

	build_wall();

	cout << max;


}