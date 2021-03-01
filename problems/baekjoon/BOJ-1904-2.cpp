//제목 : 01타일
//목표 : 00, 1 두가지 타일이 있을 때, 두 타일로 만들 수 있는 길이가 N인 모든 경우의 수
//조건 : N은 최대 100만

/*아이디어 2 :
팩토리얼로 안되겠다. 점화식을 찾으면 된다 함
팩토리얼  그 자체뿐 아니라, 팩토리얼이 분자 분모에 들어간것도 점화식 가능

N = 2k일때, O(0) = 1 = k!/k!
O(1) = O(0) * k+1*k/(1*2)
O(2) = O(1) * 
O(l+1) = (k+l)!/(k-l)!2l! = O(l) * k+l * k - l /(2l) /(2l-1)

N = 2k+1일때
O(l+1) = O(l) * (k+l) * (k - l +1 )/ (2l+1) / (2l)
*/
#include <iostream>

using namespace std;

long long factorial_array[1000001] = { 0 };

long long factorial(long long k)
{
	if (k == 1) return 1;
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

int main()
{
	long long N;

	cin >> N;
	cout << factorial(N) % 15746;

}