//���� : ���丮��
//���� : ���� ũ�⿡ ���� ���丮���� ��� �������� �ȴ�
//���� : 12�����̹Ƿ� 12! = 4���̹Ƿ� ������Ÿ�� �ٲ� �ʿ����
/*���̵�� : �׳� ��ͷ� ���ϸ� ������ �����µ�. ������ȹ�� �� ��� Ǯ��.
���Ҿ� ������� Ǯ�����
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