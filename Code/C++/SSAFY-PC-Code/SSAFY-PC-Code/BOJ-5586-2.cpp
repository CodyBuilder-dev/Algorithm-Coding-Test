//제목 : JOI와 IOI
//목적 : 특정 문자열(JOI,IOI)가 연속으로 오는거 찾기
//조건 : 문자열 길이는 최대 10000

/*아이디어 2 : 실시간 플래그 탐색
1 한개씩 받기
2.받아서 J나 I면 플래그 on
3.플래그 켜진동안 탐색
4.플래그 켜진 상태에서 OI 들어오면 +1후 플래그 끄기

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int joi = 0, ioi = 0;

}