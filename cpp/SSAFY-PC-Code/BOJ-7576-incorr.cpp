//제목 : 토마토
//목적 : 토마토가 든 상자의 상태를 받아, 모두 익지 못하는 상황이면 -1을, 모두 익으면 익는 최소 날자를 출력
//조건 : 상자는 최대 10^3^2 = 10^6

/*아이디어 : 4방향으로 전염되고, 최소일자를 구해야 하므로 BFS가 맞는 듯
1. 우선 0을 찾아서, BFS나 DFS를 수행해 1이 없으면 무조건 결과는 -1
2. 만약 -1이 아니라면 그때부터 1 찾아서 BFS
or
1. 일단 1찾아서 BFS 
2. 한바퀴 다 돌고 마지막에 다 찾아서 0있나없나 검사
*/

/*구현 :
1. 전구간을 다 스캔해서, 1인 곳의 좌표를 찾아서 큐나 어디에 넣는다
2. 큐에서 하나씩 꺼내면서 BFS
3. 그럼 time은 어떻게 찾고? 하나씩 다 꺼낸 후에 time 1증가
4. BFS로 반복
5. BFS끝나면 전구간 다 뒤져서 0 찾기
*/

//느낀점 : 이렇게 짜면 시간초과 걸리는데, 어디가 병목인지 모르겠음.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef struct {
	int value;
	int time = 0;
} BLOCK;

int N, M;
BLOCK **board;
bool **visited;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

vector<pair<int,int>> tomato;

void BFS(int y, int x)
{
	//time을 어느 시점에 증가시킬 것인가
	//큐에서 하나 뽑기
	//걔의 4방향 다 찾으면, 다음 토마토 뽑기
	//tomato 좌표가 적인 큐를 한바퀴 다 돌면 time 1 증가...하려고 했으나 한바퀴라는 개념이 없음
	//결국 보드 자체에 시간값을 저장하는 수 밖에 없음
	visited[y][x] = true;
	while (!tomato.empty())
	{
		y = tomato.front().first;
		x = tomato.front().second;
		tomato.erase(tomato.begin());
	
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (visited[ny][nx] == false && board[ny][nx].value == 0)
				{
					visited[ny][nx] = true;
					board[ny][nx].value = 1;
					board[ny][nx].time = board[y][x].time + 1;
					tomato.push_back(make_pair(ny, nx));
				}
			}
		}

	}
}

int main()
{
	cin >> M >> N;

	board = new BLOCK*[N];
	visited = new bool*[N];

	for (int i = 0; i < N; ++i)
	{
		board[i] = new BLOCK[M];
		visited[i] = new bool[M]();
	}
	
	for(int i = 0; i<N;++i) //스캔받으면서 1이 있을 경우 벡터에 넣기
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j].value;
			if (board[i][j].value == 1) tomato.push_back(make_pair(i, j));
		}
	//여기서부터 본격적인 코딩 시작
	int result;
	if (tomato.empty()) result = -1;
	else {
		BFS(tomato.front().first, tomato.front().second);

		
		for (int i = 0; i < N; ++i) { //한바퀴 돌면서 0 있으면 -1
			for (int j = 0; j < M; ++j) //한바퀴 돌면서 최대값 찾아서 cout
			{
				if (board[i][j].value == 0) {
					result = -1; break;
				}
				result = max(result, board[i][j].time);
			}
			if (result == -1) break;
		}
	}
	cout << result;
}