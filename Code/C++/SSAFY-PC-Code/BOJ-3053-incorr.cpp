//제목 : 택시 기하학
//목적 : 새로운 기하학 개념을 이용해 값을 계산할 수 있는가
//조건 : 반지름 R은 10^4 정답 오차는 10^-4까지 허용

//유클리드 기하학 원넓이 = piR^2
//택시 기하학의 원은 마름모이다. 

/*구현 : 
1. 정밀도를 쓸줄 아는가
2. pi상수를 쓸줄 아는가.
3. root(2) 값을 얻을 줄 아는가.
*/

//느낀점 : 왜 틀린거지?

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int R;

	setprecision(10);
	cin >> R;
	
	cout << M_PI * R * R << '\n';
	cout << 2 * R * R<<'\n';
	
}