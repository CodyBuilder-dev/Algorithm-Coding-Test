//제목 : 에라토스테네스의 체
//목적 : 에라토스테네스의 체를 조건대로 구현할 수 있는가

/*구현
1. 우선 다 지워놓고 마지막에 세기? ->No
2. 지우는 즉시 cnt 증가
3. 처음에 1로 초기화, 그 후 0으로 지움. 
*/
#include <iostream>
//#include <cstring>

using namespace std;

char* prime;

int main()
{
	int N,K;
	cin >> N >> K;
	prime = new char[N+1](); //그냥 0초기화 고고
	//memset(prime, -1, N+1); 이거 쓰면 왜 작동 안되는지?

	
	int cnt = 0;
	for (int i = 2; i<=N;++i)
		if (prime[i] == 0)
		{
			prime[i] = 1;
			cnt++;
			if (cnt == K) cout << i;
			for (int j = 2 * i; j <= N; j += i) {
				if(prime[j] == 0){
					prime[j] = 1;
					cnt++;
					if (cnt == K) cout << j;
				}
			}
			
		}
}