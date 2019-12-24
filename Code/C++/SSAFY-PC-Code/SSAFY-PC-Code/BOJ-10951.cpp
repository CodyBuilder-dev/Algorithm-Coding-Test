//제목 : A+B - 4
//목적 : A와 B를 입력받되, 종료 선언 없이 입력이 끝나면 종료되도록 하기
//조건 : A와 B는 1자리 정수

#include <iostream>

using namespace std;

int main()
{
	//cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b;
	while (cin >> a >> b)
	{
		cout << a + b << '\n';
	}
}