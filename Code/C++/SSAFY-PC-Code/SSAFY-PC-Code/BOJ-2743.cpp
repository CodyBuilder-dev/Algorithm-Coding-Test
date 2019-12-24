//제목 : 단어 길이 재기
//목적 : 단어를 받아 단어의 길이를 재라
//조건 : 길이는 최대 100

/*아이디어 :
1. 직접 세어 본다
2. 패키지를 쓴다
3. 아예 문자열을 안 받아 본다.
*/

#include <iostream>

using namespace std;

int main()
{
	char temp;
	int len = 0;
	while (cin >> temp){
		len++;
	}
	cout << len;
}