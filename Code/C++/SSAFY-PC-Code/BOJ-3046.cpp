//���� : R2
//���� : ������ ��� �� �����ϱ�
//���� : (�ʹ� ���� ������ ������ ����� Ǯ ��)

//���̵�� : R1+R2/2 = S �� ����

#include <iostream>

using namespace std;

int main()
{
	int R1, R2, S;

	scanf("%d%d", &R1, &S);

	R2 = 2 * S - R1;

	printf("%d", R2);
}