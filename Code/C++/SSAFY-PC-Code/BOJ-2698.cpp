//제목 : 인접한 비트의 개수
//목적 : 0과 1로 이루어진 수열에서, 1이 2개 붙어있는 인접한 비트의 개수를 구하라
//조건 : 테케 1000개, 길이 n은 100이하, 인접 개수 k는 n보다 작겠지. 인접이 k인 수열의 개수는 int 범위 이내

/*아이디어 : next permu를 그냥 쓰면 무조건 에러난다. 수식을 고쳐서 점화식을 만들어야 함
*/


//느낀점 : 점화식을 구현하기 위해서 배열을 어떻게 써야 하는지 알겠음

#include <iostream>

using namespace std;

int dp[101][101][2]; //dp[n][k][0] = 길이 n 문자열에서, 인접이 k인놈 중, 끝이 0 인 놈 갯수

int T;
int N, K;

void calc_num(int length,int serial)
{
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 0;
	dp[1][1][1] = 0;
	for (int i = 2; i <= length; ++i){
		for(int j = 0; j< i;++j)
		{
			if (dp[i][j][0] != 0 && dp[i][j][1] != 0) //해당 부분이 차있을 경우
			{
				continue;
			}
			else{
				if (j == 0) {
					dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
					dp[i][j][1] = dp[i - 1][j][0];
				}
				else {
					dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
					dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
				}
			}
		}
	}
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> N >> K;
		calc_num(N, K);
		cout << dp[N][K][0] + dp[N][K][1] << '\n';
	}
}

