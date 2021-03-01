//제목 : 유학 금지
//목적 : 문자열 내에서 특정 알파벳을 지우기
//조건 : 문자열의 길이는 최대 100

/*아이디어 : 'str'내에서 'char'찾기
1. CAMBRIDGE 문자열의 알파벳들 배열에 저장
2. 문자열을 받으면, 배열에 저장된 것과 한글자씩 비교
3. 비교해서 같으면 제거
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string cambridge = "CAMBRIDGE";
	string inStr, outStr;

	cin >> inStr;

	for (int i = 0; i < inStr.length(); ++i)
	{
		if (find(cambridge.begin(), cambridge.end(), inStr[i]) != cambridge.end())
			continue;
		outStr.push_back(inStr[i]);
	}
	
	cout << outStr;

	return 0;

}