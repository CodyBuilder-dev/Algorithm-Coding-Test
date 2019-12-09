//제목 : 네트워크 연결
//목적 : 모든 컴퓨터를 연결하는 방법 중 가장 최소가 되는 것을 생각하라
//조건 : 컴퓨터 최대 1000대, 선의 수 최대 10만개, 비용은 양수, 

/*아이디어 :
모든 노드를 다 연결하는 것 = 최소 스패닝 트리
최소 스패닝 트리 = BFS,DFS/크루스칼(아는게 이거뿐)/프림
여기서는 BFS사용
*/

/*구현 : 모든 정점을 시작점으로 해서 모두 연결하는 스패닝 트리 탐색 시작
스패닝트리가 완성되면 그 거리 체크
거리를 최소값과 비교
주의점!! 최소 스패닝 트리는 같은 노드가 여러번 선택되도 됨 ㅜㅜ
간선을 선택하고 점들을 집합에 넣은 후 집합의 크기가 4인지 검사하는게 맞나?
->그러려면 visited도 일차원배열 1000이 아니라, 1000x1000으로 만들어야 함
*/


#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int N, M;
int graph[1000][1000];
bool edgeVisited[1000][1000];
bool nodeVisited[1000];

set<int> nodeSet;
priority_queue<int,vector<int>,greater<int>> minDist;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if (graph[start - 1][end - 1] == 0 ) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
		}
		else if (graph[start - 1][end - 1] > cost) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
		}
	}
}
//DFS로 스패닝 트리 찾기
void find_spanning(int start , bool edge[][1000],bool node[],int cnt, int sum) 
{
	if (cnt == N-1) { //간선 n개 선택한 경우
		minDist.push(sum);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (graph[start][i] != 0 && edge[start][i] == false) { //연결이 되어 있고 간선 선택 안됨
			if (node[i] == false) { //노드도 선택 안됨

			}
			int newsum = sum + graph[start][i];
			bool newvisit[1000];
			memcpy(&newvisit[0], &visit[0], 1000);
			newvisit[i] = true;
			find_spanning(i, newvisit, cnt + 1, newsum);
		}
	}
}
//스패닝 트리 중 최소값 찾기
void find_min()
{
	//모든 경우의 수를 다 따지면서 스패닝 트리 만들기
	for (int i = 0; i < N; ++i) {//모든 정점을 시작점으로
		visited[i] = true;
		find_spanning(i, visited, 1, 0);
	}
	cout << minDist.top();
}

int main()
{
	input();
	//그래프 검사
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << graph[i][j];
		cout << '\n';
	}*/
	find_min();


}

