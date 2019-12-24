//제목 : R2
//목적 : 간단한 평균 식 구현하기
//조건 : (너무 쉬운 문제는 문제를 영어로 풀 것)

//아이디어 : R1+R2/2 = S 식 구현

#include <iostream>

using namespace std;

int main()
{
	int R1, R2, S;

	scanf("%d%d", &R1, &S);

	R2 = 2 * S - R1;

	printf("%d", R2);
}