//제목 : 10부제
//목적 : 배열에서 찾고자 하는 숫자의 개수 세기

/*아이디어 : 아무래도 탐색(search) 문제의 입문용 문제인듯
5개뿐이므로 단순 O(N)짜리 순차탐색으로 가능
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int numArray[5];

	scanf("%d", &N);

	scanf("%d %d %d %d %d",
		&numArray[0], &numArray[1], &numArray[2], &numArray[3], &numArray[4]);
	
	int sum=0;
	for (int i = 0; i < 5; ++i)
		if (numArray[i] == N) sum++;

	printf("%d", sum);
}