//제목 : 숨바꼭질
//목적 : 수직선 상에서 동생의 위치를 가장 빨리 찾는데 걸리는 시간
//조건 : 수직선 범위는 0~100,000

/* 아이디어 : 마찬가지로, 이걸 왜 BFS로 풀어야 하는지 생각부터 하는게 우선이다.
1. 현재 시점에서 이동가능한 경우의 수는 3가지임
2. 즉 현재 시점에서 자식이 3개인 트리를 그리고 도착점을 검색하는 문제로 치환가능
3. 최소시간을 찾아야 하므로 BFS를 써야 함
*/

/*구현 :
1.수직선이므로 1차원배열로 구현가능

*/

#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { 0 };

int BFS(int start, int end)
{
	int time = 0;
	if (start == end) return time;//바로 찾는경우 필요없음
	visited[start] = true;
	
	queue<int> route;
	queue<int> timeQue;

	route.push(start);
	timeQue.push(time);

	while (!route.empty())
	{
		start = route.front();
		time = timeQue.front();

		route.pop();
		timeQue.pop();

		int ns = start + 1;//+1하는 경우
		if (ns <= 100000 && ns >= 0){
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		ns = start - 1;//-1하는 경우
		if (ns <= 100000 && ns >= 0) {
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		
		ns = start*2;//-1하는 경우
		if (ns <= 100000 && ns >= 0) {
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		
	}
	
	
}

int main()
{
	int N, K;

	cin >> N >> K;
	
	cout << BFS(N, K);
	//return 0;
}
