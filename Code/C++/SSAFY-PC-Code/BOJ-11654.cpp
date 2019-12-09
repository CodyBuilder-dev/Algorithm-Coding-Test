//제목 : 아스키 코드
//목적 : c++에서 Char과 아스키 코드의 표현이 어떻게 되는지 확인하기
//개념정리 : C언어 메모리와 문자, 문자열의 개념 정리
//unsigned의 개념도 확실히 정리
//의의 : 메모리에서 어떻게 저장되는지 확실히 이해하면, 굳이 if문 나눌 필요가 없음

#include <iostream>

using namespace std;

int main() {
	unsigned char A;
	cin >> A;
	cout << (int)A;
	return 0;
}
