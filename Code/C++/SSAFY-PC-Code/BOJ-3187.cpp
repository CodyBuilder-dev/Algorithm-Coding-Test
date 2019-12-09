//제목 : 양치기 꿍
//목적 : 울타리 안 양과 늑대 중 어느 쪽이 얼마나 살아남는지 구하시오
//조건 : 영역은 최대 250x250 = 62500

/*아이디어 : BFS문제는, 대체 왜 BFS로 접근해야 하는지 그 이유를 밝히는게 중요함
1. 울타리로 둘러쌓여 있으므로, 울타리 내의 상황을 아는 것이 중요함
2. 사실 이건 DFS로 해도 될거같긴 함
3. 그럼에도 불구하고, 2차원 배열 상에서 별로 깊지 않게 탐색하므로 BFS 고고
*/

/*구현
1. BFS구현. 이때 각 y,x좌표는 pair로 구현하면 편한 듯
2. 보드는 int의 2차원 배열로 구현
3. 값 받아들이기는 어떻게 해야될지 좀 헷갈리긴한데 일단 scanf
*/

/*느낀점 
1. 삼항연산자 사용시 괄호 사용 주의?
2. 정신 바짝 차리고 코딩안하면 =,== 실수함
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


int kTotal = 0;
int vTotal = 0; 

int kCnt=0; //양
int vCnt = 0; //늑대

void BFS(int y, int x)
{
	//구현 순서 기억하기
	//1. 현재 위치를 visited에 넣는다
	visited[y][x] = true;

	//2. 현재 위치에서 작업을 수행한다.
	switch (board[y][x]) {
	case 'v': vCnt++; break;
	case 'k': kCnt++; break;
	}
	//3. 현재 위치를 큐에다가 pair로 넣는다(while문에서 empty 방지하기 위함)
	queue<pair<int, int>> route;
	route.push(make_pair(y, x));

	//--여기서부터 while문--
	while (!route.empty())
	{
		//4. 큐에서 꺼내서 현재좌표로 설정한다.
		y = route.front().first;
		x = route.front().second;
		route.pop();
		//5. 현재 위치 주변의 4점을 탐색한다.
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			//5. 각 점이 방문되지 않았을 경우, 각 점을 방문하고 작업을 수행한 뒤 visited 표기한다.
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
					case 'k':
						kCnt++;
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
	//다 끝나면 늑대계산
	vTotal += (kCnt > vCnt ? 0 : vCnt);
	kTotal += (kCnt > vCnt ? kCnt : 0);
	vCnt = 0;
	kCnt = 0;
}
int main()
{
	cin >> R >> C;

	board = new char* [R];
	visited = new bool*[R];
	for (int i = 0; i < R; ++i){
		board[i] = new char[C];
		visited[i] = new bool[C]();
	}
	
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
		}
	/*보드 확인*/
	/*
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	*/

	
	//여기서부터 코딩
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if(visited[i][j] == false) BFS(i, j);
		}

	cout << kTotal << ' ' << vTotal;
	return 0;
}

