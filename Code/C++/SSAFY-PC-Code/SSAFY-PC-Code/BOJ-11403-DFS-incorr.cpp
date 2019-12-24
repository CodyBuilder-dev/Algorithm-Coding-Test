//제목 : 경로찾기
//목적 : 그래프의 인접행렬이 주어졌을 때, 이를 해석하여 원하는 경로가 있는지 찾는 문제

//조건 : 정점개수는 100개, 즉 인접행렬은 100x100. 출력도 인접행렬 형식으로 출력해야 함에 주의

/*아이디어-DFS : 처음으로 배열이 아니라 그래프 탐색
0. 0->1로 가는 경로를 찾는데, 01230, 0124X이라 치자
1. 0번째 행을 검사한다
2. 1번째 열을 검사한다. 0이면 넘어간다. 1이면 바로 해당열 재귀
3. 2번째 열 검사. 0이면 다음 열 검사, 1이면 바로 해당열 재귀

4. 2번째 행도 1번째 열 검사. 1이면 넘어감, 0이면 또 반복..

5. 모든행을 다 돌았는데도 1로 가는 경로가 없다?! 0
6. 0->2, 0->3에 대해 처음부터 무한반복
(근데 이럼 시간초과 걸릴거같은데. 일단 무식하게라도 구현 고고)
*/

/*느낀점
1.탐색과 삽입삭제 동시에 해야되는 경우, 즉 이떄까지 모든 경로를 다 확인해야 되는 경우는
스택보단 벡터가 낫다.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
int **graph;
int **resultGraph;
int *routecheck;

vector<int> routestack;

void search_route(int start, int end) //start에서 end까지의 경로 파악
{
	/*탈출조건을 정확하게 설정해야함
	1. 경로가 발견되었을 때
	2. 경로가 없다면, 다른 경로를 찾았을 때
	3. 다른 경로조차 없을 때
	*/
	//탈출조건 1. 경로가 발견될 경우 지금까지의 모든 route 다 삽입
	routecheck[start] = 1;
	routestack.push_back(start);

	if (graph[start][end] == 1 || resultGraph[start][end] == 1) {
		resultGraph[start][end] = 1;
		for (int i = 0; i < routestack.size(); ++i){
			int temp = routestack[i];
			resultGraph[temp][end] = 1;
		}
		routestack.pop_back();
		return;
	}
	//탈출조건2. 경로가 없다면 안가본 다른 경로를 찾는다.
	else {
		
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (routecheck[i] == 0 && graph[start][i] == 1)
				sum+=1;
		if (sum != 0) {
			for (int i = 0; i < N; ++i) //start로부터 다른 점 모두 탐색
			{
				if (routecheck[i] == 0 && graph[start][i] == 1)
					search_route(i, end);
			}
		}
		else { //탈출조건3 : 다른 경로고 뭐고 아무것도 없을 때
			
			for (int i = 0; i < routestack.size(); ++i) {
				int temp = routestack[i];
				resultGraph[temp][end] = 0;
			}
			routestack.pop_back();
			return;
		}
	}

	
}

int main()
{
	cin >> N;

	graph = new int*[N];
	resultGraph = new int*[N];
	for (int i = 0; i < N; ++i){
		graph[i] = new int[N]();
		resultGraph[i] = new int[N]();
	}
	routecheck = new int[N](); //현재 점에 도달한적 있는가 체크
	

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];

	//여기부터 본격적인 코드 작성 시작
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			search_route(i, j);
			for (int k = 0; k < N; ++k)
				routecheck[k] = 0;
		}
	
	//cout << '\n';
	
	//결과 행렬 출력
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			cout << resultGraph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}


