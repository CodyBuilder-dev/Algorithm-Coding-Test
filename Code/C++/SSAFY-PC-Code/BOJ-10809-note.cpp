//제목 : 알파벳 찾기
//의도 : check list 활용을 한번 해보세요 라는 의미 ㅎ
//아이디어 : checklist 만들고, a=0, b=1, ....z = 25에 대응시켜야 함
//이를 위해서는 map을 만들 수도 있고, 아니면 ascii code에 대응시킬 수도 있음
//아스키 코드 상으로는 a = 97 z = 122
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int a[26];
	memset(a, -1, sizeof(a)); //배열 0,-1로 초기화할때 쓸 수 있음
	//배열이 char 타입이면 아무 값으로나 초기화할 수 있음

	string str;

	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (a[str[i] - 97] == -1) a[str[i] - 97] = i;
	}
	for (int i = 0; i < 26; ++i) cout << a[i] << ' ';
}