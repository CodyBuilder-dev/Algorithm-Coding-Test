//제목 : 경로찾기
//목적 : 그래프의 인접행렬이 주어졌을 때, 이를 해석하여 원하는 경로가 있는지 찾는 문제

//조건 : 정점개수는 100개, 즉 인접행렬은 100x100. 출력도 인접행렬 형식으로 출력해야 함에 주의

/*아이디어-DFS2
1. 그냥 DFS 단순하게 수행
2. 마지막에 visited를 검사함
3. 검사해서 체크된 놈들은 다녀왔다는 뜻이므로 1로 해주면 됨;
*/

/*느낀점
1.탐색과 삽입삭제 동시에 해야되는 경우, 즉 이떄까지 모든 경로를 다 확인해야 되는 경우는
스택보단 벡터가 낫다.
2. DFS를 돌린 후, visited를 검사하면 유향그래프나 무향그래프에서 직접 연결되지 않고
간접적으로 연결된 관계도 파악할 수 있다.(그래프에서의 DFS 완료!)
->이를 다른문제에 응용가능할듯
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
int **graph;
int **resultGraph;
bool *routecheck;

void search_route(int start, int end) //start에서 end까지의 경로 파악
{
	/*탈출조건 굳이 스택 넣고 복잡하게 짤 필요가 없음
	그냥 보통 DFS처럼 돌면 됨
	*/
	for (int i = 0; i < N; ++i) {
		if (routecheck[i] == false && graph[start][i] == 1) {
				routecheck[i] = true;
				search_route(i, end);
		}
	}
}
bool check_path(int end)
{
	if (routecheck[end] == false) return false; //DFS결과 end에 도달했으면 true, 도달 못했으면 false
	else true;//return 안 적어서 에러;;;
}

int main()
{
	cin >> N;

	graph = new int*[N];
	resultGraph = new int*[N];
	routecheck = new bool[N](); //현재 점에 도달한적 있는가 체크
	for (int i = 0; i < N; ++i) {
		graph[i] = new int[N]();
		resultGraph[i] = new int[N](); 
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];

	//여기부터 본격적인 코드 작성 시작
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			
			search_route(i, j);
			
			if(check_path(j) == true) 
				resultGraph[i][j] = 1;
			//if(routecheck[j] == true) <-오류
				//resultGraph[i][j] = 1;
			else resultGraph[i][j] = 0; <정답
			for (int k = 0; k < N; ++k)
				routecheck[k] = false;
			
		}

	//cout << '\n';

	//결과 행렬 출력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << resultGraph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}


