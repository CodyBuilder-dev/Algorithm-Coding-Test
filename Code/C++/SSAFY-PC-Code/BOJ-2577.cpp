//���� : ������ ����
//���� : 
//���� : A�� �ִ� 10^3, ��ABC�� �ִ� 10^9�̹Ƿ�... int �ᵵ��

/*���̵�� : ���̵����ü�� ���, �� �ٸ��� Ǯ��� ����
1. �迭�� �����Ҵ� ���� ��, ������ ���� ���ΰ� �����ϴ� ��
2. -1�� �ʱ�ȭ�س���, -1�� �����ϸ� �׸��δ� ���?!
*/
#include <iostream>

using namespace std;

int numArray[10];
int decimalArray[10];

void devide_decimal(int num)
{
	int first;
	int decimal = 0;
	while (num != 0) {
		first = num % 10;
		num = num / 10;
		numArray[decimal] = first;
		decimal++;
	}
}

void check_decimal()
{
	int i = 0;
	while (numArray[i] != -1)
	{
		decimalArray[numArray[i]]++;
		++i;
	}
}
int main()
{
	int A, B, C;

	cin >> A >> B >> C;
	
	//-1�� �ʱ�ȭ
	for (int i = 0; i < 10; ++i)
		numArray[i] = -1;

	int result = A * B * C;
	devide_decimal(result);
	check_decimal();
	for (int i = 0; i < 10; ++i)
		cout << decimalArray[i] << '\n';
}