//제목 : 최소 스패닝 트리
//목적 : 그래프가 주어졌을 때, 최소 스패닝 트리를 구하기
/*조건 : 정점은 최대 1만개, 간선은 최대 10만개
->입력받을 개수가 많으므로 입출력 최적화 필요
간선 가중치는 다행히 int범위 내
*/


/*아이디어 : 전통적인 방식인 유니언 파인드-크루스칼
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int V, E;
//int graph[10001][10001]; //내가보기에 그래프 만드는거 자체가 문제임
int parent[10001];

int mstCost;

//edge들을 모아두는 pq
priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;

//입력함수
void input()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		//한번 들어온 간선 또 들어올수 있을라나?
		int s, e, c;
		cin >> s >> e >> c;
		//graph[s][e] = c;
		//graph[e][s] = c;
		//받으면서 인접행렬 뿐 아니라 pq에도 넣기
		edgeSet.push(make_pair(c, make_pair(s, e)));
	}
}

//유니언 파인드
int Find(int child)
{
	if (parent[child] == child) return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
	}
}

void Union(int left,int right)
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

//kruscal
void kruscal()
{

	//parent 초기화
	for (int i = 1; i <= V; ++i)
		parent[i] = i;

	while (!edgeSet.empty()) {
		//1.우선순위 큐에서 젤 앞에놈 빼기
		int s = edgeSet.top().second.first;
		int e = edgeSet.top().second.second;
		int c = edgeSet.top().first;

		edgeSet.pop();

		if (isUnion(s, e)) continue;
		else {
			Union(s, e);
			mstCost += c;
		}

		//2.해당 s,e가 isUnion인지 파악
		//3. 맞으면 패스, 아니면 유니언으로 묶기
		//4. 반복
	}
}

int main()
{
	input();
	kruscal();
	cout << mstCost;
}