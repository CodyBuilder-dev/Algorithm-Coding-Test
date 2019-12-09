//제목 : 공
//목적 : 컵들을 이리저리 움직인 후, 최종적으로 공이 든 컵의 위치를 구하라
//조건 : 공의 위치는 고정되어 있으므로, 그냥 컵만 바꾸면 됨

/*아이디어2 : 공이 있는 컵의 움직임이 아닌 다른 컵은 신경도 안 써도 됨
1. 두 컵 번호를 각각 정수로 입력 받기
2. 받은 정수 중 현재 공 컵 번호가 있으면, 공 컵 번호를 새로 교체
3. 없으면 그냥 무시
*/

#include <iostream>

using namespace std;

int main()
{
	int M;
	cin >> M;
	
	int ball = 1;
	
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		if (a == ball) ball = b;
		else if (b == ball) ball = a;
	}
	cout << ball;
}