//제목 : 동전 0
//목적 : 그리디로 풀리는 문제. 동전 가치의 합
//조건 : 동전의 가치는 배수이고 많아봐야 10개
//그리디로 풀리는 이유 : 1원짜리가 존재함. 개수도 많지 않음.
//서로 배수 관계라 고액동전은 저액동전을 포함하므로, 고액부터 따져도 괜찮음
#include <iostream>

using namespace std;

int main()
{
	int  N, K;
	cin >> N >> K;
	int *coin;
	int cnt = 0;

	coin = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		while (K - coin[i] >= 0) {
		
			cnt++;
			K -= coin[i];
		}
	}
	if(K == 0) cout << cnt;
	else cout << -1;
}