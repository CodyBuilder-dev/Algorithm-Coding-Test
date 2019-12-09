//제목 : 직사각형 탈출
//목적 : 한 점이 아니라, 직사각형 덩어리를 이동시키며 원하는 지점에 도달하기
/*조건 : 보드의 크기는 최대 1000x1000
맨 윗자리는 1,1로 시작함에 주의
*/

/*아이디어 : 
1. 게임판 입력 받는다
(1,1)부터 시작이므로, 2x3네모는 최대 (x+H-1,y+W-1)까지
1. 최단거리이므로 BFS를 해본다
2. 충돌조건을 직사각형 전체로 잡고. visited는 한점으로 잡아도 될 듯
3. 최단거리를 찾아야 하므로, 거리를 저장한...다
(거리는 다른 보드에 저장하거나, 따로 벡터 만들어서 저장하거나)
4. 목적지에 도달하면 탈출할 수 있도록 한다.
*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int H, W;

int board[1001][1001];
bool visited[1001][1001];
int dist[1001][1001]; //거리를 큐에 넣느냐 그냥 여기에 바로 적느냐 문제

pair<int, int> s,e;

int dx[] = { 1,0,-1,0 }; //동남서북
int dy[] = { 0,1,0,-1 };

bool isReached;

void input()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> board[i][j];

	cin >> H >> W >> s.first >> s.second >> e.first >> e.second;

}

bool check_next(int y, int x, int dir)
{
	int checkCol, checkRow;
	switch (dir) {
	case 0:  //동. 
		checkCol = x + W;
		if (checkCol > M) return false;
		else {
			for (int i = 0; i < H; ++i) 
				if (board[y + i][checkCol] == 1) return false;

			return true;
		}
		break;

	case 1: //남
		checkRow = y+H;
		if (checkRow > N) return false;
		else {
			for (int i = 0; i < W; ++i) //y
				if (board[checkRow][x + i] == 1) return false;

			return true;
		}
		break;
	case 2: //서
		checkCol = x-1;
		for (int i = 0; i < H; ++i) //y
			if (board[y + i][checkCol] == 1) return false;

		return true;
		break;
	case 3: //북
		checkRow = y -1;
		for (int i = 0; i < W; ++i) //y
			if (board[checkRow][x + i] == 1) return false;

		return true;
		break;
	}
}
void find_route_bfs(int y, int x)
{
	queue<pair<int, int>> Q;
	queue<int> distQ;

	int len = 0;
	Q.push(make_pair(y, x));
	distQ.push(len);
	visited[y][x] = true;

	do {
		y = Q.front().first;
		x = Q.front().second;
		len = distQ.front();
		Q.pop();
		distQ.pop();

		if (y == e.first && x == e.second) {
			isReached = true;
			dist[e.first][e.second] = len;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= N && ny >= 1 && nx <= M && nx >= 1) {//경계조건
				if (visited[ny][nx] == false && check_next(y, x, i)) {//이동 가능하면
					visited[ny][nx] = true;
					Q.push(make_pair(ny, nx));
					distQ.push(len+1);
				}
			}
		}
	} while (!Q.empty());

}
int main()
{
	input();
	
	/*cout << s.first << s.second << '\n';
	cout << e.first << e.second;*/
	find_route_bfs(s.first, s.second);

	if (dist[e.first][e.second] != 0) cout << dist[e.first][e.second];
	else cout << -1;
}