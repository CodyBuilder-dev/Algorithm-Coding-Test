//���� : ��ġ�� ��
//���� : ��Ÿ�� �� ��� ���� �� ��� ���� �󸶳� ��Ƴ����� ���Ͻÿ�
//���� : ������ �ִ� 250x250 = 62500

/*�ش� ������ BOJ-3187 ��ġ�� ��� ������ �����̹Ƿ� ����
*/


#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int R, C;
char** board;
bool** visited;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };


int oTotal = 0;
int vTotal = 0;

int oCnt = 0; //��
int vCnt = 0; //����

void BFS(int y, int x)
{
	//���� ���� ����ϱ�
	//1. ���� ��ġ�� visited�� �ִ´�
	visited[y][x] = true;

	//2. ���� ��ġ���� �۾��� �����Ѵ�.
	switch (board[y][x]) {
	case 'v': vCnt++; break;
	case 'o': oCnt++; break;
	}
	//3. ���� ��ġ�� ť���ٰ� pair�� �ִ´�(while������ empty �����ϱ� ����)
	queue<pair<int, int>> route;
	route.push(make_pair(y, x));

	//--���⼭���� while��--
	while (!route.empty())
	{
		//4. ť���� ������ ������ǥ�� �����Ѵ�.
		y = route.front().first;
		x = route.front().second;
		route.pop();
		//5. ���� ��ġ �ֺ��� 4���� Ž���Ѵ�.
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			//5. �� ���� �湮���� �ʾ��� ���, �� ���� �湮�ϰ� �۾��� ������ �� visited ǥ���Ѵ�.
			if (ny >= 0 && ny < R && nx >= 0 && nx < C)
			{
				if (visited[ny][nx] == false)
				{
					switch (board[ny][nx])
					{
					case '#': visited[ny][nx] = true; break;
					case '.':
						visited[ny][nx] = true;
						route.push(make_pair(ny, nx)); break;
					case 'o':
						oCnt++;
						visited[ny][nx] = true;
						route.push(make_pair(ny, nx)); break;
					case 'v':
						vCnt++;
						visited[ny][nx] = true;
						route.push(make_pair(ny, nx)); break;
					}
				}
			}

		}

	}
	//�� ������ ������
	vTotal += (oCnt > vCnt ? 0 : vCnt);
	oTotal += (oCnt > vCnt ? oCnt : 0);
	vCnt = 0;
	oCnt = 0;
}
int main()
{
	cin >> R >> C;

	board = new char*[R];
	visited = new bool*[R];
	for (int i = 0; i < R; ++i) {
		board[i] = new char[C];
		visited[i] = new bool[C]();
	}

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
		}
	/*���� Ȯ��*/
	/*
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	*/


	//���⼭���� �ڵ�
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (visited[i][j] == false) BFS(i, j);
		}

	cout << oTotal << ' ' << vTotal;
	return 0;
}
