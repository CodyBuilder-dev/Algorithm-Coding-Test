//제목 : 드래곤 커브
//목적 : 격자 위에 드래곤 커브가 주어질 때, 드래곤 커브에 속하는 네모를 찾기
//조건 : 커브는 최대 20개이다. 시작점의 범위가 0부터 100, 세대는 10까지, 격자크기는 아직 알 수 없는듯
//길이가 2배씩 늘어나므로 2^10 최대 1024. 격자크기는 아마 최대 1500x1500

/*아이디어 : 드래곤 커브의 시작점만 주어지므로, 직접 만들수밖에 없음
1. 드래곤 커브 만들기
->종점 체크/이전세대 벡터 배열 거꾸로/90도 돌린 후 방향 반대->종점에서 벡터따라 이동
2. 네모 체크
-> 0,0 0,1 1,0 1,1 네점 모두 visited면 네모 1개 추가
*/

/*구현
1. 종점 좌표 : pair
2. 방향 배열 : 아무 컨테이너나
3. 방향 좌표 : dy,dx
4. 방문 체크 : visited
*/

/*느낀 점
1. for문에서 조건이 i<N인 경우, i== N-1인 마지막 루프 후에도, ++문은 한번더 실행된다는 것을 잊지 말 것
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int board[101][101];
bool visited[101][101];

int dy[] = {0,-1,0,1};//동 북 서 남
int dx[] = {1,0,-1,0};
int dir;

vector<int> route;
pair<int, int> finalPoint;
int routeIndex; //전체 route에서 현재 세대의 위치를 나타내는 인덱스
int generation;

int squareCnt;

void append_route()
{
	for (int i = route.size() - 1; i >= 0; --i) {
		int newdir = (route[i] + 1) % 4; //90도 반시계 회전
		route.push_back(newdir);
	}

	/*for (int i = 0; i < route.size(); ++i)
		cout << route[i];
	cout << '\n';
	cout << "routeIndex" << routeIndex << '\n';*/
}

void check_square()
{
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (visited[i][j] == true && visited[i + 1][j] == true && visited[i][j + 1] == true && visited[i + 1][j + 1] == true)
				squareCnt++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) { //각 드래곤 커브에 대해 그리기
		routeIndex = 0;
		route.clear();

		cin >> finalPoint.second >> finalPoint.first >> dir >> generation;
		visited[finalPoint.first][finalPoint.second] = true;
		route.push_back(dir);
		//cout << "start "<< finalPoint.first << ',' << finalPoint.second << '\n';
		
		for (int j = 0; j <= generation; ++j) {
			if (j == 0) {
				finalPoint.first += dy[dir];
				finalPoint.second += dx[dir];
				visited[finalPoint.first][finalPoint.second] = true;
				//cout <<"gen0 "<< finalPoint.first << ',' << finalPoint.second << '\n';
				routeIndex++;
			}
			else {
				append_route();
				for (routeIndex; routeIndex < route.size(); ++routeIndex) {
					finalPoint.first += dy[route[routeIndex]];
					finalPoint.second += dx[route[routeIndex]];
					//cout << "gen" << j << ' ' <<finalPoint.first <<',' <<finalPoint.second<<'\n';
					visited[finalPoint.first][finalPoint.second] = true;
				}
			}
		}
		


	}

	check_square();
	cout << squareCnt;
}




