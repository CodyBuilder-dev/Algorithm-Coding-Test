//제목 : 알파벳
//목적 : 보드에서 모든 알파벳과 다른 경로로 진행하기
//조건 : 보드는 최대 20x20

/*아이디어 : 
1.포함된 알파벳은 alphabet[26]에 저장
2.진행된 경로는 vistied에 저장
3.그외에는 그냥 배열에다가 BFS/DFS쓰기 끝
*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int R, C;

char board[20][20];
bool visited[20][20];
bool alphabet[26];
queue<pair<int, int>> route;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

void bfs(int y,int x)
{
	visited[y][x];
	route.push(make_pair(y, x));

	do {
		y = route.front().first;
		x = route.front().second;
		route.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny >=0 && ny < R && nx >=0 && nx<C)
				if (visited[ny][nx] == false
					&& alphabet[board[ny][nx] - 65] == false)
				{
					visited[ny][nx] = true;
					alphabet[board[ny][nx] - 65] = true;
					route.push(make_pair(ny, nx));
				}
		}
	} while (!route.empty());

}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			scanf("%c", &board[i][j]);

	
}