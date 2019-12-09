//제목 : 타임머신
//목적 : 1번 도시에서 타임머신을 타고 다른 도시로 이동하는 방법
/*조건 : 도시는 최대 500개, 버스 노선은 최대 6천개, 시간값은 최대 -1만~1만
시간복잡도 : 플루이드와샬 = 500^3 = 1억2500만(애매?)
크루스칼 = 500*6000 = 3백만 (ㄱㄴ)
공간복잡도 = 모든간선 다 1만이면 1만*500 = 500만(ㄱㄴ)
*/

/*아이디어2 : 벨만-포드 적용
1.기본적인 벨만-포드 뼈대
2.사이클 발생시 대처
3. 도달하지 못할 경우 대처
*/

#include <iostream>
#define INF 987654321

using namespace std;

int N, M;
int graph[500][500];
int dist[500];

void init_inf()
{
	for(int i=0 ; i<N;++i)
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			graph[i][j] = INF;
		}

}
void input()
{
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;

		if (graph[start - 1][end - 1] > cost) graph[start - 1][end - 1] = cost;
	}
}

void bellman(int start)
{
	//출발노드 선택
	//간선 선택
	//간선거리 비교
	for (int i = 0; i < N; ++i) {
		if (i == start) continue;
		dist[i] = INF; //거리 초기화
	}

	//for (int i = 1; i < N; ++i)
	//	cout << dist[i] << '\n';

	for(int s = 0; s<N;++s)
		for (int e = 0; e < N; ++e) {
			if (s != e && graph[s][e] != INF) {
				if (dist[e] > dist[s] + graph[s][e]) dist[e] = dist[s] + graph[s][e];
			}
		}
}
int main()
{
	cin >> N >> M;
	init_inf();
	input();
	bellman(0);
	for (int i = 1; i<N;++i)
		cout << dist[i] << '\n';

}