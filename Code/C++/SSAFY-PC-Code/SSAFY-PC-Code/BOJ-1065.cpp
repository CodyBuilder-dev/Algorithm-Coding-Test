//���� : �Ѽ�
//���� : N���� ���� �Ѽ��� ����
//���� : N�� 1000����.

/*�������� : �Ѽ���
ABC�� ���� ��, B-A = C-B�� ��
���̵�� : �Ѽ��� ����
1. ���ڸ� �޴°� �ƴ϶� �����ؾ� �ϹǷ�, 10���� �ڸ����� �ڸ��� ��� �ʿ�
2. �� �ڸ����� �迭�� �����Ѵ�.
3. �迭�� ó������ ���鼭 �� �ڸ����� ���Ѵ�.
4. ���̰� �ٸ��� �ٷ� Ż��, ������ ��� ����
5. �Ѽ��� cnt++;
6. �ݺ�
*/

/*���� : 
1. 10������ �ڸ����� ���� �����... �׳�/10,%10 ����
*/

//������ : 10������ �ٷ궧�� �ڸ����� ����
#include <iostream>

using namespace std;

int numarray[4] = { 0, };

void divide_decimal(int num)
{
	//�������� for�� ¥��
	int first;
	int decimal = 0;

	while (num != 0 || decimal<4)
	{
		first = num % 10;
		num = num / 10;
		numarray[decimal] = first;
		decimal+=1;

	}
}

int check_num(int decimal)
{
	int temp;
	int sub;
	if (decimal>=1)
	{
		sub = numarray[0] - numarray[1];
	}
	int hansu =1;
	for (int i = 0; i < decimal; ++i)
	{
		temp = numarray[i] - numarray[i + 1];
		if (temp != sub)
		{
			hansu = 0;
			break;
		}
	}
	return	hansu;
}
int main()
{
	int N;
	int cnt=0;
	cin >> N;

	
	for (int i = 1; i <= N; ++i)
	{
		if (i < 10) cnt++;
		else if (i < 100) {
			divide_decimal(i);
			check_num(1);
			if (check_num(1)) cnt++;
		}
		else if (i < 1000) {
			divide_decimal(i);
			check_num(2);
			if (check_num(2)) cnt++;
		}
		else {
			divide_decimal(i);
			check_num(3);
			if (check_num(3)) cnt++;
		}

		
	}
	cout << cnt;


}