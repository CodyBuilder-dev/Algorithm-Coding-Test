//���� : ��ٳ���
//���� : ���� + ���� ��Ʈ �� ���� ������ ���� ����
//���� : �� ������ 100~2000��
/*���̵��:
1. ������ ��� �޾� ������ �� ���Ʈ ����
or �ƴϸ� �׳� ���������� min�Լ��� �̿��� min�� ���
2. ���⼱ min�Լ��� �̿��غ���
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int burger;
	int drink;
	int burgerMin=2000, drinkMin=2000;

	for (int i = 0; i < 3; ++i)
	{
		cin >> burger;
		burgerMin = min(burger, burgerMin);
	}

	for (int i = 0; i < 2; ++i)
	{
		cin >> drink;
		drinkMin = min(drink,drinkMin);
	}
	
	cout << burgerMin + drinkMin - 50;
}