//제목 : 영역 구하기
//목적 : 직사각형으로 분리된 영역의 갯수와 각 영역의 넓이를 구하기

/*아이디어 : 전형적인 배열 DFS/BFS문제
1.우선 직사각형 부터 구하고
2. DFS로 탐색하는 함수 만든다
3. 영역의 갯수, 넓이는 단지 구하기랑 비슷하게 구한다.
(DFS가 끝날때마다 갯수 1개씩 up. 넓이는 한칸 진행될때마다 up
*/

/*구현
1. 재귀로 짜면 재미없으니 Stack으로 한번 구현해보자
2. 좌표가 왼쪽 아래부터 (0,0)임에 주의
(x좌표가 들어오면 실제 칠해지는곳은 x, 
y좌표가 들어오면 실제 칠해지는곳은 N-1-y부터 N-y까지
*/

//느낀점 : DFS 스택으로 구현할 때 순서를 잘 기억하자
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int M, N, K;

int** board;
bool** visited;

int area = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
void DFS1(int y, int x) //플래그 없이 pop바로 때리는 방식
{
	//스택으로 짤 때 순서 기억
	//1. visit 방문하기
	visited[y][x] = true;
	//2. 노드에서 할일 하기
	area++;
	//3. 첫부분 스택에 넣기(while 반복문용)
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));
	//---여기부터 while문----
	while (!route.empty())
	{
		//4. 스택의 top부분을 현재 위치로 설정
		y = route.top().first;
		x = route.top().second;
		route.pop();
		//5.연결된 정점 돌아보면서 안 방문한곳 찾아서 스택넣기
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (visited[ny][nx] == false && board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					route.push(make_pair(y, x));
					route.push(make_pair(ny, nx));
					area++;
					break;
				}

			}

		}
		
	}
}
void DFS2(int y, int x) //플래그 쓰는 방식
{
	//스택으로 짤 때 순서 기억
	//1. visit 방문하기
	visited[y][x] = true;
	//2. 노드에서 할일 하기
	area++;
	//3. 첫부분 스택에 넣기(while 반복문용)
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));
	//---여기부터 while문----
	//4. 스택의 top부분을 현재 위치로 설정
	while (!route.empty())
	{
		y = route.top().first;
		x = route.top().second;
	
		bool flag = false;
		//연결된 정점 돌아보면서 안 방문한곳 찾아서 스택넣기
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny<M && nx >=0 && nx<N){
				if (visited[ny][nx] == false && board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					route.push(make_pair(ny, nx));
					area++;
					flag = true;
					break;
				}

			}
			
		}
		if (flag == false) route.pop();
	}

}
int main()
{
	cin >> M >> N >> K;
	
	board = new int* [M];
	visited = new bool* [M];
	for (int i = 0; i < M; ++i)
	{
		board[i] = new int[N]();
		visited[i] = new bool[N]();
	}
	/*
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j)
			cout << visited[i][j];
		cout << '\n';
	}
	*/
	

	int leftX, leftY, rightX, rightY;
	for (int i = 0; i < K; ++i)
	{
		cin >> leftX >> leftY >> rightX >> rightY;
		for (int j = M - rightY; j < M - leftY; ++j)
			for (int k = leftX; k < rightX; ++k)
				board[j][k] = 1;
	}
	/*
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			cout << board[i][j];
		cout << '\n';
	}
	*/

	int square = 0;
	vector<int> areaArray;

	//여기부터 DFS 개시
	for(int i = 0 ; i<M;++i)
		for(int j =0; j<N;++j)
			if (visited[i][j] == false && board[i][j] == 0) {
				DFS1(i, j);
				areaArray.push_back(area);
				area = 0;
				square++;
			}

	cout << square << '\n';
	sort(areaArray.begin(), areaArray.end());
	for (int i = 0; i < square; ++i)
		cout << areaArray[i] <<' ';
}