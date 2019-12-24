//제목 : 연구소3
//목적 : 2차원배열에서 바이러스 3개 선택해서 감염
//조건 : 연구소 크기 50x50. 바이러스 최대 10개

/*아이디어 :
1.바이러스 10개중에 3개 선택
->선택할 때, 바이러스의 좌표를 어딘가에 넣은 후 인덱스를 초이스해야함
2. 3개로부터 BFS 돌리기(최소 시간이므로)
->2군데에서 동시에 BFS 돌리는건 토마토2 참조
(시간은 보드에 따로 저장해야 한다 ㅜㅜ
3. 바이러스가 진행하다 바이러스를 만날 경우 마찬가지로 바이러스로 전이
4. 마지막 남은 칸이 바리어스일 경우 굳이 한 타임 더 안 가도 됨
(이걸 어떻게 처리하느냐가 문제)
*/

/*문제점 : 74%에서 틀림 <- 논리 오류
아이디어 전환 필요 
1. 솔직히 논리자체는 문제없다 ㅇㅈ?
2. 문제는 VIRUS의 크기가 990밖에 안되는데, 경우가 엄청 커지는 경우에 초과되는게 문제였음 ㅋㅋㅋㅋㅋ
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <list>

#define VIRUS 9900

using namespace std;

int N, M;

int board[50][50];
int time[50][50];
bool visited[50][50];
int minimum = 987654;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };

int virusNum; //보드 위 바이러스의 개수
deque<pair<int, int>> virusCoord; //보드 위 바이러스의 좌표
deque<int> virusChoice; // 바이러스 조합 vector
queue<pair<int, int>> route; //경로 큐
vector<int> timeSet;

//보드 입력 받기
void input_board()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virusCoord.push_back(make_pair(i, j));
				virusNum++;
			}
		}
}

//time배열 최대값 찾기
void check_maxtime()
{
	int max = -987654;
	bool isBlank = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] != 1 && visited[i][j] == false) isBlank = true;
			if (time[i][j] > VIRUS && board[i][j] == 2)
				continue;
			if (max < time[i][j]) max = time[i][j];

		}
	}
	if (!isBlank) timeSet.push_back(max);
}

//바이러스 성장
void grow_virus(int y, int x)
{
	do {
		y = route.front().first;
		x = route.front().second;
		route.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (visited[ny][nx] == false) {
					if (time[y][x] >= VIRUS) //현재칸이 비활성 바이러스인 경우
					{
						if (board[ny][nx] == 0)//다음칸이 그냥 공간인 경우
						{
							visited[ny][nx] = true;
							time[y][x] -= VIRUS;
							time[ny][nx] = time[y][x] + 1;

							route.push(make_pair(ny, nx));
						}
						else if (board[ny][nx] == 2) //또 virus인 경우
						{
							visited[ny][nx] = true;
							time[ny][nx] = time[y][x] + 1;
							route.push(make_pair(ny, nx));
						}
					}
					else { //현재칸이 그냥 평범한 경우
						if (board[ny][nx] == 0)//그냥 공간인 경우
						{
							visited[ny][nx] = true;
							time[ny][nx] = time[y][x] + 1;

							route.push(make_pair(ny, nx));

						}
						else if (board[ny][nx] == 2) //virus인 경우
						{
							visited[ny][nx] = true;
							time[ny][nx] = VIRUS + time[y][x] +1;
							route.push(make_pair(ny, nx));
						}

					}
					
					
	/*				for (int k = 0; k < N; ++k) {
						for (int l = 0; l < N; ++l)
							cout << time[k][l];
						cout << '\n';
						
					}
					cout << "----------------\n";*/
					
				}
			}
		}

	} while (!route.empty());
}

//바이러스 선택
void choice_virus()
{
	for (int i = 0; i < virusNum - M; ++i)
		virusChoice.push_back(0);
	for (int i = virusNum - M; i < virusNum ; ++i)
		virusChoice.push_back(1);
	
	do {
		
		while (!route.empty())
		{
			route.pop();
		}

		//for (int i = 0; i < virusNum; ++i)
		//	cout << virusChoice[i] ;
		//cout << '\n' << virusNum << virusChoice.size() << '\n';

		//for (int k = 0; k < N; ++k) {
		//	for (int l = 0; l < N; ++l)
		//		cout << board[k][l];
		//	cout << '\n';

		//}
		/*
		for (int i = 0; i < virusNum; ++i)
			cout << virusCoord[i].first << ' ' << virusCoord[i].second << '\n';
		*/

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				time[i][j] = 0;
				visited[i][j] = false;
			}
		}


		for (int i = 0; i < virusChoice.size(); ++i) {
			if (virusChoice[i] == 1) { 
				route.push(virusCoord[i]); 
				visited[virusCoord[i].first][virusCoord[i].second] = true;
			}
		}

		int y = route.front().first;
		int x = route.front().second;

		grow_virus(y, x);

		check_maxtime();

	} while (next_permutation(virusChoice.begin(), virusChoice.end()));
	
	if (timeSet.size() > 0) {//한 경우라도 성공한 경우
		for (int i = 0; i < timeSet.size(); ++i)
			if (timeSet[i] < minimum) minimum = timeSet[i];
	}
	
	else minimum = -1;
}



int main()
{
	input_board();

	choice_virus();
	cout << minimum;
}