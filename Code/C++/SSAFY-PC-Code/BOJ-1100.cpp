//���� : �Ͼ� ĭ
//���� : ü���ǿ��� �Ͼ�ĭ ���� ���� ���� ������ ���ϱ�
//���� : ���� ���� �� ĭ���� ����. ü������ 8x8

/*���̵�� : char�� 2�����迭�� Ž���� �� �ִ°�
1. char 2�����迭 ����
2. Ư�� �ε����� ��� �˻� �� ���� üũ
*/

/*���� : ��� �ε����� �˾Ƴ��� ��
1. (0,0)~(7,7)����
2. �� �ε����� ���� ¦���� ���, Ȧ���� ������

or
1. 0~63����
2.
*/

//������ : 
#include <iostream>

using namespace std;

char chessboard[8][8];

int main()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> chessboard[i][j];
			//scanf("%c", &chessboard[i][j]);

	int cnt = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			if ((i + j) % 2 == 0)
			{
				if (chessboard[i][j] == 'F') cnt++;
			}
		}

	cout << cnt;
}