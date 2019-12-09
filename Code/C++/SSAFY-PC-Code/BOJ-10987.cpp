//제목 : 모음의 개수
//목적 : 문자열에서 모음의 개수를 출력
//조건 : 문자열 길이 최대 100

/*아이디어 : 형식지정자에 정규표현식 넣어서 풀어보기

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char temp;
	int cnt = 0;
	char moum[] = { 'a','e','i','o','u' };

	while(cin >> temp)
		if (find(moum, moum + 5, temp) != moum + 5) {
			cnt++;
		}

	cout << cnt;


}