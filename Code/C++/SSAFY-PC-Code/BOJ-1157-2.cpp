//제목 : 단어 공부
//목적 : 역시 checklist 사용 잘 하는지 못하는지 확인할라고
//조건 : 단어의 길이는 최대 100만


/*아이디어 : 역시 알파벳 checklist 사용이 핵심
1. 입력을 받아서
2. 한단어씩 루프 돌면서 체크리스트 삽입 끝
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int alphabet[26];

int main()
{
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 65 && str[i] <= 90) //대문자인 경우
			alphabet[str[i] - 65]++;
		else if (str[i] >= 97 && str[i] <= 122) //소문자인 경우
			alphabet[str[i] - 97]++;

	}

	int max = -987654321;
	char maxidx;
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] > max) {
			maxidx = i; max = alphabet[i];
		}
	}

	bool isDuplicated = false;
	for (int i = 0; i < 26; ++i)
	{
		if (i == maxidx) continue;
		if (alphabet[i] == max) isDuplicated = true;
	}
	//생각해보니 그냥 for문 2번 돌면 됨 ㅋㅋㅋㅋ개이득

	if (isDuplicated) cout << '?';
	else printf("%c",maxidx+65);
}