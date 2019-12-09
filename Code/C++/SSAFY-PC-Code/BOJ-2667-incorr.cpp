//제목 : 단지번호 붙이기
//목적 : 2차원 배열을 순회할 때 BFS/DFS를 쓸 수 있는가
/*아이디어
1.단지를 일종의 그래프로서 파악
2. 단지의 이동 방향은 4방향이므로 델타순회? 배열을 완전탐색하는게 아니므로 놉
3. 이거는 4방향을 모두 따져야 하므로 BFS가 맞는듯
*/

/*구현
1. 배열에 1로 넣는다
2. 배열 시작부분에서 끝까지, 최대 625번 for문 돌린다.
3. visited도 2차원배열로 만들어서, visited를 검사한다.
*/

/* 코딩 - BFS

*/
/*느낀점
*/
#include <iostream>
#include <queue>

using namespace std;
//전역변수
int N;
int **graph;
int **visited;

queue<int> x_que;
queue<int> y_que;

//델타
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int apt_cnt = 0;
int danji_idx = 0;
int danji_cnt[63];


void BFS(int node_x,int node_y)
{
	if (visited[node_x][node_y] == 1) {
		x_que.pop();
		y_que.pop();
		return;
	}

	visited[node_x][node_y] = 1;
	apt_cnt++;


	int new_x;
	int new_y;

	for (int i = 0; i < 4; ++i) {
			
		if (node_x == 0 && dx[i] == -1) continue;
		else new_x = node_x + dx[i];
		
		if (node_y == 0 && dy[i] == -1) continue;
		else new_y = node_y + dy[i];
		
		cout << new_x << '\n';
		cout << new_y << '\n';

		if (graph[new_x][new_y] == 1) {
			x_que.push(new_x);
			y_que.push(new_y);


		}
	}
	
	while (!x_que.empty() && !y_que.empty())
		BFS(x_que.front(), y_que.front());

	if (x_que.empty() && y_que.empty()) {
		danji_cnt[danji_idx] = apt_cnt;
		apt_cnt = 0;
		danji_idx++;
	}
	
}

void graphcheck();

void visitcheck();

int main()
{
	scanf("%d",&N);
	graph = new int*[N];
	for (int i = 0; i < N; ++i) {
		graph[i] = new int[N]();
		for (int j = 0; j < N; ++j)
			scanf("%1d", &graph[i][j]);
	}

	visited = new int*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new int[N]();
	
	//cout << "bug1";여기까진 잘 됨
	//graphcheck();
	//visitcheck();

	//배열 처음부터 순회
	for (int i = 0; i < N; ++i)
		for (int j = 0; i < N; ++j)
			if (graph[i][j] == 1)
				BFS(i,j);
	cout << "bug2";
	
	for(int i = 0; i < danji_idx;++i)
		printf("%d",danji_cnt[i]);
	cout << "bug3";
	return 0;
}

void graphcheck() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cout << graph[i][j];
}

void visitcheck() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cout << visited[i][j];
}