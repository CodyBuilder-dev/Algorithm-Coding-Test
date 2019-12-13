//���� : Largest Empty Square
//���� : ����������, ũ�Ⱑ ���� ū ���簢���� ���ϴ� ���
//���� : �ִ� 1000x1000

/*���̵�� : �翬�� ���Ʈ������ �õ����� �ȵǰ�, dp��ߵ�
���� ���簢������ ���� ���簢������ (x)
���� ĭ���� ���� ĭ���� (O)��� ���ε�� �����ؾ� ��ȭ�� ������

*/

/*������ : ��ȭ���� ��� �������� ������ ���� �غ��� ���� �𸥴�
����, ���� �������� ���� Ʋ���� �ٸ��� ã�� ���� �����ϴ�
*/

#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;
int board[1000][1000];
int dp[1000][1000];
int countmax;

void input()
{
	cin >> N;
	for (int row = 0; row < N; ++row)
		for (int col = 0; col < N; ++col)
			scanf("%1d", &board[row][col]);

	//for (int row = 0; row < N; ++row) {
	//	for (int col = 0; col < N; ++col)
	//		printf("%d", board[row][col]);
	//	printf("\n");
	//}

}
void count()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = board[i][j];
			}
			else if (board[i][j] == 0) {
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] }) + 1;
				countmax = (dp[i][j] > countmax) ? dp[i][j] : countmax;
			}
		}
	}

}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		countmax = -987654321;
		memset(dp,0,sizeof(dp));
		input();
		count();
		printf("#%d %d\n", i, countmax);
	}
}