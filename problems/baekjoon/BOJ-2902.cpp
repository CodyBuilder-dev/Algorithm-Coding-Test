//제목 : KMP는 왜 KMP일까?
//목적 : 긴 형태의 문자열을 짧은 형태로 바꾼다
//조건 : 문자열 길이 100

/*아이디어 : 대소문자,-가 들어간 알고리즘의 파싱
1.길이가 짧으므로, 처음부터 순차 탐색
2.대문자면 저장, 나머지는 다 스킵.
*/

/*구현 :
1.문자열을 통으로 받은 후 파싱
2.그냥 한글자씩 받아서 담기/버리기
*/
#include <iostream>

using namespace std;

void ASCII(int a)
{
	printf("%c", a);
}
int main()
{
	//ASCII(65); 65~90이 대문자인거 확인
	char temp;
	while (cin >>temp)
	{
		if (temp >= 65 && temp <= 90) printf("%c", temp);
	}
}