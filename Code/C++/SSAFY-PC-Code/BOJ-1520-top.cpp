//제목 : 내리막 길
//목적 : 내리막으로 이동하는 경우의 수
//조건 : 지도의 최대 크기는 500

/*아이디어 : DFS+메모이제이션. 탈출이랑 비슷함
1.DFS로 경로 찾아서 탈출함
2.경로상의 모든 점에 exitable 체크
*/

/*DFS+DP에 대해 완전 잘못 접근하고 있었음
내가 생각한 풀이 : 그냥 DFS하면서, 도착하게 될 경우 지금까지 경로 전부 exitable하고 1 더해줁다
가다가 이미 exitable에 도착할 경우 마찬가지로 이때까지 루트를 전부 exitable하고 루트를 1 더해준다
->문제점 : 하위 경로로부터 파생되는 경로 개수를 세지 않고 다 +1로 퉁침

맞는 풀이 : exitable 가/불 뿐 아니라, 해당 점으로부터 몇가지로 탈출할 수 있는가를 더해줘야 함
->그냥 더하는 것이 아니고, 곱하기로 해줘야 함

DP풀이 : 현재 점까지 오는 방법은, 현재점 바로 전 점까지의 경우의 수의 총합
*/

/*DFS에서 return의 위치는, for문 안에 넣으면 안 좋을 수 있음
이유 : 네방향다 살펴보기도 전에 탈출해버림
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int M, N;

int board[500][500];
bool exitable[500][500];
int dp[500][500];

int dy[] = { 1,0,-1,0 }; //남동북서
int dx[] = { 0,1,0,-1 };

deque<pair<int, int>> routeSet;

void input()
{
	cin >> M >> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
}

void find_route_dfs(int y, int x, deque<pair<int, int>> route)
{
	/*논리의 흐름
	1. 일단 방향 탐색
	2. 탐색하면서 계속 경우의 수 가지고 잇음
	3. 가다가 탈출하면
	4.
	5.
	*/
	if (y == M - 1 && x == N - 1) { //탈출하면
		for (int j = 0; j < route.size(); ++j) {
			exitable[route[j].first][route[j].second] = true;
			dp[route[j].first][route[j].second] += 1;
		}
		return;
	}
	if (exitable[y][x] == true) { //이미 탈출가능하다고 계산될 경우
		for (int j = 0; j < route.size(); ++j) {
			exitable[route[j].first][route[j].second] = true;
			dp[route[j].first][route[j].second] += 1;
		}
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N) {//경계조건
			if (board[y][x] > board[ny][nx]) {//내리막
				deque<pair<int, int>> newRoute(route);
				newRoute.push_back(make_pair(ny, nx));
				find_route_dfs(ny, nx, newRoute);
			}
		}
	}
}

//dp의 레퍼토리가 비슷하기때문에 int를 return할 것이라고 생각할 수 있다.
int find_route_dp(int y, int x)
{
	if (y == M - 1 && x == N - 1)
		ret
	else if (dp[y][x] != 0)
		return dp[y][x];

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < M && nx >= 0 && nx < N) {//경계조건
			if (board[y][x] > board[ny][nx]) {//내리막
				return find_route_dp()
			}
		}
	}
}
int main()
{
	input();
	dp[0][0] = 1;

	//find_route_dfs(0, 0,routeSet);
	
	cout << dp[0][1] + dp[1][0];


}