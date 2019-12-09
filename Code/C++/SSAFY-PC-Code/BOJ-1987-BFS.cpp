//���� : ���ĺ�
//���� : ���忡�� ��� ���ĺ��� �ٸ� ��η� �����ϱ�
//���� : ����� �ִ� 20x20

/*���̵�� : 
1.���Ե� ���ĺ��� alphabet[26]�� ����
2.����� ��δ� vistied�� ����
3.�׿ܿ��� �׳� �迭���ٰ� BFS/DFS���� ��
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