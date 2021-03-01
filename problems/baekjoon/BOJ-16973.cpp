//���� : ���簢�� Ż��
//���� : �� ���� �ƴ϶�, ���簢�� ����� �̵���Ű�� ���ϴ� ������ �����ϱ�
/*���� : ������ ũ��� �ִ� 1000x1000
�� ���ڸ��� 1,1�� �����Կ� ����
*/

/*���̵�� : 
1. ������ �Է� �޴´�
(1,1)���� �����̹Ƿ�, 2x3�׸�� �ִ� (x+H-1,y+W-1)����
1. �ִܰŸ��̹Ƿ� BFS�� �غ���
2. �浹������ ���簢�� ��ü�� ���. visited�� �������� ��Ƶ� �� ��
3. �ִܰŸ��� ã�ƾ� �ϹǷ�, �Ÿ��� ������...��
(�Ÿ��� �ٸ� ���忡 �����ϰų�, ���� ���� ���� �����ϰų�)
4. �������� �����ϸ� Ż���� �� �ֵ��� �Ѵ�.
*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int H, W;

int board[1001][1001];
bool visited[1001][1001];
int dist[1001][1001]; //�Ÿ��� ť�� �ִ��� �׳� ���⿡ �ٷ� ������ ����

pair<int, int> s,e;

int dx[] = { 1,0,-1,0 }; //��������
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
	case 0:  //��. 
		checkCol = x + W;
		if (checkCol > M) return false;
		else {
			for (int i = 0; i < H; ++i) 
				if (board[y + i][checkCol] == 1) return false;

			return true;
		}
		break;

	case 1: //��
		checkRow = y+H;
		if (checkRow > N) return false;
		else {
			for (int i = 0; i < W; ++i) //y
				if (board[checkRow][x + i] == 1) return false;

			return true;
		}
		break;
	case 2: //��
		checkCol = x-1;
		for (int i = 0; i < H; ++i) //y
			if (board[y + i][checkCol] == 1) return false;

		return true;
		break;
	case 3: //��
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

			if (ny <= N && ny >= 1 && nx <= M && nx >= 1) {//�������
				if (visited[ny][nx] == false && check_next(y, x, i)) {//�̵� �����ϸ�
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