//���� : ���� Ż��2
//���� : �峭���� 4�������� ��￩ �������� ���� ������
/*���� : ������ ���ۿ� ���� ������ ������ ����
1. ����̱�� 90�� ȸ���� �ƴ϶� �׳� �߷��� �������� ����̴� ��
2. ������ ũ��� 10x10
*/

/*���̵�� :�� �������� 4������ ����� ���� ������ Ʈ����� ���� ��
1. �ϴ� ���� �ޱ�
2. ����, ������, �Ʒ�, �� �Լ� ����
3. DFS�� ���� 4���� �� ������
4. ������ ����� ��� �� ���� �����ؼ� min���� ���
�ݺ�
*/

//������ : 4������ dy,dx�� �ƴ϶� left,right �Լ��� �̷�������� bfs ���پƴ°�
/*������ : 2�����迭�� ���ڿ� ���� ��
�Լ� ���Ǵ� board[][10]������, ���� ������ Ȯ���ؼ� �ִ´�
���� ȣ��ô� �迭 �̸� board�� �ִ´�
*/
//�迭�� ����Լ��� �������� �� ��� �Ǵ��� �������� ��
//�迭�� ������ ��, memcpy�� copy�� �ִµ� memcpy�� ����.
//sizeof�� 2�����迭�� ��쿡�� ����Ʈ�� ���ε�, ����ũ��� �׳� ���� �ִ°� ���� �� ����
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
char board[10][10];
bool visited[10][10];

int minima;
vector<int> cntset;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	/*
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cout << board[i][j];
	*/
}

//����
void left(char curboard[][10])
{
	//�켱 ���������� ���鼭 ���� ��ġ ã��
	//���� ã������ ������ �������� ������
	//�״��� �� ã�Ƽ� ������
	//������ �� ������ ����
	//������ ���� ������ Ż�� �÷��� �����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B'){
				int k = j;
				while (k - 1 >= 0 && curboard[i][k-1] == '.') {
					swap(curboard[i][k], curboard[i][k - 1]);
					k -= 1;
				}
				if (curboard[i][k - 1] == 'O') {
					if (curboard[i][k] == 'R') {

						curboard[i][k] = '.';
					}
					if (curboard[i][k] == 'B') {

						curboard[i][k] = '.';
					}
				}
			}
		}
	}
}

//������
void right(char curboard[][10])
{
	for (int i = 0; i < N; ++i) {
		for (int j = M-1; j >=0; --j) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B'){
				int k = j;
				while (k + 1 < M && curboard[i][k+1] == '.') {
					swap(curboard[i][k], curboard[i][k + 1]);
					k += 1;
				}
				if (curboard[i][k + 1] == 'O') {
					if (curboard[i][k] == 'R') {
						curboard[i][k] = '.';
					}
					if (curboard[i][k] == 'B') {
						curboard[i][k] = '.';
					}
				}
			}
		}
	}
}

//����
void up(char curboard[][10])
{
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N; ++i) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B') {
				int k = i;
				while (k - 1 >= 0 && curboard[k - 1][j] == '.') {
					swap(curboard[k][j], curboard[k - 1][j]);
					k -= 1;
				}
				if (curboard[k - 1][j] == 'O') {
					if (curboard[k][j] == 'R') {

						curboard[k][j] = '.';
					}
					if (curboard[k][j] == 'B') {
		
						curboard[k][j] = '.';
					}
				}
			}
		}
	}
}

//�Ʒ���
void down(char curboard[][10])
{
	for (int j = 0; j < M; ++j) {
		for (int i = N-1; i >=0; --i) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B') {
				int k = i;
				while (k + 1 < N && curboard[k + 1][j] == '.') {
					swap(curboard[k][j], curboard[k + 1][j]);
					k += 1;
				}
				if (curboard[k + 1][j] == 'O') {
					if (curboard[k][j] == 'R') {
						curboard[k][j] = '.';
					}
					if (curboard[k][j] == 'B') {
						curboard[k][j] = '.';
					}
				}
			}
		}
	}
}
int check_win(char curboard[][10])
{
	bool Rout = true;
	bool Bout = true;
	//���带 �ѹ��� �� ���鼭 RB���� �ľ�
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (curboard[i][j] == 'R') Rout = false;
			if (curboard[i][j] == 'B') Bout = false;
		}

	if (Rout == true) {
		if (Bout == true) return -1;
		else return 1;
	}
	else {
		if (Bout == true) return -1;
		else return 0;
	}
}
//���� �̵� ����
void start_game_dfs(char curboard[][10],int cnt)
{
	//������ �����
	//left�غ���
	//���ӳ�? Ƚ�� ���� �� ���ư���
	//�ȳ�? ���� dfs�� �ѱ��
	//right�غ���
	//..�ݺ�

	if (cnt > 10) {
		return;
	}

	char newboard[10][10];
	memcpy(&newboard[0][0], &curboard[0][0], 100);
	//cout << "��ȯ ��" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << newboard[i][j];
	//	cout << '\n';
	//}
	
	left(newboard);
	//cout << "��ȯ ��" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << newboard[i][j];
	//	cout << '\n';
	//}

	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt+1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}

	memcpy(&newboard[0][0], &curboard[0][0], 100);
	right(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}

	memcpy(&newboard[0][0], &curboard[0][0], 100);
	up(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}
	memcpy(&newboard[0][0], &curboard[0][0], 100);
	down(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}
}


int main()
{
	input();

	//�̷��� ������� ���� �ּҿ� �����ϴ°Ŷ� board�� newboar�� ���� ����
	//2���� �迭�� �����ϴ� ��� �˾ƾ� ��
	char newboard[10][10];
	//cout << sizeof(newboard);
	memcpy(&newboard[0][0], &board[0][0], sizeof(board));
	
	//copy(&board[0][0], &board[0][0] + N * M, &newboard[0][0]);
	//���⼱ ���� �� �Ǵµ�
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << newboard[i][j];
		cout << '\n';
	}*/

	start_game_dfs(newboard, 1);

	if (cntset.size() == 0) minima = -1;
	else {
		minima = 987;
		for (int i = 0; i < cntset.size(); ++i)
			if (cntset[i] < minima) minima = cntset[i];
	}
	cout << minima;
}