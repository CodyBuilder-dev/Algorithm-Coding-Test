//제목 : 인접한 비트의 개수
//목적 : 0과 1로 이루어진 수열에서, 1이 2개 붙어있는 인접한 비트의 개수를 구하라
//조건 : 테케 1000개, 길이 n은 100이하, 인접 개수 k는 signed int범위 내

/*아이디어 : 수식이 없으면 수식을 만들어야 하지만, 수식이 있으므로 쓰면 됨!
(이런건 배운 적 없는데..그냥 배운거로부터 써먹어야지)
1. 그냥 문제에 수식이 나와 있으므로 쓰면 됨
2.for문 돌려서 두개씩 더하면 됨
*/


//문제점 : next_permu로 그냥 풀면 무조건 시간초과남

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N, K;
int cnt;

int main()
{
	cin >> T;
	
	for (int i = 1; i <= T; ++i)
	{
		cnt = 0;
		cin >> N >> K;
		
		for (int j = K + 1; j < N; ++j)  //인접이 k개가 되려면 최소 1이 k+1개
		{
			vector<int> num;
			for (int k = 0; k < N-j; ++k) //앞에부터 0 넣기
				num.push_back(0);
			for (int k = N-j; k < N; ++k) //그다음 1넣기
				num.push_back(1);
			do {
				int serial = 0;
				for (int k = 0; k < N-1; ++k)
				{
					if (num[k]*num[k+1] == 1) serial++;
				}
				if (serial == K) cnt++;
			} while (next_permutation(num.begin(),num.end()));
			
		}

		cout << cnt;

	}
}