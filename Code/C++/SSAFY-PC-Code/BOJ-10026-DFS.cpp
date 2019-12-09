//제목 : 적록색약
//목적 : 적록색약이 본 경우의 구역과 일반인이 본 구역

/*아이디어 : 그냥 전형적인 배열 탐색 문제
1.DFS/BFS중에 하나로 풀자
2.
*/

//느낀점 : DFS에서 진입조건만 까다롭게 잘 잡으면 return조건은 심지어 없어도 됨
#include <iostream>

using namespace std;

int N;

char** board;
bool** visited;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void DFS(int y, int x, char color)
{
	//1.return조건 적어넣기
	//2. visited 체크
	visited[y][x] = true;
	//3. 현재 노드에서 할일
	//4. for문으로 노드와 인접한 곳 중 방문하지 않은 곳 탐색
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && ny<N&& nx>=0 && nx <N)
				if (visited[ny][nx] == false && board[ny][nx] == color)
					DFS(ny, nx,color);
		}
	//5. 방문하지 않았을 경우 재귀로 더 들어감
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
	//여기서부터 코딩 시작
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false) {
				DFS(i, j, board[i][j]);
				area++;
			}
		
		}
	cout << area<<' ';

	//적록색맹 보드 변경
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