//제목 : 거스름돈
//목적 : 그리디 알고리즘을 이용해 잔돈을 줄 수 있는가

/*구현 :
0. 동전의 관계(배수관계)를 보고 그리디로 풀수 있음 확인
->당장의 최적해가 최종적 최적해임을 확인
1. 동전의 배열을 만든다.
2. 500엔,100엔,50엔,10엔, 5엔 ,1엔 순으로 탐색한다.
3. 500엔을 빼서 결과가 양수면 okay, 음수면 100엔으로,
(혹은 if-else로도 가능)
(나머지와 나누기로 구현해도 됨)
*/

#include <iostream>

using namespace std;

int yen[] = { 500,100,50,10,5,1 };

int main()
{
	int num;
	cin >> num;
	num = 1000 - num;
	
	int cnt = 0;
	for (int i = 0; i < 6; ++i) {
		while (num > 0)
		{
			num -= yen[i];
			cnt++;
		}
		if (num < 0) {
			num += yen[i];
			cnt--;
		}
	}
	
	cout << cnt;
}