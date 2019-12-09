//제목 : 피보나치 수 2
//목적 : 동적 계획법으로 피보나치 수를 푼다
//차이점 : n =45에서 n =90으로 증가했음
/*아이디어 : BOJ-2747와 동일하게, 메모이제이션 쓰면 된다
그러나 주의할 점은 n<=90이므로, int 범위를 한참 벗어나므로 데이터타입을 바꿔야 한다.
*/
//느낀점 : 심지어 n =90인 경우에는 long long으로도 모자람
#include <iostream>

using namespace std;

//전역 피보나치 array

long long fiboarray[45] = { 0 };

long long fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		if (fiboarray[n] != 0) return fiboarray[n];
		else
		{
			fiboarray[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return fiboarray[n];
		}
	}
}
int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n);
	return 0;
}
