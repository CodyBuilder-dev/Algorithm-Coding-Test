//���� : ���� ����
//���� : ������ ���� �ּҰ�
//���� : ������� �����ڿ� �������� ���� 10^6�̹Ƿ� ��� ���� ����
//���� : ������ ���� int ���� ��������, �� ���� ���� int ������ �ʰ��� �� �ִ�.

/*���̵�� :
�������� ���� �׳� �������� ����ϸ� ���� �ʳ�
�Ѱ������� �� �־�� �ȴٴ� ���� ����?

case 1 : B>C�̸� �� ���� 1+(A-B)/C
case 2 : B<C�̸� �� �ʿ� ���� A/C

�̶� �����ϱ� �Ҽ��� ó�� ����.

995/100 =9
*/

/*���̵�� 2 :
���̽��� ���� �Ѱ������� �ݵ�� �־�� ��

case 1 : A<=B�̸� 1
case 2 : C>A>B�̸� A-B/C �Ҽ�
case 3 : A>B>C�̸� A-B/C ����

5-2/10 = 0,3
10-2/3 = 2,2
*/

#include <iostream>

using namespace std;

int main()
{
	int N, B, C;
	int *A;
	
	int cnt;
	long long sum=0;
	
	cin >> N;

	A = new int[N];
	for (int i = 0; i < N; ++i) cin >> A[i];
	
	cin >> B >> C;
	
	for (int i = 0; i < N; ++i)
	{
		if (A[i] <= B) cnt = 1;
		else {
			if ((A[i] - B) % C == 0) cnt = 1 + (A[i] - B) / C;
			else cnt = 2 + (A[i] - B) / C;
		}

		sum += cnt;
	}
	cout << sum;

	return 0;
}

