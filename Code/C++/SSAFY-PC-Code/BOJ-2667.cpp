//���� : ������ȣ ���̱�
//���� : 2���� �迭�� ��ȸ�� �� BFS/DFS�� �� �� �ִ°�
/*���̵��
1. BFS�� �غôµ� ö���� ������
2. ������ �ִܰ�� ���� ���� ���� �ƴϹǷ�, DFS�� ���� ���� ������ �ִ�.
*/

/*����
0. �׷��� ��ü Ž���ϴ� 1 ������ DFS ����
1. ���� ��ȣ�� ���������� ����, �迭�� ����
2. ���� ������ �Ź� �ʱ�ȭ �� ī����
3. ���̻� �� �� �մ� ���� ������ DFS ����
*/

/*������
1. �迭���� �������� �߸� �� �������� ����� �ܿ��� ��
2. �迭 �ε����� �ʰ��ϴ� ��輱���� ������ �����ؾ� ��
3. ���������� �ǵ帱 ���� ���� �������� ���� ������ ��Ȯ�� Ȯ���� ��
4. 2�����迭 2�� �� ����, board�� visited �� ���� �ִ��� Ȯ���ϱ�

*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int **board;
int **visited;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int danji_num = 0;
int apt_cnt[70] = {0};
int cnt = 0;

void DFS(int x, int y)
{
	//cout << "bug2_dfs"; �����۵�
	if (x >= N || y >= N || x < 0 || y < 0) return;
	if (visited[x][y] != 0) return;
	if (board[x][y] != 1) return;

	visited[x][y] = 1;
	cnt++;

	//cout << "bug3_dfs";
	//�迭 �ε��� �ʰ� ������ �̰�
	for (int i = 0; i < 4; ++i)
		DFS(x+dx[i], y+dy[i]);

	apt_cnt[danji_num] = cnt;
}

int main()
{

	scanf("%d", &N);

	board = new int*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new int[N]();

	visited = new int*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new int[N]();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &board[i][j]);

	//DFS����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == 1 && visited[i][j] != 1) {
				DFS(i, j);

				danji_num++;
				cnt = 0;
			}
		}
	}

	cout << danji_num << '\n';
	if (danji_num == 0) cout << 0;
	else{
		sort(apt_cnt, apt_cnt + danji_num);
		for (int i = 0; i < danji_num; ++i)
			cout << apt_cnt[i] << '\n';
	}
	
}