//제목 : 만취한 상범
//목적 : 게임이 끝난 후 감옥문이 얼마나 열려있는가

/*아이디어 : 사실 브루트포스로 해도 됨
*/

#include <iostream>

using namespace std;

int T;
int n;
bool* door; //true면 잠김, false면 열림

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> n;
		door = new bool[n + 1]();
		door[0] = true;
		for (int cnt = 2; cnt <= n; ++cnt)
		{
			for (int j = cnt; j <= n; j += cnt)
				door[j] = (door[j]) ? false : true;
		}
		int sum = 0;
		for (int j = 1; j <= n; ++j)
			if (door[j] == false) sum++;

		cout << sum << '\n';
	}
}