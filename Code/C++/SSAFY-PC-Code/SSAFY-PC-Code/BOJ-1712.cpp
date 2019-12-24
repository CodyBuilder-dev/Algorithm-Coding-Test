//���� : ���ͺб���
//���� : ���ʷ� ������ �߻��ϴ� �Ǹŷ� ���ϱ�
//���� : A,B,C���� 21�� ���� -> long long�� ����� ���ɼ� ����

/*���̵�� : A + B*q < C*q ���� A/(B-C) = q
q�� �Ǽ����� �������� �Ǻ��ϱ�
*/

/*���� ��
1. long long üũ ���ϸ� ���� ��ǰ
2. int/float���� ���� ��Ȯ�� �ľ��� ��
*/
#include <iostream>

using namespace std;

long long A, B, C;
long long q;

int main()
{
	cin >> A >> B >> C;

	if (B >= C) cout << -1;
	else {
		
		q = A / (C - B) + 1;
		cout << q;
	}
}