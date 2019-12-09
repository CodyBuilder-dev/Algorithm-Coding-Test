//제목 : 피보나치 함수
//목적 : 피보나치를 재귀로 쓸 때 호출횟수를 구한다.
//아이디어 : 재귀로 그냥 구현하고, 호출될때마다 cnt++를 해주는 구문을 추가한다.
//문제점 : 그냥 재귀로 구현하면 시간 초과되게 되어있음ㅋㅋㅋㅋㅋㅋㅋㅋ
//아이디어2 : 동적할당 구현하고, 0,1 횟수도 동적할당 하는거임 ㅋㅋ
//0,1으 횟수를 저장하는 자료구조는 pair
#include <iostream>
#include <utility>
using namespace std;

//n번째 피보나치 수의 0,1 호출 개수를 저장하는 배열
pair<int, int> cnt[40];


pair<int,int> fibonacci(int n) {
	if (n == 0) {
		cnt[0].first = 1;
		cnt[0].second = 0;
		return cnt[0];
	}
	else if (n == 1) {
		cnt[1].first = 0;
		cnt[1].second = 1;
		return cnt[1];
	}
	else {
		if (cnt[n].first != 0 && cnt[n].second != 0) {
			return cnt[n];
		}
		else
		{
			cnt[n] = fibonacci[n - 1] + fibonacci[n - 2];
			return cnt[n];
		}
		
	}
}

int main()
{
	int T;
	int N;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> N;
		fibonacci(N);
		cout << cnt[N].first << ' ' << cnt[N].second << '\n';
	}

	return 0;
}