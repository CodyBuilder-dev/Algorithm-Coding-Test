//���� : N�� M
//���� : nPm ���� ����ϱ�
//���� : N�� M�� �ſ� �����Ƿ� �׳� �� ���ص� ��
//8! = 4��
/*
���̵�� : ������ ����ϴ� ���̹Ƿ� ���� �� �ؾ� ��
�����̶� ������ Ʈ��. ��
*/

#include <iostream>

using namespace std;

void print_permutation(int n, int m)
{
	if (m == 1) {
		printf("%d ", n); return;
	}
	print_permutation(n, m - 1);
	print_permutation(n - 1, m - 1);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	print_permutation(N, M);

}