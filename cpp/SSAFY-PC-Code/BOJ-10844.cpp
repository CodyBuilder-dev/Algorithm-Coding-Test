//제목 : 쉬운 계단 수
//목적 : '계단 수'의 정의를 이해하고, N자리의 계단 수의 개수를 구하여라
//조건 : N은 최대 100, 정답은 10억으로 나눈 수

/*아이디어 : 10억으로 나눈 나머지를 출력한다->무조건 DP
엥?? 그냥 최대 100자리니까 0자리부터 100자리까지 읽으면 되는거 아니냐?
->경우의 수가 겁나 많으므로 안됨

점화식? 가능할듯
->N자리의 경우의 수를 저장
->N+1자리는 N자리 경우의 수에서
끝이 9인 경우 그대로 1가지
끝이 0인 경우 그대로 1가지
그 외는 +1,-1붙인 2가지

메모이제이션? 써야지
*/

/*느낀점 : 
1.값을 너무 뛰어넘으면 2로 출력된다
2. 점화식이라는게 그렇게 대충 짜지는게 아닐 수 있다.
->컴퓨터의 장점인, 모든 케이스를 다 저장할수 있다는 점을 이용해
케이스별로 잘 나눠서 짜야할 수 있음
*/

#include <iostream>
#define DEVIDEND 1000000000

using namespace std;
int N;
long long caseCnt[101][10];

long long find_case(int n,int last)
{
	if (n <= 0) return 0; //탈출조건
	if (caseCnt[n][last] != 0) return caseCnt[n][last]; //메모이제이션 사용
	
	long long nowCase;
	if (last == 0) {
		nowCase = find_case(n - 1, 1)%DEVIDEND;
	}
	else if (last == 9) {
		nowCase = find_case(n - 1, 8)%DEVIDEND;
	}
	else {
		nowCase = (find_case(n - 1, last - 1) + find_case(n - 1, last + 1)) % DEVIDEND;
	}

	caseCnt[n][last] = nowCase;
	return nowCase;
}
int main()
{
	cin >> N;
	//1자리, 2자리는 하드코딩
	for (int i = 1; i <= 9; ++i)
		caseCnt[1][i] = 1;
	
	//3자리부터는 맨 뒤에 0인 경우의수를 고려해줘야 함

	long long sum = 0;
	for (int i = 0; i <= 9; ++i)
		sum += find_case(N, i) ;

	cout << sum%DEVIDEND;
}