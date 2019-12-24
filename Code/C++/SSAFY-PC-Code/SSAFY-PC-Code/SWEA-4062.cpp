//제목 : Largest Empty Square
//목적 : 흑백사진에서, 크기가 가장 큰 정사각형을 구하는 방법
//조건 : 최대 1000x1000

/*아이디어 : 당연히 브루트포스는 시도조차 안되고, dp써야됨
현재 정사각형에서 다음 정사각형으로 (x)
현재 칸에서 다음 칸으로 (O)라는 마인드로 접근해야 점화식 세워짐

*/

/*느낀점 : 점화식은 어떤거 기준으로 세워야 할지 해보기 전엔 모른다
따라서, 빨리 세워보고 빨리 틀리고 다른거 찾느 것이 ㅈ요하다
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