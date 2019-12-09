//제목 : 행운의 편지
//목적 : 정수론에서 모듈러 연산의 수식적 의미를 아는가
//모듈러를 단순 나눗셈으로 생각하면 안된다.
//값 = 나머지 mod 몫
/*
아이디어 : 2~1000자리이므로
n = qa + a-1 = (q+1)a -1
a q 이중 for문
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	for (int a = 2; a <= 1000; ++a)
		for (int q = -10; q <= 10; ++q)
			n = (q + 1) * a - 1;
			cout << n << '\n';
}