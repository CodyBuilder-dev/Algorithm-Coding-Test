//제목 : 타일 붙이기
//목적 : 가로 행이 4, 세로행이 N인 타일 칸에 타일 붙이는 방법
//조건 : 테스트 케이스는 최대 1000개, 너비는 제한 없지만, 경우의 수가 int범위 안에 들어올 만큼만

/*아이디어 : 이거는 확실히 DP로 알겠네 ㅋㅋㅋ
1. 4*n을 채우는 경우의 수는 4*(n-1)이랑 4*(n-2)로부터 알 수 있음
2. Cnt(n) = Cnt(n-1)+1 + Cnt(n-2)+Cnt(2)-1
*/

//문제점 : 생각대로 점화식이 안 계산됨

//느낀점 : 공간에서의 점화식은 생각보다 복잡하다
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
int Cnt[1000];

int main()
{
	Cnt[0] = 0; // 4*0
	Cnt[1] = 1; // 4*1
	Cnt[2] = 5; // 4*2
	Cnt[3] = 11;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> N;
		
		if (N <= 3) cout << Cnt[N];
		else
		{
			for (int j = 4; j <= N; ++j)
			{
				Cnt[j] =
					Cnt[j - 1]
					+ Cnt[j - 2] * (5 - 1)
					+ Cnt[j - 3] * (11 - 9);
				//printf("Cnt[%d] = %d\n", j, Cnt[j]);
			}
			cout << Cnt[N] << '\n';
		}
		

	}
}