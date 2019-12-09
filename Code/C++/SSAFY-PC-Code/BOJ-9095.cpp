//제목 : 1,2,3 더하기
//목적 : 정수 n이 주어졌을 때, ndmf 1,2,3의 합으로 나타내는 방법의 수
//조건 : 정수 n은 11보다 작다

/*아이디어 : DP의 가장 기본기가 되는 문제
1.n을 만드는 경우의 수는
=n-1을 만드는 경우의 수 + n-2를 만드는 경우의 수 + n-3을 만드는 경우의 수
->bottom up 방식으로 구현. 피보나치와 비슷함
->증명을 해야 함
*/

/*아이디어 2 : DP테이블 그리는 법
*/

#include <iostream>

using namespace std;

int T;
int N;

int Cnt[11];

int main()
{
	cin >> T;
	Cnt[0] = 0;
	Cnt[1] = 1;
	Cnt[2] = 2;
	Cnt[3] = 4;
	for (int i = 1; i <= T; ++i)
	{
		cin >> N;
		for (int j = 4; j <= N; ++j)
		{
			Cnt[j] = Cnt[j - 3] + Cnt[j - 2] + Cnt[j - 1];
		}

		cout << Cnt[N];
	}
}