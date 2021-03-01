//제목 : 문자열 반복
//목적 : 문자열에 *연산이 될까 안될까? 안되면 어떻게 반복 출력할까요?
//결론 : *쓰면 숫자로 인식됨ㅋㅋㅋ
//아이디어 : 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	int R;
	string str;
	
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> R >> str;

		for (int j = 0; j < str.size(); ++j)
			for(int k = 1; k <= R; ++k)	cout << str[j];

		cout << '\n';
	}
}