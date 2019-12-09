//제목 : 행복한지 슬픈지
//목적 : 이모티콘 :-)와 :-(의 개수에 따라 감정을 비교해주는 프로그램을 작성한다.
//조건 : 문자메시지는 최대 255자. 반드시 :-)의 형태로 지켜야 함

/*아이디어 : 
1. 공백이 포함된 문자열을 한번에 받을 수 있는가
2. 문자열에서 여러 가지의 패턴을 탐색할 수 있는가
*/

/* 구현 : 
1. 우선 :-) :-( 저장해두기
2. substr로 비교하기
*/

/*느낀점 : 
1.문자열과 공백의 관계 확실히 정리하고 갈 필요가 있음
2.substr보다 원문 길이가 짧은 경우 에러처리 필요
*/
#include <iostream>
#include <string>

using namespace std;

string txt;
string sad = ":-(";
string happy = ":-)";
int mood; //happy면 양수, sad면 음수
bool isExist;

int main()
{
	getline(cin, txt);

	if (txt.length() >= 2) {
		for (int i = 0; i < txt.length() - 2; ++i)
		{
			if (txt[i] == ':') {
				if (txt.substr(i, 3).compare(sad) == 0)
				{
					mood--;
					isExist = true;
				}
				else if (txt.substr(i, 3).compare(happy) == 0)
				{
					mood++;
					isExist = true;
				}
			}
		}
	}
	if (isExist)
		printf("%s", (mood > 0) ? "happy" : (mood == 0) ? "unsure" : "sad");
	else
		cout << "none";
}



