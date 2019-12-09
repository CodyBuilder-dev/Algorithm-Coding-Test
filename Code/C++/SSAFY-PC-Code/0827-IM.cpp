//���� : �簢�� ĥ�ϱ�
//���� : �簢�� �� ĥ�ϰ�, ���������� ���� ���
//���� : �� ��Ӱ� ��ĥ�� ����, �� ��Դ� �Ұ���. �簢���� �ִ� 100x100
//���� : ���� �׸��� ��,���� 0���� ���� ����

/*
���̵�� : �׳� �ݺ��� ���� �� ���������� ��ü ���鼭 �迭�� ������ ��
*/

#include <iostream>

using namespace std;

int T;
int N, M, K;

int **board;
int left_x, left_y, right_x, right_y;

int color;
int *color_cnt;
int check = 0;

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N >> M >> K;

		board = new int*[N];
		for (int j = 0; j < N; ++j)
			board[j] = new int[M]();

		color_cnt = new int[11]();

		//��ĥ�ϱ�
		for (int j = 1; j <= K; ++j) {
			cin >> left_y >> left_x >> right_y >> right_x >> color;

			for (int ii = left_y; ii <= right_y; ++ii)
				for (int jj = left_x; jj <= right_x; ++jj)
					if (board[ii][jj] > color) check = 1;
			
			if (check != 1) {
				for (int ii = left_y; ii <= right_y; ++ii)
					for (int jj = left_x; jj <= right_x; ++jj)
						board[ii][jj] = color;
				
			}
			check = 0;
		}

		//���� ���� ����
		for (int ii = 0; ii < N; ++ii)
			for (int jj = 0; jj < M; ++jj) {
				int idx = board[ii][jj];
				color_cnt[idx]++;
			}

		int max = 0;
		for (int j = 0; j < 11; ++j) {
			if (max < color_cnt[j]) max = color_cnt[j];
		}


		//���� ���������� �ִ밪 ���
		cout << '#' << i << ' ' << max << '\n';
		delete[] color_cnt;

		for (int j = 0; j < N; ++j)
			delete[] board[j];
		delete[] board;
	}


	return 0;

}