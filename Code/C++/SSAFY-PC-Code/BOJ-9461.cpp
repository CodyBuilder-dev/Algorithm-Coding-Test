//���� : �ĵ��� ����
//���� : ���������� �ﰢ���� �߰��� ��, ��Ģ ã��
//���� : �ִ� �ﰢ���� 100������ ���̱� ����

/*���̵�� : �����̹Ƿ�, ��ȭ�� ã��
1. �տ����� �𸣰ڴµ�, 5�׺��ʹ� ��Ģ ����?
->������ ������̸� 5�� ���� �͵��� ã���� ����ϰ�����
->��ǻ���� ������� �׳� 5�� ���ĺ��͸� ã�� ������
*/

#include <iostream>

using namespace std;

int N;
long long triangle[101];

int main()
{
	cin >> N;

	triangle[1] = 1;
	triangle[2] = 1;
	triangle[3] = 1;
	triangle[4] = 2;
	triangle[5] = 2;
	triangle[6] = 3;
	triangle[7] = 4;
	triangle[8] = 5;
	triangle[9] = 7;
	triangle[10] = 9;
	for (int i = 11; i <= 100; ++i)
		triangle[i] = triangle[i - 1] + triangle[i - 5];

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		cout << triangle[temp] << '\n';
	}
}