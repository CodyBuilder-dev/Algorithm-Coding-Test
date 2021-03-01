//제목 : A+B - 8
//목적 : 두 정수 A+B의 합을 조건에 맞게 출력하는 것
//조건 : 특정 형식으로 출력해야 함

//느낀점 : 확실히 scanf가 cin보다 빠름

#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a,b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
}