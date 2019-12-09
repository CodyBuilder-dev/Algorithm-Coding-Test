//제목 : Kids Love Candies
//목적 : 만족시킬 수 있는 최대의 아이 숫자를 계산하는 것
//조건 : T 최대 100, 

/*아이디어 : 각 캔디를 나눈 몫을 구해서 더한다.
*/

#include <iostream>

using namespace std;

int T;
int N, K;
int kids;
int sum;

int main()
{
	scanf("%d", &T);
	
	for (int i = 1; i <= T; ++i)
	{
		int sum = 0;
		scanf("%d%d", &N, &K);
		int temp;
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &temp);
			sum += temp / K;
		}

		printf("%d\n", sum);
	}
	return 0;
}




