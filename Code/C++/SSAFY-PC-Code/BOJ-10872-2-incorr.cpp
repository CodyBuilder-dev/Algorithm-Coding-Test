//팩토리얼은 쉬움 ㅋㅋ
//12까지이므로 12! = 4억이므로 데이터타입 바꿀 필요도 없음
//근데 이문제는 시간초과가 좀 빡세네. cin cout 다해봐도 안됨
#include <iostream>

using namespace std;

int pactorial(int num)
{
	if (num == 1) return 1;
	return num * pactorial(num - 1);
}
int main()
{
	int N;

	scanf("%d", &N);

	printf("%d", pactorial(N));

}