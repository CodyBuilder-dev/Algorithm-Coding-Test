//���� : ������ ���
//���� : ������ ���� �� �������� �󸶳� �����ִ°�

/*���̵�� : ��� ���Ʈ������ �ص� ��
*/

#include <iostream>

using namespace std;

int T;
int n;
bool* door; //true�� ���, false�� ����

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