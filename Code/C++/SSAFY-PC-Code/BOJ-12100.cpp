//제목 : 2048(easy)
//목적 : 이동 횟수가 정해져 있을때, 결과로 나올 수 있는 가장 큰 수 찾기
//조건 : 보드의 크기는 최대 20x20=400, 4방향 이동시 경우의 수는 4^5 = 1024

/*아이디어 : 동/서/남/북 각 이동별로 구현
1. 보드를 구현하거나, 블록을 구현하거나.
(이건 보드를 구현하는게 나을 듯)
2.동/서/남/북 각 이동별로 구현
(동쪽 이동시, 배열의 가장 동쪽에 존재하는 블록들부터 벽으로 붙임)
3. 벽으로 붙이면서 같은 블록이 있을 시 합쳐짐
4. 합쳐진 것은 다시 합쳐지지 않게 하려면 음...
5. 구조체의 배열로 만들어야되나
*/

/*구현 : 
1. 구조체 내부에는 현 좌표의 값, 충돌합 여부를 저장함
2. 값은 더해지고 충돌합은 True
3. 매 첫 분기에 False로 초기화됨
*/

/*느낀점 :
1.2차원 배열 보드판 위에 값 말고 다른 정보도 넣고 싶으면 구조체?
2.구조체에 통째로 swap을 해도 되는가? 가능
3.디버거(f5)를 쓰면 배열 index 에러 등을 쉽게 잡을 수 있다.
4.재귀의 깊이가 얕은 경우 for 여러개 써서 할 수도 있다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;

//보드판 블록 구현
typedef struct {
	int value;
	bool collision = false;
}BLOCK;

BLOCK **board;
BLOCK **saveBoard;
//블록 이동 함수 구현
void move_block(int dir)
{
	switch (dir)
	{
	case 0: //동쪽으로 이동
		for (int i = 0; i < N; ++i)
			for (int j = N - 1; j >= 0; --j){
				if (j == N - 1) continue;
				int k = j;
				//막히기 전까지 오른쪽으로 쭉쭉 전진
				while ((k < N - 1) && (board[i][k + 1].value == 0)){
					swap(board[i][k + 1], board[i][k]);	
					k++;
				}
				if (k == N - 1) continue;//충돌없이 끝까지 도달했을 경우 
				//막혔을 경우, 막힌 칸의 다음칸과 같은지 확인
				if ((board[i][k].value == board[i][k + 1].value)
					&&(board[i][k+1].collision == false))
				{
					board[i][k + 1].value *= 2;
					board[i][k + 1].collision = true; //같을 경우 값을 2배로 늘리고, 충돌 true
					board[i][k].value = 0;
					board[i][k].collision = false;
				}
				
			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break; //1회 이동 후 모든 충돌 초기화;

	case 1: //서
		for (int i = 0; i < N; ++i)
			for (int j = 0; j <N; ++j) {
				if (j == 0) continue;
				int k = j;
				//막히기 전까지 쭉쭉 전진
				while ((k > 0) && (board[i][k - 1].value == 0)) {
					swap(board[i][k - 1], board[i][k]);
					k--;
				}
				if (k == 0) continue; //충돌없이 끝까지 도달했을 경우
				//충돌 발생시 같은지 확인
				if ((board[i][k].value == board[i][k - 1].value)
					&& (board[i][k - 1].collision == false))
				{
					board[i][k - 1].value *= 2;
					board[i][k - 1].collision = true;
					board[i][k].value = 0;
					board[i][k].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;
	case 2: //남
		for (int j = 0; j < N; ++j)
			for (int i = N - 1; i >= 0; --i) {
				if (i == N - 1) continue;
				int k = i;
				//아무것도 없으면 쭉쭉 전진
				while ((k < N - 1) && (board[k+1][j].value == 0)) {
					swap(board[k][j], board[k+1][j]);
					k++;
				}
				
				if (k == N - 1) continue;//충돌없이 끝까지 도달했을 경우 
				//충돌 발생시 같은지 확인
				if ((board[k+1][j].value == board[k][j].value)
					&& (board[k+1][j].collision == false))
				{
					board[k+1][j].value *= 2;
					board[k+1][j].collision = true;
					board[k][j].value = 0;
					board[k][j].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;

	case 3: //북
		for (int j = 0; j < N; ++j)
			for (int i = 0; i <N; ++i)
			{
				if (i == 0) continue;
				int k = i;
				//아무것도 없으면 쭉쭉 전진
				while ((k > 0) && (board[k - 1][j].value == 0)) {
					swap(board[k][j], board[k - 1][j]);
					k--;
				}
				if (k == 0) continue;//충돌없이 끝까지 도달했을 경우 
				//충돌 발생시 같은지 확인
				if ((board[k - 1][j].value == board[k][j].value)
					&& (board[k - 1][j].collision == false))
				{
					board[k - 1][j].value *= 2;
					board[k - 1][j].collision = true;
					board[k][j].value = 0;
					board[k][j].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;
	}

}

int find_maxblock(int exMax)
{
	int maxNum = exMax;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (maxNum < board[i][j].value) maxNum = board[i][j].value;

	return maxNum;
}
int main()
{
	
	cin >> N;

	board = new BLOCK*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new BLOCK[N];

	saveBoard = new BLOCK*[N];
	for (int i = 0; i < N; ++i)
		saveBoard[i] = new BLOCK[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			cin >> saveBoard[i][j].value;
			board[i][j] = saveBoard[i][j];
		}

	/* 구조체 배열 확인
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			cout << board[i][j].value << ' ';
		cout << '\n';
	}
	*/
	int maxNum = 0;
	//여기부터 본격적인 코딩 시작
	//한번 움직이고 블록 초기화를 해줘야하는 것을 까먹음
	//이렇게 하지 말고, movearray를 만들자.
	int moveArray[5];
	for (int i = 0; i < 4; ++i){
		moveArray[0] = i;
		for(int j = 0 ; j<4;++j){
			moveArray[1] = j;
			for(int k = 0; k<4; ++k){
				moveArray[2] = k;
				for(int l = 0; l<4;++l){
					moveArray[3] = l;
					for (int m = 0; m < 4; ++m){
						moveArray[4] = m;
						for (int n = 0; n < 5; ++n)
							move_block(moveArray[n]);
						maxNum = find_maxblock(maxNum);
						for (int n = 0; n < N; ++n)
							for (int o = 0; o < N; ++o)
								board[n][o] = saveBoard[n][o];
					}			
				}
			}
		}
	}
	
	cout << maxNum;
	return 0;
}

