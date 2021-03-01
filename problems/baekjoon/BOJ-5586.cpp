//제목 : JOI와 IOI
//목적 : 특정 문자열(JOI,IOI)가 연속으로 오는거 찾기
//조건 : 문자열 길이는 최대 10000

/*아이디어 : 선 저장 후 순차 탐색
1. 문자열 통으로 받기
2. J나 I가 들어오면, 그 뒤로 연속해서 2개 더 살펴봄
3. 살펴볼떄도 플래그 켜고 보기 vs 바로 살피기
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int joi = 0, ioi = 0;

	for (int i = 0; i < str.length() - 2; ++i)
	{
		if (str.substr(i, 3).compare("JOI")==0) joi++;
		if (str.substr(i, 3).compare("IOI")==0) ioi++;
	}
	cout << joi << '\n' << ioi;
}