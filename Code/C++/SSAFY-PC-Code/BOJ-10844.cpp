//���� : ���� ��� ��
//���� : '��� ��'�� ���Ǹ� �����ϰ�, N�ڸ��� ��� ���� ������ ���Ͽ���
//���� : N�� �ִ� 100, ������ 10������ ���� ��

/*���̵�� : 10������ ���� �������� ����Ѵ�->������ DP
��?? �׳� �ִ� 100�ڸ��ϱ� 0�ڸ����� 100�ڸ����� ������ �Ǵ°� �ƴϳ�?
->����� ���� �̳� �����Ƿ� �ȵ�

��ȭ��? �����ҵ�
->N�ڸ��� ����� ���� ����
->N+1�ڸ��� N�ڸ� ����� ������
���� 9�� ��� �״�� 1����
���� 0�� ��� �״�� 1����
�� �ܴ� +1,-1���� 2����

�޸������̼�? �����
*/

/*������ : 
1.���� �ʹ� �پ������ 2�� ��µȴ�
2. ��ȭ���̶�°� �׷��� ���� ¥���°� �ƴ� �� �ִ�.
->��ǻ���� ������, ��� ���̽��� �� �����Ҽ� �ִٴ� ���� �̿���
���̽����� �� ������ ¥���� �� ����
*/

#include <iostream>
#define DEVIDEND 1000000000

using namespace std;
int N;
long long caseCnt[101][10];

long long find_case(int n,int last)
{
	if (n <= 0) return 0; //Ż������
	if (caseCnt[n][last] != 0) return caseCnt[n][last]; //�޸������̼� ���
	
	long long nowCase;
	if (last == 0) {
		nowCase = find_case(n - 1, 1)%DEVIDEND;
	}
	else if (last == 9) {
		nowCase = find_case(n - 1, 8)%DEVIDEND;
	}
	else {
		nowCase = (find_case(n - 1, last - 1) + find_case(n - 1, last + 1)) % DEVIDEND;
	}

	caseCnt[n][last] = nowCase;
	return nowCase;
}
int main()
{
	cin >> N;
	//1�ڸ�, 2�ڸ��� �ϵ��ڵ�
	for (int i = 1; i <= 9; ++i)
		caseCnt[1][i] = 1;
	
	//3�ڸ����ʹ� �� �ڿ� 0�� ����Ǽ��� �������� ��

	long long sum = 0;
	for (int i = 0; i <= 9; ++i)
		sum += find_case(N, i) ;

	cout << sum%DEVIDEND;
}