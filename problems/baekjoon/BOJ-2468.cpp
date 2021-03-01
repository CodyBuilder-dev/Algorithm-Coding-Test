//제목 : 안전 영역
//목적 : 비의 양보다 높이가 낮아 잠기는 지역과 잠기지 않는 지역을 구분하여 잠기지 않는 영역의 개수를 구하라
//조건 : 땅은 최대 100x100 

/*아이디어 : 전형적인 배열 DFS/BFS탐색
1. 역시 DFS를 스택 사용해서 사용하자
2. 내리는 비의 양을 정한다. 
3. 해당 량에 대해 우선 전체를 탐색하면서 침수되는 지역을 찾아서 체크
4. 그리고 다시 탐색하면서 침수되지 않은 지역을 찾자.
*/

/*느낀점 : 
1.배열 다쓰고나서 초기화하는 방법 알아야 함
2.침수구역 찾을 때 그냥 for문 돌려도 됐었네 ㅋㅋㅋ
*/
#include <iostream>
#include <stack>
#include <utility>
#include <cstring>

using namespace std;

int N;
int **land;
bool **flooded;
bool **visited;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

void check_flooded(int y , int x, int rain)
{
	//1. flooded 체크
	flooded[y][x] = true;

	//2. 할일 하기

	//3. 스택에 넣기
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));

	//4. while문 쓰기
	while (!route.empty())
	{
		//5. top을 받은 후 바로 pop하거나 아니면 나중에 flag로 pop하거나
		y = route.top().first;
		x = route.top().second;
		route.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (flooded[ny][nx] == false && land[ny][nx] <= rain)
				{
					flooded[ny][nx] = true;
					route.push(make_pair(y, x));
					route.push(make_pair(ny, nx));

					break;
				}
			}
		}
	}
}

void check_saved(int y, int x, int rain)
{
	//1. flooded 체크
	visited[y][x] = true;

	//2. 할일 하기

	//3. 스택에 넣기
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));

	//4. while문 쓰기
	while (!route.empty())
	{
		//5. top을 받은 후 바로 pop하거나 아니면 나중에 flag로 pop하거나
		y = route.top().first;
		x = route.top().second;
		route.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N)
			{
				if (visited[ny][nx] == false && land[ny][nx] > rain)
				{
					visited[ny][nx] = true;
					route.push(make_pair(y, x));
					route.push(make_pair(ny, nx));

					break;
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	land = new int*[N];
	flooded = new bool*[N];
	visited = new bool*[N];
	for (int i = 0; i < N; ++i){
		land[i] = new int[N];
		flooded[i] = new bool[N]();
		visited[i] = new bool[N]();
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> land[i][j];

	//land 확인 - okay(주석처리는 ^e상태에서 c. 해제는 ^e상태에서 u)
	//for (int i = 0; i < N; ++i)
	//	for (int j = 0; j < N; ++j)
	//		cout << land[i][j];

	int area = 0;
	int maxima = 0;
	//여기서부터 DFS 시작
	for (int i = 0; i <= 100; ++i) {//비의 양
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
			{
				if (flooded[j][k] == false && land[j][k] <= i)
					check_flooded(j, k, i);
			}
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
			{
				if (visited[j][k] == false && land[j][k] > i){
					check_saved(j, k,i);
					area++;
				}
			}
		maxima = (maxima < area) ? area : maxima;
		area = 0;
		
		/*for(int  j = 0; j<N;++i)
			fill_n(flooded[i], N, false);
		*/
		//fill_n(&visited[0][0], N*N, false); <-for문 없이 혼자 쓰면 미작동

		//memset(flooded, 0, N*N); 매우 느린듯? 뭐지
		//memset(visited, 0, N*N);
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				flooded[j][k] = false;
	
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				 visited[j][k] = false;
			
	}
	for (int i = 0; i < N; ++i)
	{
		delete[] land[i];
		delete[] flooded[i];
		delete[] visited[i];
	}
	delete[] land;
	delete[] flooded;
	delete[] visited;
	cout << maxima;
	return 0;
}

