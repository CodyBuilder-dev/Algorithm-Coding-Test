//���� : ��� �� �Ķ��̵� ��
//���� : ��� X����, �Ķ��̵� Y������ �� �� ���� ���� �������� ��� ��
//���� : ������ ���� �ִ� 5õ��, �������� �ִ� 10���������� ����

/*���̵�� : ��Ž���� �� Ǯ���ϱ� �̰� ���������� �����ؾ� ��
1. ���� ���+�Ķ��̵� > 2*�ݹ��̸� ��� �Ķ��̵� ��°� �̵�
2. ���� ���+�Ķ��̵� < 2*�ݹ��̸� �ݹ� ��°� �̵�
3. �ݹ� ��� ���ڶ�� ������ ���

4. ���� ��� >�ݹ�, �Ķ��̵�>�ݹ��̸� �������ٵ� �ݹ� ��°� �̵�
*/

//���� �� : �������� ������ ��Ž�� �⺻������, �� ���� ������ �� ���� ������ ���� ������ ��
//���п��� �� ���� ���踦 ��� ��Ȯ�� Ž���� ��

#include <iostream>

using namespace std;

int A, B, C, X, Y;
int cost;
int main()
{
	cin >> A >> B >> C >> X >> Y;

	int set = (X > Y) ? Y : X;
	int xdiff = (X > Y) ? X - Y : 0;
	int ydiff = (X > Y) ? 0 : Y-X;

	if (A + B >= C*2) { //�ݹ� �ΰ��� �� �� ���
		if (A > 2*C && B > 2*C) { // �ݹ� �ΰ��� ��亸�� �� ���
			cost = set * 2 * C + xdiff * 2*C + ydiff * 2*C;
		}

		else if (A < 2*C) { // B>C>A
			cost = set * 2 * C + xdiff * A + ydiff * 2*C;
		}
		else if (B < 2*C) { //A>B>C
			cost = set * 2*C + xdiff * 2*C + ydiff * B;
		}
		
	}

	else {
		if (A < 2 * C) { // B>C>A
			cost = set * (A+B) + xdiff * A + ydiff * 2*C;
		}
		else if (B < 2 * C) { //A>B>C
			cost = set * (A+B) + xdiff * 2*C + ydiff * B;
		}
		else if (A < 2 * C && B < 2 * C) {
			cost = set * (A + B) + xdiff * A + ydiff * B;
		}
	}

	cout << cost;
}