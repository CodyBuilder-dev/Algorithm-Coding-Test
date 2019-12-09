//���� : ������ ��
//���� : ���������� �̵��ϴ� ����� ��
//���� : ������ �ִ� ũ��� 500

/*���̵�� : DFS+�޸������̼�. Ż���̶� �����
1.DFS�� ��� ã�Ƽ� Ż����
2.��λ��� ��� ���� exitable üũ
*/

/*DFS+DP�� ���� ���� �߸� �����ϰ� �־���
���� ������ Ǯ�� : �׳� DFS�ϸ鼭, �����ϰ� �� ��� ���ݱ��� ��� ���� exitable�ϰ� 1 ���ء���
���ٰ� �̹� exitable�� ������ ��� ���������� �̶����� ��Ʈ�� ���� exitable�ϰ� ��Ʈ�� 1 �����ش�
->������ : ���� ��ηκ��� �Ļ��Ǵ� ��� ������ ���� �ʰ� �� +1�� ��ħ

�´� Ǯ�� : exitable ��/�� �� �ƴ϶�, �ش� �����κ��� ����� Ż���� �� �ִ°��� ������� ��
->�׳� ���ϴ� ���� �ƴϰ�, ���ϱ�� ����� ��

DPǮ�� : ���� ������ ���� �����, ������ �ٷ� �� �������� ����� ���� ����
*/

/*DFS���� return�� ��ġ��, for�� �ȿ� ������ �� ���� �� ����
���� : �׹���� ���캸�⵵ ���� Ż���ع���
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N;

int board[500][500];
bool exitable[500][500];
int dp[500][500];

int dy[] = { 1,0,-1,0 }; //�����ϼ�
int dx[] = { 0,1,0,-1 };

deque<pair<int, int>> routeSet;

void input()
{
	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
}

void find_route_dfs(int y, int x, deque<pair<int, int>> route)
{
	/*���� �帧
	1. �ϴ� ���� Ž��
	2. Ž���ϸ鼭 ��� ����� �� ������ ����
	3. ���ٰ� Ż���ϸ�
	4.
	5.
	*/
	if (y == M - 1 && x == N - 1) { //Ż���ϸ�
		for (int j = 0; j < route.size(); ++j) {
			exitable[route[j].first][route[j].second] = true;
			dp[route[j].first][route[j].second] += 1;
		}
		return;
	}
	if (exitable[y][x] == true) { //�̹� Ż�Ⱑ���ϴٰ� ���� ���
		for (int j = 0; j < route.size(); ++j) {
			exitable[route[j].first][route[j].second] = true;
			dp[route[j].first][route[j].second] += 1;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N) {//�������
			if (board[y][x] > board[ny][nx]) {//������
				deque<pair<int, int>> newRoute(route);
				newRoute.push_back(make_pair(ny, nx));
				find_route_dfs(ny, nx, newRoute);
			}
		}
	}
}

//dp�� �����丮�� ����ϱ⶧���� int�� return�� ���̶�� ������ �� �ִ�.
int find_route_dp(int y, int x)
{
	if (y == M - 1 && x == N - 1)
		ret
	else if (dp[y][x] != 0)
		return dp[y][x];

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N) {//�������
			if (board[y][x] > board[ny][nx]) {//������
				return find_route_dp()
			}
		}
	}
}
int main()
{
	input();
	dp[0][0] = 1;

	//find_route_dfs(0, 0,routeSet);
	
	cout << dp[0][1] + dp[1][0];


}