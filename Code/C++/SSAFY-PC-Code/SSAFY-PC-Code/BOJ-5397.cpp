//제목 : 키로거
//목적 : 키보드 입력값으로부터 비밀번호를 알아내기
//조건 : 입력 문자열의 크기는 최대 10^6

/*아이디어
1.테스트케이스 문자열 한자한자 검사
2.해당 부분의 값에 따라 비밀번호 문자열 만들기
*/

/*구현 : STL중 list를 이용해 구현
1. list와 같이 인덱싱이 불가능한 자료구조에서 어떻게 한칸씩 넘어가는가
-> 반복자를 써야 함
2. 반복자의 index는 distance로, 값은 *로 출력
*/


#include <iostream>
#include <string>
#include <list>

using namespace std;

int T;

string inStr;
list<char> passStr(1);
list<char>::iterator itr;

void check_char(char chr)
{
	switch (chr) {
	case '<': //좌측이동인 경우, 포인터의 위치가 0 초과면 감소
		if (itr != passStr.begin()) itr--;
		break;

	case '>': //우측이동인 경우
		if (itr != passStr.end()) itr++;
		break; //포인터의 위치가 passStr 사이즈 미만이면 증가
	case '-': //BS인 경우
		if (itr != passStr.begin()) {
			itr--;
			itr = passStr.erase(itr);
		}
		//cout << pointer << '\n';
		break;
	default: //알파벳인 경우
		passStr.insert(itr,chr);
		//itr++;
		//cout << pointer << '\n';
	}
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> inStr; //입력 문자열 받기
		passStr.clear(); //패스워드 문자열 초기화
		itr = passStr.begin();

		for (int j = 0; j < inStr.size(); ++j) { // 입력 문자열 처음부터 끝까지 탐색
			check_char(inStr[j]); //한자씩 체크
		}

		for(itr = passStr.begin();itr!=passStr.end();++itr)
			cout << *itr;
		cout << '\n';
	}
}