//���� : �����
//���� : �ݹݸ� �߶� ���ϴ� ���� �����

/*
���̵�� : ��� �ڿ��� n�� 2�� �������� ������ ��Ÿ���� ����
��� : �׸���δٰ� ���� ū 2 ������ ��������
*/

/*
�ٸ���� ���̵�� :
1.�� �׸���� �Ȱ��� ǰ
2. ��ó�� pow�Ⱦ��� /2�Ἥ �ص� ��
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int X;
	cin >> X;

	int minus_cnt=0;

	for (int i= 6; i >= 0; --i)
	{
		if (pow(2, i) > X) continue;
		X -= pow(2, i);
		minus_cnt++;
	}
	cout << minus_cnt;
	return 0;
}
