//���� : ������
//���� : ������ ���� �ƴ°���������

/*���� : �׳� �ϸ� �ʹ� �����, ���������� �ɾ��
1. cin.tie(NULL) ����
2. std �� ����
3.���ð���)�޸� ���� ����
*/
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	
	int total;
	std::cin >> total;
	int temp;
	for (int i = 0; i < 9; ++i) {
		std::cin >> temp;
		total -= temp;
	}
	std::cout << total;
}