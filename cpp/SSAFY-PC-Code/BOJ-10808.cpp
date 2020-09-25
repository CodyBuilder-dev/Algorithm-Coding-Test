//제목 : 알파벳 개수
//목적 : 알파벳 소문자로 이루어진 단어에서 각 알파벳 개수 세기
//조건 : 길이는 최대 100

/*아이디어 : 알파벳 체크 배열을 쓸줄 아는가 묻는 문제
1. 알파벳 체크 배열 int check[26] 생성
2. 단어를 받아 순차적으로 체크
3. 시간복잡도는 O(M)
*/

#include <iostream>
#include <string>

using namespace std;

int check[26];

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		check[str[i] - 97]++;

	for (int i = 0; i < 26; ++i)
		cout << check[i] << ' ';
}