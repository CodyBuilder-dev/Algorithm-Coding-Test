//제목 : 피보나치 함수
//목적 : 피보나치 수를 구하는 것이 아니라, 재귀에서 호출 횟수를 구하라
//조건 : N = 40,

/*아이디어 : 직접 수를 구하려 하지 말고, 계수를 그냥 더하자
f(0) = 1f(0)+0f(1)
f(1) = 0f(0)+1f(1)
f(2) = 1 + 1;
f(3) = 

*/



#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//피보나치 각 항들(f(0),f(1),....f(n))을 배열에 저장
//pair의 first는 f(0)의 계수, second는 f(1)의 계수
//f(n) = xf(0)+yf(1)꼴로 표현
pair<int, int> fibonacci[41];

int T;
int N;

int main()
{

	fibonacci[0] = make_pair(1, 0);
	fibonacci[1] = make_pair(0, 1);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		if (N == 0) cout << fibonacci[0].first << ' ' << fibonacci[0].second << '\n';
		else if(N==1) cout << fibonacci[1].first << ' ' << fibonacci[1].second << '\n';
		else {
			for (int j = 2; j <= N; ++j)
			{
				fibonacci[j].first = fibonacci[j - 1].first + fibonacci[j - 2].first;
				fibonacci[j].second = fibonacci[j - 1].second + fibonacci[j - 2].second;
			}
			cout << fibonacci[N].first << ' '<< fibonacci[N].second << '\n';
		}
	}
}