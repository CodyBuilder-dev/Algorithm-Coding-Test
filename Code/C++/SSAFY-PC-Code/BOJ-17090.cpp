//제목 : 미로 탈출하기
//목적 : 미로에서 탈출 가능한 칸을 찾기
//조건 : 미로의 크기는 500x500 = 250

/*아이디어 : 이거 완탐한다 치면 25만 x25만으로 개 박살남
D/BFS로 완탐을 하되, 메모이제이션으로 탈출가능한 칸에 도달하면 바로 탈출해야 함
*/

/*느낀점 : 
1.exit/unexit을 두개 만들어도 되는가? ->가능
2.탐색 중 과거의 경로는 어떻게 저장하는가?
-> 배열에 하면 무조건 터짐, 
->벡터? 대부분 가능
->데큐? 가능
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M;

char board[500][500];
bool visited[500][500]; //이번 bfs에 본 애들

bool exitable[500][500];
bool unexitable[500][500];

bool exited;
int dy[] = { 1,0,-1,0 }; //남 동 북 서
int dx[] = { 0,1,0,-1 };
//deque<pair<int, int>> pastRoute;
vector<pair<int, int>> pastRoute;
void find_path_dfs(int y, int x)
{
	visited[y][x] = true;
	pastRoute.push_back(make_pair(y, x));

	int ny, nx;
	switch (board[y][x]) {
	case 'D':
		ny = y + dy[0]; nx = x + dx[0];
		if (ny >= N || ny <0 || nx >= M || nx < 0) { //나갔는데 탈출 되는 경우
			/*for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j) {
					if (visited[i][j] == true) exitable[i][j] = true;
					visited[i][j] = 0;
				}*/ //이따위로 하면 시간초과 오지게 남
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //나가진 않았는데 그곳이 나가지는곳인거 아는경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //나가진 않았는데 그곳이 안 나가지는 곳인 경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //아직 안 가본 곳인 경우
			find_path_dfs(ny, nx);
		break;
	case 'R':
		ny = y + dy[1]; nx = x + dx[1];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //나갔는데 탈출 되는 경우
		/*for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == true) exitable[i][j] = true;
				visited[i][j] = 0;
			}*/ //이따위로 하면 시간초과 오지게 남
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //나가진 않았는데 그곳이 나가지는곳인거 아는경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //나가진 않았는데 그곳이 안 나가지는 곳인 경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //아직 안 가본 곳인 경우
			find_path_dfs(ny, nx);
		break;
	case 'U':
		ny = y + dy[2]; nx = x + dx[2];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //나갔는데 탈출 되는 경우
			/*for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j) {
					if (visited[i][j] == true) exitable[i][j] = true;
					visited[i][j] = 0;
				}*/ //이따위로 하면 시간초과 오지게 남
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //나가진 않았는데 그곳이 나가지는곳인거 아는경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //나가진 않았는데 그곳이 안 나가지는 곳인 경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //아직 안 가본 곳인 경우
			find_path_dfs(ny, nx);
		break;
	case 'L':
		ny = y + dy[3]; nx = x + dx[3];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) { //나갔는데 탈출 되는 경우
		/*for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == true) exitable[i][j] = true;
				visited[i][j] = 0;
			}*/ //이따위로 하면 시간초과 오지게 남
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (exitable[ny][nx] == true) { //나가진 않았는데 그곳이 나가지는곳인거 아는경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				exitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}
		else if (unexitable[ny][nx] == true) { //나가진 않았는데 그곳이 안 나가지는 곳인 경우
			for (int i = 0; i < pastRoute.size(); ++i) {
				unexitable[pastRoute[i].first][pastRoute[i].second] = true;
			}
			pastRoute.clear();
		}

		else if (visited[ny][nx] == false) //아직 안 가본 곳인 경우
			find_path_dfs(ny, nx);
		break;
	}
}
//void find_path_bfs(int y, int x)
//{
//	queue<pair<int, int>> route;
//	visited[y][x] = true;
//	route.push(make_pair(y, x));
//
//	do {
//		y = route.front().first;
//		x = route.front().second;
//		route.pop();
//
//		switch (board[y][x]) {
//		case 'D': 
//			int ny = y + dy[0]; int nx = x + dx[0];
//			if(ny > N || ny <0 || nx > M || nx <0) { //탈출 가능한 경우
//				exitable[y][x] = true;
//			}
//			if(exitable[ny][nx] == true) 
//		case 'R':
//		case 'U':
//		case 'L':
//		}
//
//	} while (!route.empty());
//}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)	{
			cin >> board[i][j];
		}
	}

	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout<< board[i][j];
		}
		cout << '\n';
	}*/
	//잘 받아짐 확인


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == false) {
				find_path_dfs(i, j);
				if (!exitable[i][j]) {//탈출못한 경우 
					for (int k = 0; k < pastRoute.size(); ++k) {
						unexitable[pastRoute[k].first][pastRoute[k].second] = true;
					}
					pastRoute.clear();
				}
			}
		}

	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (exitable[i][j] == true) cnt++;

	cout << cnt;

}
