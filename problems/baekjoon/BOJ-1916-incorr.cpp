//제목 : 최소비용 구하기
//목적 : 도시에서 다른 도시로 이동하는데 드는 최소 비용
/*조건 : 도시는 최대 1000개, 비용은 최대 10만원,
--같은 노선이 여러개 있을 수 있음!!--
*/

/*아이디어1 : 플로이드 와샬 알고리즘으로 인접행렬 다 구하기
*/

/*문제점 : 도시가 10^3개이므로
플로이드 와샬은 O(10^9)로 CPU동작 어림잡아 fail
*/

#include <iostream>

using namespace std;

int N, M;
int dist[1000][1000];

void inf()
{
	for (int i = 0; i<N;++i)
		for(int j = 0; j<N;++j)
			if(i!=j) dist[i][j] = 987987987;
}

void floyd()
{
	for (int m = 0; m < N; ++m)
		for (int s = 0; s < N; ++s)
			for (int e = 0; e < N; ++e)
				dist[s][e] = (dist[s][m] + dist[m][e] > dist[s][e]) ? dist[s][e] : dist[s][m] + dist[m][e];
}

int main()
{
	cin >> N >> M;

	inf();

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if(dist[start-1][end-1]>cost) dist[start - 1][end - 1] = cost;	
	}

	//dist 잘 들어갔나 검증
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < N; ++j)
	//		cout << dist[i][j] << ' ';
	//	cout << '\n';
	//}


	floyd();

	int start, end;
	cin >> start >> end;

	cout << dist[start - 1][end - 1];

}