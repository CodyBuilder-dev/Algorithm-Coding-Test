//제목 : 초콜릿 자르기
//목적 : 금이 가 있는 N*M초콜릿을 최소한도로 쪼개기

/*아이디어 : 엥 몇번 해봤는데 이거 그냥 N*M-1 아냐?
->진짜 맞았다...*/

/*초콜릿 자르기 증명
1. 점화식을 이용한 증명
*/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	cout << N * M - 1;
}