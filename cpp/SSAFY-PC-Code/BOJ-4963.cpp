//제목 : 섬의 개수
//목적 : 지도에서 섬의 개수를 찾기
//조건 : 지도는 최대 50x50

/*아이디어 : 
1. 지도는 2차원배열이므로, 단지번호붙이기처럼 BFS를 쓰면 될 것 같은데
2. 단 이동방향이 8가지 케이스임에 주의
3. BFS쓰고 섬 개수 +1씩 하기
*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int X, Y;
int map[50][50];
bool visited[50][50];
queue<pair<int, int>> nextCoord;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

void bfs(int y, int x) 
{
	//우선 현재 지점을 체크하고
	//갈수있는 모든 지점을 큐에 넣고
	//큐에서 젤 앞에있는놈 빼고
	//반복
	visited[y][x] = true;
	nextCoord.push(make_pair(y, x));

	do{
		y = nextCoord.front().first;
		x = nextCoord.front().second;
		nextCoord.pop();

		for (int i = 0; i < 8; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < Y && nx < X) {
				if (visited[ny][nx] == false && map[ny][nx] == 1){
					visited[ny][nx] = true;
					nextCoord.push(make_pair(ny, nx));
				}
			}
		}
	} while (!nextCoord.empty());
}
int main()
{
	while (true)
	{
		cin >> X >> Y;
		if (X == 0 && Y == 0) break;
		for (int i = 0; i < Y; ++i)
			for (int j = 0; j < X; ++j)
				cin >> map[i][j];
		int cnt = 0;
		for(int i = 0; i<Y;++i)
			for (int j = 0; j < X; ++j) {
				if (visited[i][j] == false && map[i][j] == 1){
					bfs(i, j);
					cnt++;
				}
			}

		for (int i = 0; i < Y; ++i)
			for (int j = 0; j < X; ++j)
				visited[i][j] = false;

		cout << cnt << '\n';
	}
}
