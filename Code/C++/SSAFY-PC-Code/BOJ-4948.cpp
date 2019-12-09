//제목 : 베르트랑 공준
/*목적  :
1.소수에 대해 이해하고 있는가
2.소수 관련 정리들을 컴퓨터를 이용해 구현할 수 있는지
*/
/*아이디어 : 결국 컴퓨터로 소수 구하는 가장 빠른건 에라토스테네스 체
시간복잡도는 O(N*log(logN))이라고 함
1. 그냥 2n까지 에라토스테네스 체를 다 쓴다.
2. n부터 2n까지 가면서 검사하면서 ++한다.
*/

/*구현 : 에라토스테네스의 체 구현
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	while(1)
	{
		cin >> N;
		if (N == 0) break;

		char numArray[246912]; //2n이므로 123456*2에 주의
		memset(numArray, 1, sizeof(numArray));

		for (int i =2; i*i<=2*N;++i)
			if (numArray[i] == 1) {
				for (int j = i * i; j <= 2*N; j += i)
					numArray[j] = 0;
			}
		int sum = 0;
		for (int i = N + 1; i <= 2 * N; ++i)
			if (numArray[i] == 1) sum++;
		cout << sum << '\n';
	}
}