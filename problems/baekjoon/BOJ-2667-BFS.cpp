//제목 : 단지번호붙이기
//목적 : 1로 표시된 아파트 단지마다 번호를 매기자
//조건 : 지도는 최대 25x25

/*아이디어 : BFS로도 풀리는데 내가 그냥 제대로 못한거임
*/

/*느낀점 : bool 배열에 scanf로 int를 받으면 
백준에선 메모리 초과 오류 발생(VS는 실행됨)
*/

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int N;

bool visited[25][25];
int map[25][25];
//bool map[][]로 하면 에러!

queue<pair<int, int>> route;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int danji;
int aptNum[313];

void BFS(int y,int x,int danji)
{
	visited[y][x] = true;
	route.push(make_pair(y, x));
	aptNum[danji]++;

	do{
		y = route.front().first;
		x = route.front().second;
		route.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny >= 0 && ny < N && nx >= 0 && nx <N)
				if (visited[ny][nx] == false && map[ny][nx] == true)
				{
					visited[ny][nx] = true;
					aptNum[danji]++;
					route.push(make_pair(ny, nx));
				}
		}
	} while (!route.empty());
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d",&map[i][j]);

	for(int i = 0; i<N;++i)
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == true && visited[i][j] == false) {
				BFS(i, j,danji);
				danji++;
			}
		}

	cout << danji << '\n';
	sort(aptNum, aptNum + danji);
	for (int i = 0; i < danji; ++i)
		cout << aptNum[i] << '\n';
}