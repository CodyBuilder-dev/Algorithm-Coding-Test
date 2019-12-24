//제목 : 사각형 칠하기
//목적 : 사각형 다 칠하고, 최종적으로 영역 계산
//조건 : 더 어둡게 덧칠은 가능, 더 얇게는 불가능. 사각형은 최대 100x100
//주의 : 문제 그림의 행,열이 0부터 시작 주의

/*
아이디어 : 그냥 반복문 돌린 후 최종적으로 전체 돌면서 배열에 넣으면 됨
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

		//색칠하기
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

		//색깔별 넓이 검정
		for (int ii = 0; ii < N; ++ii)
			for (int jj = 0; jj < M; ++jj) {
				int idx = board[ii][jj];
				color_cnt[idx]++;
			}

		int max = 0;
		for (int j = 0; j < 11; ++j) {
			if (max < color_cnt[j]) max = color_cnt[j];
		}


		//테케 끝날때마다 최대값 출력
		cout << '#' << i << ' ' << max << '\n';
		delete[] color_cnt;

		for (int j = 0; j < N; ++j)
			delete[] board[j];
		delete[] board;
	}


	return 0;

}