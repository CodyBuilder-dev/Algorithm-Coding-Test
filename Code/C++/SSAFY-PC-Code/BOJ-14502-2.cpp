//제목 : 연구소
//목적 : 2차원배열에서 벽 3개를 세워 바이러스를 막았을 때 안전영역 최대
//유형 : DFS 2중 중첩

/*아이디어 : 
1. 벽을 세우는 경우의 수부터 일단 트리구조로 뻗어나가므로 DFS
2. 벽이 모두 세워진 이후에 바이러스의 범위를 찾는것도 DFS/BFS
*/

//느낀점 : DFS안에 DFS가 있으 ㄹ경우, stack으 ㄹ이용해서 원하는 정보를 들고갈 수 있다.
//대신 stack을 언제 어떻게 push pop 할지는 잘 생각해서 풀어야 한다.
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int N,M;

int **lab;
bool **walled;
bool **visited;

stack<pair<int,int>> route;

int maxima=-987654;
int safe = 0;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1 };

void DFS(int y, int x) //대충 DFS 도는 함수
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M)
		{
			if (visited[ny][nx] == false && walled[ny][nx] == false
				&& lab[ny][nx] != 1)
				DFS(ny, nx);
		}
	}
}

void make_wall(int cnt) //대충 벽 만드는 함수
{
	if (cnt > 2) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (lab[i][j] == 2 && visited[i][j] == false && walled[i][j] == false)
					DFS(i, j);
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (visited[i][j] == false && walled[i][j] ==false
					&& lab[i][j] == 0)
					safe++;
		maxima = (safe > maxima) ? safe : maxima;
		//cout << "넓이" << safe << '\n';
		safe = 0;
		int dely = route.top().first;
		int delx = route.top().second;
		//cout << "마지막 벽" <<dely << ' ' << delx << '\n';
		route.pop();
		walled[dely][delx] = false;
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				visited[i][j] = false;
		return;
	}
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			
			if (!walled[i][j] && lab[i][j] == 0) {
				walled[i][j] = true;
				route.push(make_pair(i, j));
				//cout << "현재 " << cnt << "번째 벽" << i << ' ' << j << ',';
				make_wall(cnt + 1); //벽의 개수


			}
		
		}
	}
	if (!route.empty())
	{
		int dely = route.top().first;
		int delx = route.top().second;
		walled[dely][delx] = false;
		route.pop();
	}
}

//문제 : 한번 walled되면 안 초기화됨

int main()
{
	cin >> N >> M;
	lab = new int*[N];
	walled = new bool*[N];
	visited = new bool*[N];
	for (int i = 0; i < N; ++i){
		lab[i] = new int[M];
		walled[i] = new bool[M]();
		visited[i] = new bool[M](); 
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> lab[i][j];
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << lab[i][j] << ' ';
		cout << '\n';
	}
	*/
	make_wall(0);
	//cout << "해답 " << maxima;
	cout << maxima;
}
