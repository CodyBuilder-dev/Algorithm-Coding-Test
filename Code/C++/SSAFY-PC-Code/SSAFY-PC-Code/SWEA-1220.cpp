//제목 : Magnetic
//목적 : 자기장을 걸었을 때 자성체들의 움직임 결과 교착상태 개수 파악
//유형 : 시뮬레이션
//조건 : 테이블 크기 100x100 고정.테이블의 상태가 입력으로 제공
//1= N, 2=S 즉1 은 밑으로 2는 위로

/*
아이디어 : 
1.우선 규칙대로 움직이고, 교착상태에 빠지면 정지하도록 코딩
1.1 원자소멸이랑 비슷하게, time이 1씩 증가할 때 마다 움직이도록
1.2 만약 인접행렬에 존재할 경우 정지
1.3 보드가 작으므로 보드를 그려도 됨. time은 최대 0-100
2.최종적으로 교2착상태의 개수를 세는 아이디어가 필요
2.1 열마다 1개씩 세므로, 2차원배열을 그린 후 1개씩 체크
*/
/*구현
1. 시간복잡도 파악 : 10000칸을 100번동안 그리므로 10^4*10^2 = 10^6

*/
#include <iostream>

using namespace std;
int T = 10;
int N;

int **board;


void move(int y, int x) //y,x좌표 받아 이동방향 결정하는 함수
{
	//배열 바깥으로 나가는 경우에 주의
	if (board[y][x] == 1) { //N자성체 동작
		if (y == N - 1) board[y][x] = 0;
		else if (board[y+1][x] == 0) {
			swap(board[y][x], board[y+1][x]);
		}
	}
	else if (board[y][x] == 2) { //S자성체 
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