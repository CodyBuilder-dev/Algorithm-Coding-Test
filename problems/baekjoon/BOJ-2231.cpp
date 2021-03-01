//���� : ������
//���� : ���Ʈ ������ ���� ������ ���ϱ�
//���̵�� : �������� ���ϴ°� ������ �����ڸ� ���ϴ°� ��ƴ�
//�������� �������� Ǯ�� �Ӹ����µ� �ڵ����δ� ���� �� ����
//�ڵ����ε� �׳� ��� ����� �� �� ���ϸ� �Ӹ� �����µ�, ������ ���� �� ����
// abc�� �������� abc+a+b+c��. �ٵ� abc�� ���ڸ����̹Ƿ� 
// abc+a+b+c < abc+10+10+10 �� 30��
// �� � n�ڸ����� �������� �ƹ��� Ŀ���� <n�ڸ���+10*n��
// �ݴ�� � ���� �����ڴ� �ƹ��� �۾ƺ��� ������-10*n��

//�� ���ڸ��� ���ڸ� �� Ŀ���� ���� ���� �� �غ�������, �ϴ� ���� ���
//�α� ���غ��߰ڳ� ����

#include <iostream>
#include <cmath>
using namespace std;
int find_decomp(int construct)
{
	if (construct < 1) return 0;
	return construct % 10 + find_decomp(construct / 10);

}
int main() {
	int N;
	int order;
	int i;
	cin >> N;
	order = log10(N) + 1;

	for (i = N - 10 * order; i < N; i++)
	{
		if ((i+find_decomp(i)) == N)
		{
			cout << i;
			break;
		}
	}
	if (i == N) cout << 0;
}