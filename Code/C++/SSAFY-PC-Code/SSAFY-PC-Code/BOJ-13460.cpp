//제목 : 구슬 탈출2
//목적 : 장난감을 4방향으로 기울여 구멍으로 공을 빼내기
/*조건 : 구슬의 동작에 대한 조건이 굉장히 많음
1. 기울이기란 90도 회전이 아니라 그냥 중력의 방향으로 기울이는 것
2. 보드의 크기는 10x10
*/

/*아이디어 :각 시점에서 4가지의 경우의 수를 가지는 트리라고 보면 됨
1. 일단 보드 받기
2. 왼쪽, 오른쪽, 아래, 위 함수 구현
3. DFS를 통해 4가지 다 돌려봄
4. 구슬이 통과될 경우 그 값을 저장해서 min으로 삼기
반복
*/

//느낀점 : 4방향이 dy,dx가 아니라 left,right 함수로 이루어졌을때 bfs 할줄아는가
/*느낀점 : 2차원배열은 인자에 넣을 때
함수 정의는 board[][10]식으로, 열의 개수를 확정해서 넣는다
실제 호출시는 배열 이름 board만 넣는다
*/
//배열을 재귀함수에 넣을떄는 또 어떻게 되는지 느껴봐야 함
//배열을 복사할 떄, memcpy랑 copy가 있는데 memcpy가 나음.
//sizeof는 2차원배열의 경우에는 바이트의 수인데, 고정크기면 그냥 숫자 넣는게 나을 수 있음
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
char board[10][10];
bool visited[10][10];

int minima;
vector<int> cntset;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	/*
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cout << board[i][j];
	*/
}

//왼쪽
void left(char curboard[][10])
{
	//우선 왼쪽위부터 돌면서 공의 위치 찾기
	//먼저 찾아지는 공부터 왼쪽으로 굴리기
	//그다음 공 찾아서 굴리기
	//굴리다 벽 만나면 정지
	//굴리다 구멍 만나면 탈출 플래그 세우기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B'){
				int k = j;
				while (k - 1 >= 0 && curboard[i][k-1] == '.') {
					swap(curboard[i][k], curboard[i][k - 1]);
					k -= 1;
				}
				if (curboard[i][k - 1] == 'O') {
					if (curboard[i][k] == 'R') {

						curboard[i][k] = '.';
					}
					if (curboard[i][k] == 'B') {

						curboard[i][k] = '.';
					}
				}
			}
		}
	}
}

//오른쪽
void right(char curboard[][10])
{
	for (int i = 0; i < N; ++i) {
		for (int j = M-1; j >=0; --j) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B'){
				int k = j;
				while (k + 1 < M && curboard[i][k+1] == '.') {
					swap(curboard[i][k], curboard[i][k + 1]);
					k += 1;
				}
				if (curboard[i][k + 1] == 'O') {
					if (curboard[i][k] == 'R') {
						curboard[i][k] = '.';
					}
					if (curboard[i][k] == 'B') {
						curboard[i][k] = '.';
					}
				}
			}
		}
	}
}

//위쪽
void up(char curboard[][10])
{
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N; ++i) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B') {
				int k = i;
				while (k - 1 >= 0 && curboard[k - 1][j] == '.') {
					swap(curboard[k][j], curboard[k - 1][j]);
					k -= 1;
				}
				if (curboard[k - 1][j] == 'O') {
					if (curboard[k][j] == 'R') {

						curboard[k][j] = '.';
					}
					if (curboard[k][j] == 'B') {
		
						curboard[k][j] = '.';
					}
				}
			}
		}
	}
}

//아래쪽
void down(char curboard[][10])
{
	for (int j = 0; j < M; ++j) {
		for (int i = N-1; i >=0; --i) {
			if (curboard[i][j] == 'R' || curboard[i][j] == 'B') {
				int k = i;
				while (k + 1 < N && curboard[k + 1][j] == '.') {
					swap(curboard[k][j], curboard[k + 1][j]);
					k += 1;
				}
				if (curboard[k + 1][j] == 'O') {
					if (curboard[k][j] == 'R') {
						curboard[k][j] = '.';
					}
					if (curboard[k][j] == 'B') {
						curboard[k][j] = '.';
					}
				}
			}
		}
	}
}
int check_win(char curboard[][10])
{
	bool Rout = true;
	bool Bout = true;
	//보드를 한바퀴 싹 돌면서 RB상태 파악
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (curboard[i][j] == 'R') Rout = false;
			if (curboard[i][j] == 'B') Bout = false;
		}

	if (Rout == true) {
		if (Bout == true) return -1;
		else return 1;
	}
	else {
		if (Bout == true) return -1;
		else return 0;
	}
}
//구슬 이동 시작
void start_game_dfs(char curboard[][10],int cnt)
{
	//새보드 만들기
	//left해보기
	//게임끝? 횟수 저장 후 돌아가기
	//안끝? 다음 dfs로 넘기기
	//right해보기
	//..반복

	if (cnt > 10) {
		return;
	}

	char newboard[10][10];
	memcpy(&newboard[0][0], &curboard[0][0], 100);
	//cout << "변환 전" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << newboard[i][j];
	//	cout << '\n';
	//}
	
	left(newboard);
	//cout << "변환 후" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << newboard[i][j];
	//	cout << '\n';
	//}

	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt+1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}

	memcpy(&newboard[0][0], &curboard[0][0], 100);
	right(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}

	memcpy(&newboard[0][0], &curboard[0][0], 100);
	up(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}
	memcpy(&newboard[0][0], &curboard[0][0], 100);
	down(newboard);
	if (check_win(newboard) == 0) {
		start_game_dfs(newboard, cnt + 1);
	}
	else if (check_win(newboard) == 1) {
		cntset.push_back(cnt);
	}
}


int main()
{
	input();

	//이렇게 줘버리면 같은 주소에 참조하는거라 board랑 newboar가 같이 변함
	//2차원 배열을 복사하는 방법 알아야 함
	char newboard[10][10];
	//cout << sizeof(newboard);
	memcpy(&newboard[0][0], &board[0][0], sizeof(board));
	
	//copy(&board[0][0], &board[0][0] + N * M, &newboard[0][0]);
	//여기선 복사 잘 되는데
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << newboard[i][j];
		cout << '\n';
	}*/

	start_game_dfs(newboard, 1);

	if (cntset.size() == 0) minima = -1;
	else {
		minima = 987;
		for (int i = 0; i < cntset.size(); ++i)
			if (cntset[i] < minima) minima = cntset[i];
	}
	cout << minima;
}