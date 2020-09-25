//제목 : 알파벳
//목적 : 보드를 지나되, 여태껏 밟았던 알파벳과 같은 것이 있으면 못 지나감

/*아이디어 :
1. 2차원배열 형태의 보드탐색이므로 DFS/BFS
2. 최대 진행할 수 있는 거리를 구하므로 DFS
3. 여태껏 지나왔던 경로들의 기록을 어딘가에 저장해 두고 체크해야 함
->No! 그냥 매번마다 경로를 다 보지 말고, alphabet 명단만 체크하면 됐었음
*/

/*구현
1. 보드는 배열, DFS는 스택써서
2. 경로 기록은 끝단 삽입/삭제가 쉬워야 하고, 탐색이 쉬워야 함
(삽입삭제는 스택만한게 없는데, 탐색이 안됨)
(그냥 벡터 써보고 시간초과 뜨면 배열쓰는게 답이다)
(26칸짜리 배열이 있었음 ㅅㅂ)
3. 탐색도 그냥 귀찮으니 std::find쓸꺼,시간초과 뜨면 이분탐색쓰거나 하지뭐
find는 함수 정의상 제대로 동작하지 않는 거 발견.
직접 for문 돌려서 찾기
4. DFS에서 경로의 길이 재려면 
경로도 큐나 스택에 넣거나 
flag 쓰거나 할 듯 (논리가 너무 꼬이므로 x)
maxima에 비교해서 넣거나
*/

//느낀점 : DFS+stack에서 경로 길이 찾는게 쉬운 일이 아님

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int R, C;

char **board;
bool **visited;
bool alphabet[26];

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int cnt = 1;
int maxima = -987654321;
bool dup;

//void DFS(int y, int x)
//{
//	visited[y][x] = true;
//	stack<pair<int, int>> route; //여태껏 경로 좌표들의 스택
//	route.push(make_pair(y, x));
//	
//	vector<char> check; //여태껏 알파벳들의 배열
//	check.push_back(board[y][x]);
//	
//	stack<int> far; //여태껏 경로 길이들의 스택
//	far.push(cnt);
//	
//	while (!route.empty())
//	{
//		y = route.top().first; 
//		x = route.top().second;
//		route.pop();
//
//		cnt = far.top(); //현재지점의 길이
//		far.pop();
//	
//	
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			dup = false; //중복 있나 체크용 플래그
//			if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
//				if (visited[ny][nx] == false){ //방문 안했고
//					
//					for (int i = 0; i < check.size(); ++i)
//						if (check[i] == board[ny][nx]) {
//							dup = true; 
//							break;
//						}
//				
//					if(dup == false)//다음지점의 알파벳이 현재까지의 경로에 없으면 
//					{
//					visited[ny][nx] = true;
//					route.push(make_pair(y, x));
//					route.push(make_pair(ny, nx));
//				
//					check.push_back(board[ny][nx]);
//					far.push(cnt);
//					far.push(cnt + 1);
//			
//					break;
//					}
//				}
//			}
//			dup = true;
//		
//		}
//		if (dup == true) //for문 다 돌고 나서도  ture면 더 못감을 의미
//		{
//			maxima = (maxima < cnt) ? cnt : maxima;
//			check.pop_back();
//		}
//	}
//}

void DFS(int y, int x)
{
	visited[y][x] = true;
	alphabet[board[y][x] - 65] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C)
			if (visited[ny][nx] == false && alphabet[board[ny][nx]-65] == false)
				DFS(ny, nx);
	}
}
int main()
{
	cin >> R >> C;

	board = new char*[R];
	visited = new bool*[R];
	for (int i = 0; i < R; ++i){
		board[i] = new char[C];
		visited[i] = new bool[C]();
	}

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];

	//여기서부터 DFS 코딩 시작
	DFS(0, 0);
	cout << maxima;
	return 0;
}