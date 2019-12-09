//���� : Magnetic
//���� : �ڱ����� �ɾ��� �� �ڼ�ü���� ������ ��� �������� ���� �ľ�
//���� : �ùķ��̼�
//���� : ���̺� ũ�� 100x100 ����.���̺��� ���°� �Է����� ����
//1= N, 2=S ��1 �� ������ 2�� ����

/*
���̵�� : 
1.�켱 ��Ģ��� �����̰�, �������¿� ������ �����ϵ��� �ڵ�
1.1 ���ڼҸ��̶� ����ϰ�, time�� 1�� ������ �� ���� �����̵���
1.2 ���� ������Ŀ� ������ ��� ����
1.3 ���尡 �����Ƿ� ���带 �׷��� ��. time�� �ִ� 0-100
2.���������� ��2�������� ������ ���� ���̵� �ʿ�
2.1 ������ 1���� ���Ƿ�, 2�����迭�� �׸� �� 1���� üũ
*/
/*����
1. �ð����⵵ �ľ� : 10000ĭ�� 100������ �׸��Ƿ� 10^4*10^2 = 10^6

*/
#include <iostream>

using namespace std;
int T = 10;
int N;

int **board;


void move(int y, int x) //y,x��ǥ �޾� �̵����� �����ϴ� �Լ�
{
	//�迭 �ٱ����� ������ ��쿡 ����
	if (board[y][x] == 1) { //N�ڼ�ü ����
		if (y == N - 1) board[y][x] = 0;
		else if (board[y+1][x] == 0) {
			swap(board[y][x], board[y+1][x]);
		}
	}
	else if (board[y][x] == 2) { //S�ڼ�ü 
		if (y == 0) board[y][x] = 0;
		else if (board[y-1][x] == 0) {
			swap(board[y][x], board[y-1][x]);
		}
	}
}

int main()
{
	for (int ii = 1; ii <= T; ++ii)
	{
		cin >> N;

		board = new int*[N];
		for (int i = 0; i < N; ++i)
			board[i] = new int[N];

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> board[i][j];

		int time = 0;
		while (time <= 100)
		{
			time += 1;
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					move(j, i);
		}

		int cnt = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (board[j][i] == 1) {
					if (board[j + 1][i] == 2)
						cnt++;
				}
		printf("#%d %d", ii, cnt);
	}
}