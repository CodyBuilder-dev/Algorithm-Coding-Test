//제목 : 막대기
//목적 : 반반만 잘라서 원하는 길이 만들기

/*
아이디어 : 사실 자연수 n을 2의 제곱수의 합으로 나타내는 문제
방법 : 그리디로다가 제일 큰 2 제곱수 빼버리기
*/

/*
다른사람 아이디어 :
1.다 그리디로 똑같이 품
2. 나처럼 pow안쓰고 /2써서 해도 됨
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int X;
	cin >> X;

	int minus_cnt=0;

	for (int i= 6; i >= 0; --i)
	{
		if (pow(2, i) > X) continue;
		X -= pow(2, i);
		minus_cnt++;
	}
	cout << minus_cnt;
	return 0;
}
