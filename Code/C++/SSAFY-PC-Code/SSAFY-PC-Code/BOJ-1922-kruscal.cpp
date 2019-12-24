//제목 : 네트워크 연결
//목적 : 모든 컴퓨터를 연결하는 방법 중 가장 최소가 되는 것을 생각하라
//조건 : 컴퓨터 최대 1000대, 선의 수 최대 10만개, 비용은 최대 1만

/*아이디어 :
모든 노드를 다 연결하는 것 = 최소 스패닝 트리
최소 스패닝 트리 = DFS(쓸줄 모름)/크루스칼/프림(쓸줄 모름)
여기서는 크루스칼 사용
*/

/*구현 : 
1.간선
1.1구조체로 구현
1.2구조체의 priority queue 구현
->구현 방법은 어떻게?
->구현시 자동 정렬은 어떻게? 무슨 원소 기준으로?

1.2 걍 깔끔하게 페어로 하고 포기

2. 유니온 파인드
*/

//느낀점 : 노드의 유니언을 체크하는게 아니라 간선의 유니언을 체크해야함 병신

//우선순위 큐 검색 기준, 구조체에 넣으면 아~ 검색기준이 없구나
//comp 구조체를 따로 만들어주고, operator()불 함수를 만들어 줘야 함
// pq가 comp를 매번 호출하면서
//less로하면 max heap
//greater

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

//typedef struct edge edge;
//struct edge {
//	edge *pNext;
//};

//typedef struct edge{
//	int cost;
//	int start;
//	int end;
//
//	bool operator()(const edge &x, const edge &y)
//	{
//		return x.cost > y.cost;
//	}
//}EDGE;

pair<int, pair<int, int>> EDGE;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;
deque<pair<int, pair<int, int>>> MST;

int N, M;
int graph[1000][1000]; //0번부터 시작해야함에 주의
int parent[1000];

void input()
{ //인접행렬 만들기
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int start,end,cost;
		cin >> start >> end >> cost;
		if (graph[start - 1][end - 1] == 0) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
			
			EDGE.first = cost;
			EDGE.second.first = start - 1;
			EDGE.second.second = end - 1;
			edgeSet.push(EDGE);
			//cout << edgeSet.top().first << '\n';
		}
		else if (graph[start - 1][end - 1] > cost) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
			
			EDGE.first = cost;
			EDGE.second.first = start - 1;
			EDGE.second.second = end - 1;
			edgeSet.push(EDGE);
		}
	}
}

int Find(int child)
{
	if (parent[child] == child) return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
	}
}

void Union(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);

	if (left_p != right_p) parent[right_p] = left_p;
	
}

bool isUnion(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);

	if (left_p != right_p) return false;
	else return true;

}

void make_parent()
{
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	//여기서 유니온을 하면 안되지!!!!
	/*for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			if (graph[i][j] != 0) Union(i, j);*/
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
	make_parent();

	while (!edgeSet.empty())
	{
		int s, e;
		s = edgeSet.top().second.first;
		e = edgeSet.top().second.second;
		//cout << s << ' ' << e << '\n'; //여기까진 잘 들어간거 확인
		bool doUnion = isUnion(s, e);

		if (doUnion == false) { //유니언에 있지 않으면
			Union(s, e);
			MST.push_back(edgeSet.top()); //push back이 아예 안되는 듯
		}
		edgeSet.pop();
	}

	//cout << MST.size();
	int sum = 0;
	for (int i = 0; i < MST.size(); ++i) {
		sum += MST[i].first;
	}
	cout << sum;
}

