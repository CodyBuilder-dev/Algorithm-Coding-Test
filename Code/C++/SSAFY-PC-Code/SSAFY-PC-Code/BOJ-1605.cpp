//제목 : 반복 부분문자열
//목적 : 2번이상 반복되는 부분문자열 구하기
//조건 : 문자열의 길이는 최대 200,000

/*아이디어3 :
1.라빈카프 알고리즘 고고
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int rabin(string str)
{

}
int main()
{
	int L;
	cin >> L;
	string text;
	cin >> text;
	vector<string> usedString;
	int maxLength = 0;
	for (int i = 1; i < L; ++i) //길이 i인 부분문자열
		for (int j = 0; j < L; ++j) //0번지부터 시작
		{
			bool isExist = false;
			string tempText = text.substr(j, i);
			//존재하는 경우
			if (find(usedString.begin(), usedString.end(), tempText) != usedString.end())
				continue;
			//존재하지 않는 경우
			usedString.push_back(tempText);

			//현재번지의 다음 번지부터 탐색
			for (int k = j + 1; k <= L - i; ++k)
				//같은 경우 true하고 탈출
				if (tempText.compare(text.substr(k, i)) == 0)
				{
					isExist = true;
					break;
				}
			if (isExist == true) maxLength = i;
		}
	cout << maxLength;
	return 0;
}