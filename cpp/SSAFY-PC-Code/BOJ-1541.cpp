//제목 : 잃어버린 괄호
//목적 : 식의 값을 최소로 만드는 괄호 위치 찾기
//입력 : 이미 문자열 형태로 식이 주어져 있음
//최소의 조건 : 식의 값 = (+붙은 양수의 총합)-(-붙은 양수의 총합)
//또한 a-b  나  -a+b
//즉, 36 + 5 + 34 - 535 - 3423 + 123  의 경우
//연달아 - + 오는 경우를 묶으면 됨

/*아이디어
일단 - 찾으면 그뒤에 괄호 -(
ㅅ계속 나아가다가 - 찾으면 괄호 취소 - -

계속 나아가다가 +찾으면 sig on 하고 계속 진행 -( +
계속 나아가면ㅅ +면 계속 살 붙이기 -( + + 
계속 나아가다가 -찾으면 그 앞에 괄호 -( + + )-


*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int paren_num;

	cout << str.size() << '\n';
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '-') {
			while 
		}
	}
}
