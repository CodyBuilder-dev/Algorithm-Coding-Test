//���� : �Ǻ���ġ �� 2
//���� : ���� ��ȹ������ �Ǻ���ġ ���� Ǭ��
//������ : n =45���� n =90���� ��������
/*���̵�� : BOJ-2747�� �����ϰ�, �޸������̼� ���� �ȴ�
�׷��� ������ ���� n<=90�̹Ƿ�, int ������ ���� ����Ƿ� ������Ÿ���� �ٲ�� �Ѵ�.
*/
//������ : ������ n =90�� ��쿡�� long long���ε� ���ڶ�
#include <iostream>

using namespace std;

//���� �Ǻ���ġ array

long long fiboarray[45] = { 0 };

long long fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		if (fiboarray[n] != 0) return fiboarray[n];
		else
		{
			fiboarray[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return fiboarray[n];
		}
	}
}
int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n);
	return 0;
}
