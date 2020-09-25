//제목 : 거의 최단 경로
//목적 : '거의 최단 경로'를 찾기
//조건 : 도시의 개수는 최대 500개, 도로는 최대 1만개

/*아이디어 : '거의 최단 경로'의 이해
거의 최단 경로 = 최단경로에 포함된 모든 노드들을 다 빼고, 나머지로 최단경로
1. 그냥 최단경로의 노드들 구하기
2. 최단경로 노드들 다 제외
3. 남은애들로 최단경로 구하기
*/

#include <iostream>
#include <vector>

#define INF 987654

using namespace std;

int N, M;

int graph[500][500];
int dist[500];

int route[500];

bool isShortest[500];

void dijkstra(int start, int end)
{
	/*흐름 정리
	1. dist를 초기화(시작점 빼고)
	2. 안 가봤고, 가장 짧은 정점 선택
	3. 선택된 정점의 이웃정점 확인
	4. dist 갱신
	5. (경로는 언제 추가하나?)
	*/

	//dist 초기화
	for (int i = 0; i < N; ++i) {
		if (i == start) dist[i] = 0;
		dist[i] = INF;
	}

	bool visited[500] = { 0, };
	
	while (!visited[end]) { //end가 체크되기 전까지 돔. 체크되면 탈출
		//안 가봤고, 가장 짧은 정점 선택
		int min = INF, minidx;
		int order = 0;

		for (int i = 0; i < N; ++i)
		{
			if (dist[i] < min && !visited[i]) {
				min = dist[i];
				minidx = i;
			}
		}//현재 가장 짧은 정점 선택

		//가장 짧은 정점의 이웃 정점 확인
		for (int i = 0; i < N; ++i)
		{
			if (graph[minidx][i] != 0) //인접한 애들만
				if (dist[i] > dist[minidx] + graph[minidx][i]) //출발점 dist랑 최단거리 정점에서 거리랑 비교
					dist[i] = dist[minidx] + graph[minidx][i];
		}

		route.push_back(minidx);
		visited[minidx] = true;
		order++;
	}
}

int main()
{
	while (true)
	{
		cin >> N >> M; 
		if (N == 0 && M == 0) break;
		
		int start, end;
		cin >> start >> end;

		//인접행렬 생성
		for (int i = 0; i < M; ++i)
		{
			int u, v, cost;
			cin >> u >> v >> cost;
			graph[u][v] = cost;
		}
	}

	return 0;
}