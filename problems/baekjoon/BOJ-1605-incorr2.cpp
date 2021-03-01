//제목 : 반복 부분문자열
//목적 : 2번이상 반복되는 부분문자열 구하기
//조건 : 문자열의 길이는 최대 200,000

/*아이디어2 :
앞에서 N^3을 백트래킹 해봤자 쓸모 없음. 아예 다른 접근방법
1. 백트래킹은 유지
2. KMP써서 최적화
3. 
*/

//문제점 : 라빈-카프와 KMP는 완전히 다름
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findPi(string str)
{
	int len = str.size();
	int maxPi = 0;
	for (int prelen = 1; prelen < len; ++prelen) {
		string prefix = str.substr(0, prelen);
		string suffix = str.substr(len - prelen, prelen);
		if (prefix.compare(suffix) == 0)
			maxPi = prelen;
	}
	return maxPi;
}

bool KMP(string str, string pattern)
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
			//백트래킹 - 존재하는 경우
			if (find(usedString.begin(), usedString.end(), tempText) != usedString.end())
				continue;
			//존재하지 않는 경우
			usedString.push_back(tempText);

			//현재번지의 다음 번지부터 탐색. KMP 적용
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