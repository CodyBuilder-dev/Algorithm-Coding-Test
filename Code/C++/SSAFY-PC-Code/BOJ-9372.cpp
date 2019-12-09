//제목 : 상근이의 여행
//목적 : N개국을 여행할 때, 가장 적은 종류의 비행기로 여행하는 루트 구하기

/*아이디어 : 그래프의 노드간 연결상태가 주어질 때, 이로부터 모든 루트방문 위한 최소 방문수
최소종류를 구하는 것이므로 BFS 가즈아
1. 인접행렬 그리기
2. BFS로 구하기
3. 
*/
/*구현 :
1.국가순서 1,2,3...N임에 주의
*/
/*느낀점 : 
1. 그래프에 BFS를 적용할 때는 굳이 visited를 2차원으로 만들 필요 없이 1차원으로 충분
2. 이거 DFS로 구하는 법은 없나?? 연구 필요
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int T;
int N, M;
bool **graph;
bool *visited;


int BFS(int y)
{
	visited[y] = true;
	int time = 0;
	queue<int> route;
	queue<int> timeQue;
	route.push(y);
	timeQue.push(time);

	while (!route.empty()) {
		y = route.front();
		time = timeQue.front();

		route.pop();
		timeQue.pop();

		for(int i =0;i<N;++i)
			if(visited[i] == false && graph[y][i] == true){
				visited[i] = true;
				route.push(i);
				timeQue.push(time + 1);
			}
	}
	return time;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i){
		cin >> N >> M;

		graph = new bool*[N];
		visited = new bool[N];

		for (int j = 0; j < N; ++j){
			graph[j] = new bool[N];
		}

		for (int j = 0; j < M; ++j) {
			int start, end;
			cin >> start >> end;
			graph[start-1][end-1] = true;
			graph[end-1][start-1] = true;
		}
		int minimum=10000;
		for(int k = 0 ; k<N;++k)
			minimum = min(minimum,BFS(k));
		cout << minimum << '\n';
	}
	return 0;
}