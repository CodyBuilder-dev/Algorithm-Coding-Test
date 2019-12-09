//���� : ���� ����
//���� : �������� ���� ������ ã��
//���� : ������ �ִ� 50x50

/*���̵�� : 
1. ������ 2�����迭�̹Ƿ�, ������ȣ���̱�ó�� BFS�� ���� �� �� ������
2. �� �̵������� 8���� ���̽��ӿ� ����
3. BFS���� �� ���� +1�� �ϱ�
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
	//�켱 ���� ������ üũ�ϰ�
	//�����ִ� ��� ������ ť�� �ְ�
	//ť���� �� �տ��ִ³� ����
	//�ݺ�
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
