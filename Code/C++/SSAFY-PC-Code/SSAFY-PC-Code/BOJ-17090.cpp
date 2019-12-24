//���� : �̷� Ż���ϱ�
//���� : �̷ο��� Ż�� ������ ĭ�� ã��
//���� : �̷��� ũ��� 500x500 = 250

/*���̵�� : �̰� ��Ž�Ѵ� ġ�� 25�� x25������ �� �ڻ쳲
D/BFS�� ��Ž�� �ϵ�, �޸������̼����� Ż�Ⱑ���� ĭ�� �����ϸ� �ٷ� Ż���ؾ� ��
*/

/*������ : 
1.exit/unexit�� �ΰ� ���� �Ǵ°�? ->����
2.Ž�� �� ������ ��δ� ��� �����ϴ°�?
-> �迭�� �ϸ� ������ ����, 
->����? ��κ� ����
->��ť? ����
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M;

char board[500][500];
bool visited[500][500]; //�̹� bfs�� �� �ֵ�

bool exitable[500][500];
bool unexitable[500][500];

bool exited;
int dy[] = { 1,0,-1,0 }; //�� �� �� ��
int dx[] = { 0,1,0,-1 };
//deque<pair<int, int>> pastRoute;
vector<pair<int, int>> pastRoute;
void find_path_dfs(int y, int x)
{
	visited[y][x] = true;
	pastRoute.push_back(make_pair(y, x));

	int ny, nx;
	switch (board[y][x]) {
	case 'D':
		ny = y + dy[0]; nx = x + dx[0];
		if (ny >= N || ny <0 || nx >= M || nx < 0) { //�����µ� Ż�� �Ǵ� ���
			/*for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j) {
					if (visited[i][j] == true) exitable[i][j] = true;
					visited[i][j] = 0;
				}*/ //�̵����� �ϸ� �ð��ʰ� ������ ��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �������°��ΰ� �ƴ°��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �� �������� ���� ���
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //���� �� ���� ���� ���
			find_path_dfs(ny, nx);
		break;
	case 'R':
		ny = y + dy[1]; nx = x + dx[1];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //�����µ� Ż�� �Ǵ� ���
		/*for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == true) exitable[i][j] = true;
				visited[i][j] = 0;
			}*/ //�̵����� �ϸ� �ð��ʰ� ������ ��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �������°��ΰ� �ƴ°��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �� �������� ���� ���
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //���� �� ���� ���� ���
			find_path_dfs(ny, nx);
		break;
	case 'U':
		ny = y + dy[2]; nx = x + dx[2];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //�����µ� Ż�� �Ǵ� ���
			/*for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j) {
					if (visited[i][j] == true) exitable[i][j] = true;
					visited[i][j] = 0;
				}*/ //�̵����� �ϸ� �ð��ʰ� ������ ��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �������°��ΰ� �ƴ°��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �� �������� ���� ���
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //���� �� ���� ���� ���
			find_path_dfs(ny, nx);
		break;
	case 'L':
		ny = y + dy[3]; nx = x + dx[3];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //�����µ� Ż�� �Ǵ� ���
		/*for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == true) exitable[i][j] = true;
				visited[i][j] = 0;
			}*/ //�̵����� �ϸ� �ð��ʰ� ������ ��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �������°��ΰ� �ƴ°��
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //������ �ʾҴµ� �װ��� �� �������� ���� ���
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //���� �� ���� ���� ���
			find_path_dfs(ny, nx);
		break;
	}
}
//void find_path_bfs(int y, int x)
//{
//	queue<pair<int, int>> route;
//	visited[y][x] = true;
//	route.push(make_pair(y, x));
//
//	do {
//		y = route.front().first;
//		x = route.front().second;
//		route.pop();
//
//		switch (board[y][x]) {
//		case 'D': 
//			int ny = y + dy[0]; int nx = x + dx[0];
//			if(ny > N || ny <0 || nx > M || nx <0) { //Ż�� ������ ���
//				exitable[y][x] = true;
//			}
//			if(exitable[ny][nx] == true) 
//		case 'R':
//		case 'U':
//		case 'L':
//		}
//
//	} while (!route.empty());
//}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)	{
			cin >> board[i][j];
		}
	}

	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout<< board[i][j];
		}
		cout << '\n';
	}*/
	//�� �޾��� Ȯ��


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == false) {
				find_path_dfs(i, j);
				if (!exitable[i][j]) {//Ż����� ��� 
					for (int k = 0; k < pastRoute.size(); ++k) {
						unexitable[pastRoute[k].first][pastRoute[k].second] = true;
					}
					pastRoute.clear();
				}
			}
		}

	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (exitable[i][j] == true) cnt++;

	cout << cnt;

}
