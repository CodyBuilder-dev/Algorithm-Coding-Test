//���� : ���ϻ���
//���� : ���ϻ����� �� ����� ������ �Ϲ����� �� ����

/*���̵�� : �׳� �������� �迭 Ž�� ����
1.DFS/BFS�߿� �ϳ��� Ǯ��
2.
*/

//������ : DFS���� �������Ǹ� ��ٷӰ� �� ������ return������ ������ ��� ��
#include <iostream>

using namespace std;

int N;

char** board;
bool** visited;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void DFS(int y, int x, char color)
{
	//1.return���� ����ֱ�
	//2. visited üũ
	visited[y][x] = true;
	//3. ���� ��忡�� ����
	//4. for������ ���� ������ �� �� �湮���� ���� �� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && ny<N&& nx>=0 && nx <N)
				if (visited[ny][nx] == false && board[ny][nx] == color)
					DFS(ny, nx,color);
		}
	//5. �湮���� �ʾ��� ��� ��ͷ� �� ��
}
int main()
{

	cin >> N;

	board = new char* [N];
	visited = new bool* [N];
	for (int i = 0; i < N; ++i){
		board[i] = new char[N];
		visited[i] = new bool[N]();
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	
	int area = 0;
	//���⼭���� �ڵ� ����
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false) {
				DFS(i, j, board[i][j]);
				area++;
			}
		
		}
	cout << area<<' ';

	//���ϻ��� ���� ����
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (board[i][j] == 'G') board[i][j] = 'R';
	
	visited = new bool* [N];
	for (int i = 0; i < N; ++i) {
		visited[i] = new bool[N]();
	}
	area = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false) {
				DFS(i, j, board[i][j]);
				area++;
			}
		}
	cout << area;
}