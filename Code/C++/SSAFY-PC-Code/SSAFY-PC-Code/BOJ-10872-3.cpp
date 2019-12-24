//제목 : 팩토리얼
//목적 : 숫자 크기에 따른 팩토리얼을 어떻게 구현할지 안다
//조건 : 12까지이므로 12! = 4억이므로 데이터타입 바꿀 필요없음
/*아이디어 : 그냥 재귀로 구하면 무조건 터지는듯. 동적계획법 써 줘야 풀림.
바텀업 방식으로 풀어보겠음
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int factorial[13] = { 1 };
	cin >> N;

	if (N == 0) cout << factorial[0];

	else {
		for (int i = 1; i <= N; ++i)
			factorial[i] = i * factorial[i - 1];
	}
	cout << factorial[N];
}