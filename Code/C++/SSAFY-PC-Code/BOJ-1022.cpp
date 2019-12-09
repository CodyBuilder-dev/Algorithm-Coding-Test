//���� : �ҿ뵹�� ���ڰ� ����ϱ�
//���� : ������ ĭ�� ���ڸ� �ҿ뵹�� ��Ģ�� ���� ä������ �� ���
//���� : ������ ũ��� �ִ� �ִ� 10000x10000. �׷��� ���� ĭ�� �ִ� 49x4

/*���̵�� : 
1. �켱 ���̸� �ҿ뵹�� ������� ä���
-> '����'�� 2�����迭�� �����ϸ� ��
-> �ҿ뵹�̴�...1���� �ö󰡴� ������ ������ ������ �ִ´�
2. �ҿ뵹�� ���� ���
�ҿ뵹�̰� �� �׸� ĭ�� �ȿ������� 1^2, 3^2, 5^2, 7^2...
n��° �簢���� �׵θ��� �� ������
���� = (2n-1)^2-(2n-3)^2
���� = (2n-3)^2 + 1 ~ (2n-1)^2
�簢�� ��ǥ�� ���� = (-n,-n)~(n,n)
��Ģ =(n,n)��ǥ���� �׻� �� �簢�� �ִ� ���� ��
-> �Ųٷ� ���ư��鼭 �׸��� ����?
*/

/*���� :
1. �켱 �ǿ��� 10^4x10^4 �� �׸�
2. �������� �־��� ���� ã�Ƽ� ���
*/

#include <iostream>

#define ZERO 5000 //�߽��� �Ǵ� ���� ��ũ�η� ����

using namespace std;

int r1, c1, r2, c2;

int board[10001][10001];

void input()
{
	cin >> r1 >> c1 >> r2 >> c2;
}

void print_vortex()
{
	for (int i = ZERO+r1; i < ZERO+r2; ++i) {
		for (int j = ZERO+c1; j < ZERO+c2; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}
void fill_board()
{
	board[ZERO][ZERO] = 1;
	for (int k = 1; k < 5000; ++k) {
		int maxNum = (2 * k - 1) * (2 * k - 1);
		int maxCoord = ZERO + k;
		board[maxCoord][maxCoord] = maxNum;
		for (int n = 0; n < 4; ++n) { //4���� �� �׸���
			for (int l = 1; l <= 2 * k; ++l) {
				switch (n) {
				case 0:
					board[maxCoord][maxCoord - l] = maxNum - l; break; //break? continue?
				case 1:
					board[maxCoord - l][maxCoord - 2 * k] = maxNum - 2 * k - l; break;
				case 2:
					board[maxCoord - 2 * k][maxCoord - 2 * k + l] = maxNum - 2 * k - 2 * k - l;  break;
				case 3:
					board[maxCoord - 2 * k + l][maxCoord] = maxNum - 2 * k - 2 * k - 2 * k - l;	break;
				}
			}
		}
	}
}
int main()
{
	input();
	fill_board();
	print_vortex();
}