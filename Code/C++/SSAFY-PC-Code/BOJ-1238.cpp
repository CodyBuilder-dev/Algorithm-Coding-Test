//제목 : 파티
//목적 : 파티에 참석하는 학생들 중 가장 긴 시간이 걸리는 학생 찾기
//조건 : 마을은 최대 1000개, 길은 최대 1만개,

/*아이디어 : 모든 노드에서 한 곳으로 가는 비용 비교
1. 마을이 1000개이므로 플로이드와샬은 좀 그럼
2. 모든 곳에서 한 곳으로 가는 최단경로  구하기
3. 반대로 한 곳에서 모든 곳으로 가는 최단경로 구하기
4. 더해서 최종값 연산
*/

/*아이디어 2 : 아니면 딱 그냥 깨놓고 플로이드로 풀어?
*/

#include <iostream>

#define INF 987987987

using namespace std;

int N, M, X;
int graph[1000][1000];

void inf()
{
	for(int i = 0 ; i<N;++i)
		for (int j = 0; j < N; ++j)
		{
			if (i != j) graph[i][j] = INF;
		}
}
void floyd()
{
	for (int m = 0; m < N; ++m)
		for (int s = 0; s < N; ++s)
			for (int e = 0; e < N; ++e)
				graph[s][e] = (graph[s][e] > graph[s][m] + graph[m][e]) ?
					graph[s][m] + graph[m][e] : graph[s][e];
}

int main()
{
	cin >> N >> M >> X;

	inf();

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start - 1][end - 1] = cost;

	}

	floyd();

	//여기서부터 최대시간 찾기
	//? >> X >> ?로 가는거 찾으면 됨
	int max = -123123123;
	for (int i = 0; i < N; ++i)
	{
		int dist = graph[i][X - 1] + graph[X - 1][i];
		max = (dist > max) ? dist : max;
	}

	cout << max;

	return 0;
}