//���� : ������
//���� : ��¦�� ����� ���� ��/���� ������ �Ǵ��� ���������� ����

/*���̵�� : �ʹ� ����. �׳� ���ϸ� ���ݾ�. ������ ����
*/

#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	int yoot[4];
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d %d %d", &yoot[0], &yoot[1], &yoot[2], &yoot[3]);
		switch (accumulate(yoot, yoot + 4, 0))
		{
		case 0: cout << 'D' <<'\n'; break;
		case 1: cout << 'C' << '\n'; break;
		case 2: cout << 'B' << '\n'; break;
		case 3: cout << 'A' << '\n'; break;
		case 4: cout << 'E' << '\n'; break;
		}
	}
		
}