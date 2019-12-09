//���� : �����̿� ģ����
//���� : �������̺� �ɾ� ��Ģ�� ���� �������� ������ �� �� ���� Ƚ��

/*���̵�� : �̰� �׳� �迭���°� �´�
1. �� �ε����� ������� ����
2. �迭�� ���� �� ���� Ƚ���� ����
3. ��Ģ�� ���� �迭 ���� �ø���
*/

/*����
1. Ȧ���� ���� ���������� ���� ��� : �ε��� L��ŭ ����
i+L > N-1�� ��� ���̸�ŭ 0���� ����
2. ¦���� ���� �������� ���� ��� : �ε��� L��ŭ ����
i-L < 0�� ��� ���̸�ŭ N-1���� ����
*/

//������ : ���� �ε��� ����� ��¥ ���ϴ±���...  ���� ������ �� �ֵ��� �׷����鼭 ����

#include <iostream>

using namespace std;

int N, M, L;
int *people;
int total;

void pass_ball(int ball)
{
	while (1)
	{
		for (int i = 0; i < N; ++i)
			if (people[i] == M) return;

		if (people[ball] % 2 == 0) //¦��, ����
		{
			if (ball < L) ball = N - (L - ball);
			else ball = ball - L;
			people[ball]++;
			total++;
		}
		else //Ȧ��, ������
		{
			if (ball > N - L - 1) ball = ball + L - N;
			else ball = ball + L;
			people[ball]++;
			total++;
		}
	}
}
int main()
{
	cin >> N >> M >> L;
	people = new int[N]();
	int ball = 0;
	people[ball] += 1;
	pass_ball(ball);
	cout << total;
}