//제목 : Africa
//목적 : 지문을 읽고, 입력 데이터이름에 대해 결과를 출력하라
//입력 : 입력은 8개인데, 다 아프리카 나라 이름이다
//출력 : 단 하나의 숫자이다
/*아이디어 :
1. 국가 이름에 대해 대응되는 숫자의 연결관계 찾기
2. 모든 정보는 다 지문내에 있다고 하는데...과연

1. 다 읽기 귀찮고 ^F로 찾아서 해당 문단의 숫자 다 크롤링
2. 이거 경로별 비자 발급 비용이네 ㅋㅋ
*/
/*구현 : 맵 써서 대응시키고 입력 받아서 비교 및 계산

*/

//보츠와나 0
//에티오피아, 50
//케냐,50,100
//나미비아 40,140
//남아공 0
//탄자니아 50 ,100

//잠비아 50,80
//짐바브웨 30,45, 50

#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<string, int> visa;
	visa["botswana"] = 0;
	visa["ethiopia"] = 50;
	visa["kenya"] = 100;
	visa["namibia"] = 40;
	visa["south-africa"] = 0;
	visa["tanzania"]= 50;
	visa["zambia"];
	visa["zimbabwe"];

	int N;
	cin >> N;
	
	string *nation;
	nation = new string[N];

}