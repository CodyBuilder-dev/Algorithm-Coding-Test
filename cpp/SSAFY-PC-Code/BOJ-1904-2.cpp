//���� : 01Ÿ��
//��ǥ : 00, 1 �ΰ��� Ÿ���� ���� ��, �� Ÿ�Ϸ� ���� �� �ִ� ���̰� N�� ��� ����� ��
//���� : N�� �ִ� 100��

/*���̵�� 2 :
���丮��� �ȵǰڴ�. ��ȭ���� ã���� �ȴ� ��
���丮��  �� ��ü�� �ƴ϶�, ���丮���� ���� �и� ���͵� ��ȭ�� ����

N = 2k�϶�, O(0) = 1 = k!/k!
O(1) = O(0) * k+1*k/(1*2)
O(2) = O(1) * 
O(l+1) = (k+l)!/(k-l)!2l! = O(l) * k+l * k - l /(2l) /(2l-1)

N = 2k+1�϶�
O(l+1) = O(l) * (k+l) * (k - l +1 )/ (2l+1) / (2l)
*/
#include <iostream>

using namespace std;

long long factorial_array[1000001] = { 0 };

long long factorial(long long k)
{
	if (k == 1) return 1;
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

int main()
{
	long long N;

	cin >> N;
	cout << factorial(N) % 15746;

}