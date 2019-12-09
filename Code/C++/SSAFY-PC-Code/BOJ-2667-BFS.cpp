//���� : ������ȣ���̱�
//���� : 1�� ǥ�õ� ����Ʈ �������� ��ȣ�� �ű���
//���� : ������ �ִ� 25x25

/*���̵�� : BFS�ε� Ǯ���µ� ���� �׳� ����� ���Ѱ���
*/

/*������ : bool �迭�� scanf�� int�� ������ 
���ؿ��� �޸� �ʰ� ���� �߻�(VS�� �����)
*/

#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int N;

bool visited[25][25];
int map[25][25];
//bool map[][]�� �ϸ� ����!

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