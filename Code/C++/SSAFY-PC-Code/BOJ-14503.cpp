//���� : �κ� û�ұ�
//���� : �־��� �޴����� �����ϴ� �κ�û�ұ� ����
/*���� : 
���� : 0�� 1�� 2�� 3��.
���� 1 ��ĭ�� 0 û�ҵ� ���� 2 ������ ���� ����
*/

/*���̵�� : �ùķ��̼� + ��Ž
0. �������� ���� ��Ž�̹Ƿ� ����� 2���� �迭, visited ����
1.������ ���� = ���� �����ִ� ���⿡ ���� ���� '����'�� ������
(dx dy�� ��������)
2. dx dy �� ���� ���������� �˻�
3. �� ������ �� ������ FS ��ͷ� ���
4. �� �������̸� return;
*/

#include <iostream>

using namespace std;

int N, M;

int dx[] = { -1,0,1,0 }; //���ϵ���
int dy[] = { 0,-1,0,1 };
int nowDir;

int **board;

void DFS(int y, int x)
{
	/*���� return���� ����
	1. ������ ���� ������ �������� �� ��
	2. ������ ���� ���϶�
	
	return���� ����
	1. 4���� �� ġ���� �� ġ��� ���� ��
	2. 4���� �� ġ���µ� ������ �ȵ� ��
	*/
	if (y < 0 || x < 0 || y == N || x == M) return;
	if (board[y][x] == 1) return;

	board[y][x] = 2; //�ϴ� û�ҵ� ������ 2�� ǥ���ϰ���

	//�켱 for ������ DFS���� ���
	int nextDir;
	for (int i = 0; i < 4; ++i){
		if (nowDir == 0) nextDir = 3;
		else nextDir = nowDir - 1;

		if (board[y + dy[nextDir]][x + dx[nextDir]] != 0) nowDir = (nowDir+1)%4;
		else DFS(y + dy[nextDir],x + dx[nextDir]);
	}
	
	for (int i = 0; i < 4; ++i) {
		if (nowDir == 0) nextDir = 3;
		else nextDir = nowDir - 1;
		if (board[y + dy[nextDir]][x + dx[nextDir]] != 0) {

		}
	}
	switch (nowDir)
	{
	case 0: 
		if (board[y + dy[3]][x + dx[3]] == 2) nowDir
		
	case 1:
	case 2:
	case 3:
	}

	int openDir;
	for (int i = 0; i < 4; ++i)
	{
		if (board[y + dy[i]][x + dx[i]] != 1) openDir++;
	}
	if (openDir == 0)
	{
		switch (nowDir)
		{
		case 0: 
			if (board[y + dy[3]][x + dx[3]] == 1) break;
			else DFS(y + dy[0], x + dx[0]);
		case 1:
			if (board[y + dy[0]][x + dx[0]] == 1) break;
			else DFS(y + dy[1], x + dx[1]);
		case 2:
			if (board[y + dy[1]][x + dx[1]] == 1) break;
			else DFS(y + dy[2], x + dx[2]);
		case 3:
			if (board[y + dy[2]][x + dx[2]] == 1) break; //���� ����
			else DFS(y + dy[3], x + dx[3]);
		}
	}

	

}
int main()
{
	
}