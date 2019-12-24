//제목 : 01타일
//목표 : 00, 1 두가지 타일이 있을 때, 두 타일로 만들 수 있는 길이가 N인 모든 경우의 수
//조건 : N은 최대 100만

/*아이디어 :
정리해보면 결국 같은것이 있는 순열 계산을 해야함
근데 같은것이 있는 순열에는 팩토리얼이 들어감
즉 팩토리얼 계산을 다 해야되는데
알다시피 재귀로 하면 겁나 오래걸리고 자료 커짐
N = 1,000,000이면, k = 500,000까지 갈 수도 있고 이럼 500000!은 못구하지...

머릿속으로 식을 정리 해 보면 굳이 500,000! 안구해도 됨
*/

long long factorial_array[1000001] = { 0 };

long long factorial(long long a)
{
	if (a == 1) return 1;
	else
	{
		if (factorial_array[a] != 0)
			return factorial_array[a];
		else {
			factorial_array[a] = a * factorial(a - 1);
			return factorial_array[a];
		}
	}
}
#include <iostream>

using namespace std;

int main()
{
	long long N;

	cin >> N;
	cout << factorial(N) % 15746;
	
}