//���� : 01Ÿ��
//��ǥ : 00, 1 �ΰ��� Ÿ���� ���� ��, �� Ÿ�Ϸ� ���� �� �ִ� ���̰� N�� ��� ����� ��
//���� : N�� �ִ� 100��

/*���̵�� :
�����غ��� �ᱹ �������� �ִ� ���� ����� �ؾ���
�ٵ� �������� �ִ� �������� ���丮���� ��
�� ���丮�� ����� �� �ؾߵǴµ�
�˴ٽ��� ��ͷ� �ϸ� �̳� �����ɸ��� �ڷ� Ŀ��
N = 1,000,000�̸�, k = 500,000���� �� ���� �ְ� �̷� 500000!�� ��������...

�Ӹ������� ���� ���� �� ���� ���� 500,000! �ȱ��ص� ��
*/

long long factorial_array[1000001] = { 0 };

long long factorial(long long a)
{
	if (a == 1) return 1;
	else
	{
		if (factorial_array[a] != 0)
			return factorial_array[a];
		else {
			factorial_array[a] = a * factorial(a - 1);
			return factorial_array[a];
		}
	}
}
#include <iostream>

using namespace std;

int main()
{
	long long N;

	cin >> N;
	cout << factorial(N) % 15746;
	
}