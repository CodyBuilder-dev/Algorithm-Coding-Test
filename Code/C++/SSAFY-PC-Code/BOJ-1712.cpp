//제목 : 손익분기점
//목적 : 최초로 이익이 발생하는 판매량 구하기
//조건 : A,B,C각각 21억 이하 -> long long을 써야할 가능성 농후

/*아이디어 : A + B*q < C*q 에서 A/(B-C) = q
q가 실수인지 정수인지 판별하기
*/

/*느낀 점
1. long long 체크 못하면 영영 못품
2. int/float간의 관계 명확히 파악할 것
*/
#include <iostream>

using namespace std;

long long A, B, C;
long long q;

int main()
{
	cin >> A >> B >> C;

	if (B >= C) cout << -1;
	else {
		
		q = A / (C - B) + 1;
		cout << q;
	}
}