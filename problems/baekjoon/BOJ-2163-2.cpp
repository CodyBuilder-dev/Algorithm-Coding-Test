//제목 : 초콜릿 자르기
//목적 : 금이 가 있는 N*M초콜릿을 최소한도로 쪼개기

/*아이디어 : DP를 이용해서 풀어보자
1. N*M을 가로로 k번째에서 나누면
k*M, (N-k) *M짜리로 나뉜다
O(N,M) = 1+ O(k,M)+O(N-k,M) =
= 1 + k-1 +(k)O(1,M) + N-k-1 + (N-k)O(1,M)
= N-1 + (N)O(1,M)
= N-1 +(N)(M-1) = NM-1
*/

/*구현 : DP 점화식으루다가 바텀업으로
O(2,1) = O(1,1)+O(1,1)+1
O(3,1) = 1+O(
*/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int O[301][301] = { 0 };
	for (int i = 1; i < 301; ++i)
		for (int j = 1; j < 301; ++j)
			O[i][j] = 1 + O[i][j - 1] + O[i][1];
	cout << O[N][M];
}
