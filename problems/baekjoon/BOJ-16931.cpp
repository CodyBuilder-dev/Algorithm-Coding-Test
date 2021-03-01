//���� : �ѳ��� ���ϱ�
//���� : �־��� ��ü������ �ѳ��̸� ���Ͽ���
//���� : �ظ��� ���̴� �ִ� 100x100, �� ���� ���̴� �ִ� 100

/*���̵�� : 
for�� ����
���� ������, 4�������� �ڱ� ��ġ�� �ֺ� ��� ��ġ ��
�ڱ���ġ > �ֺ���ġ�� �� ���̸�ŭ �ѳ���
�ڱ���ġ =< �ֺ���ġ�� ������ �ѳ��� ����
*/

#include <iostream>

using namespace std;

int board[100][100];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int N, M;
int sum;

void check_face(int y,int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny >= N || ny < 0 || nx >= M || nx < 0)
			sum += board[y][x];
		else if(board[y][x] > board[ny][nx])
			sum +=  board[y][x] - board[ny][nx];
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			check_face(i, j);

	sum += 2 * N * M;
	cout << sum;
}