//제목 : 상수
//목적 : 숫자를 거꾸로 읽은 후 그 크기를 비교한다
//조건 : 숫자는 세자리 수이다.

/*아이디어 : 마찬가지로 숫자를 문자열로 적절히 변환해서 처리
1. 문자열로 변경
2. 뒤집기
3. 비교
*/

#include <iostream>
#include <string>

using namespace std;

int a, b;

int main()
{
	cin >> a >> b;
	string aStr = to_string(a);
	string bStr = to_string(b);
	swap(aStr[0], aStr[2]);
	swap(bStr[0], bStr[2]);

	a = atoi(aStr.c_str());
	b = atoi(bStr.c_str());
	
	if (a > b) cout << a; else cout << b;
	return 0;
}