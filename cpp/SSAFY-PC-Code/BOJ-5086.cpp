#include <iostream>

using namespace std;

int main()
{
	int a, b;

	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		//���̽� �з�
		//�� ���� �־�����, ���-��� ����� 3������ ������
		//if-else�� 3������ ��� ó���ϵ��� ¥�� ��

		if (a%b == 0) cout << "multiple" << '\n';
		else if (b%a == 0) cout << "factor" << '\n';
		else cout << "neither" << '\n';

	}
}