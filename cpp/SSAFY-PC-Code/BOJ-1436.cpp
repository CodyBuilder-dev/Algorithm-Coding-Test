//제목 : 영화감독 숌
//목적 : N번쨰 666이 연속로 들어가는 숫자 찾기

/*
아이디어 : 우선 666이 들어가는 10000번째 숫자의 크기를 찾자
숫자의 자릿수로 찾자
3자리 = 1개
4자리 = 19개
5자리 = ...힘듬
이거 개수를 구하려면 중복순열이네
그냥 대충 한 6~7자리 검사해보면 되겠다는 생각을 할 수는 있음
실제로 2666799로 7자리
*/

/*아이디어 2 : 그럼 실제로 666이 있는 값을 찾아보자
숫자의 중간에 원하는 패턴이 있는지 문자열화 해서 찾는 방법
*/

/*아이디어 3 : 반복횟수를 줄이는 법
1. 끝까지 돌면서 굳이 맵에 저장할 필요 없이 찾으면 바로 break
2. 어차피 시작점 아니까, 시작점은 lookup table식으로 1 = 666, 2 = 1666으로 구성
3. 끝나는 점을 파악해서 끝나는점까지만 돌도록
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;

	int maximum = 3000000;
	string numstr,substr;

	map<int, string> order;
	int cnt = 0;
	
	cin >> N;

	for (int i = 666; i <= maximum; ++i)
	{
		numstr = to_string(i);
		for (int j = numstr.size() - 3; j >= 0 ; --j)
		{
			substr = numstr.substr(j, 3);
			if (substr.compare("666") == 0)
			{
				cnt++;
				if (cnt == N) cout << i;
				break;
			}
		}
	}

}