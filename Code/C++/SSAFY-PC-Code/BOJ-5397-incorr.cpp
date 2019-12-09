//제목 : 키로거
//목적 : 키보드 입력값으로부터 비밀번호를 알아내기
//조건 : 입력 문자열의 크기는 최대 10^6

/*아이디어
1.테스트케이스 문자열 한자한자 검사
2.해당 부분의 값에 따라 비밀번호 문자열 만들기
*/

//구현 : string의 중간에 값을 넣는 방식으로 구현해보자

//느낀점 : 실제 커서의 위치는 문자와 문자 사이인데, 포인터는 문자 자체를 가르킴에 주의해야 함
//느낀점 : 문자열을 캐릭터로, 캐릭터를 문자열로 바꾸는 거 확실히 할 것
//문제점 : 50%에서 시간 초과 -> 문자열을 삽입/삭제 식으로 구현하면 시간초과 뜸

#include <iostream>
#include <string>

using namespace std;

int T;

string inStr;
string passStr;
int pointer;

void delete_char(string str, int pointer)
{
	 //동작 검증 필요

}

void check_char(char chr)
{
	switch (chr) {
	case '<': //좌측이동인 경우, 포인터의 위치가 0 초과면 감소
		if (pointer > 0) pointer--;
		//cout << pointer << '\n';
		break;

	case '>': //우측이동인 경우
		if (pointer < passStr.size()) pointer++; 
		//cout << pointer << '\n';
		break; //포인터의 위치가 passStr 사이즈 미만이면 증가
	case '-': //BS인 경우
		if (pointer > 0) {
			passStr.erase(pointer - 1, 1);
			pointer--;
		}
		//cout << pointer << '\n';
		break;
	default: //알파벳인 경우
		passStr.insert(pointer,1,chr);
		pointer++;
		//cout << pointer << '\n';
	}
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> inStr; //입력 문자열 받기
		passStr.clear(); //패스워드 문자열 초기화
		pointer = 0;

		for (int j = 0; j < inStr.size(); ++j) { // 입력 문자열 처음부터 끝까지 탐색
			check_char(inStr[j]); //한자씩 체크
		}
	
		cout << passStr<< '\n';
	}
}