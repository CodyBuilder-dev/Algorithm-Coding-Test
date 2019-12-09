//제목 : 최소비용 구하기
//목적 : 도시에서 다른 도시로 이동하는데 드는 최소 비용
/*조건 : 도시는 최대 1000개, 비용은 최대 10만원,
--같은 노선이 여러개 있을 수 있음!!--
*/

/*아이디어3 : 다익스트라 알고리즘으로 풀기
*/

//구현 : 처음이니 그냥 배열 전체탐색으로 풀기

#include <iostream>

using namespace std;

int currNode;
int nextNode;

int N, M;
int totalDist[1000][1000];
int currDist[1000];
bool* visited;

void dijkstra(int start)
{
	currNode = start;

}
int main()
{
	cin >> N >> M;

	visited = new bool[N];

	for (int i = 0; i < M; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (totalDist[start - 1][end - 1] > cost) totalDist[start - 1][end - 1] = cost;
	}

	int start, end;
	cin >> start >> end;

	//여기서부터 코딩 시작
	
}
