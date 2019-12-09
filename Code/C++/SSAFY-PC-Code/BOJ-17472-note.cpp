//제목 : 다리 만들기2
//목적 : 섬간의 최단 다리를 만들고, 모든 섬을 다 돌때 최단거리를 구하여라
//조건 : 보드의 크기는 최대 10x10, 섬의 개수는 최대 6개, 다리길이는 최소 2
//특이점 : 2019.09 삼성 상시 역량테스트 A 기출

/*아이디어 :
1. 섬의 정보 입력 받기
-> 2차원배열에 받아두기

2. 섬의 영역들을 모두 찾고 번호를 매기기.
-> BFS를 이용, 2차원배열 하나 추가해서 섬 번호 붙여두기
-> 섬의 가장자리를 체크해야 할 필요는 없음

3. 섬간의 거리를 원소로 갖는 인접행렬 만들기
-> DFS 이용해서 다리를 뻗어보고 그 다리의 거리를 찾기
-> 섬의 모든 edge들로부터 모든 방향으로 다 다리 뻗어보는 식으로 진행

4. 인접행렬을 DFS로 탐색하여 4개 다 도는 최단거리(매우 비추천. 시도X)
-> 앞에서 BFS로 멘탈 갈리고 왔는데 여기서 또 DFS를 할 필요 없음
-> 코드가 진짜 매우 심각하게 더러워짐

4. 유니언파인드와 크루스칼을 이용한 간단한 MST생성
-> 유니언 파인드 함수들 작성해두기
-> 크루스칼을 쓰려면, 노드가 아닌 '간선'의 정보를 얻어야 하므로
인접행렬을 탐색하며 priority queue에 간선정보 저장
-> 크루스칼을 돈다
-> 돌고나서 "반드시" 모든 섬들이 연결되었는지 확인한다.
*/

/*느낀점 :
1.BFS -> DFS -> 크루스칼 3단콤보 문제
(이젠 2중을 넘어서 3중까지 대비해야할 필요 있을수 있음;;;;)

2.크루스칼을 쓰기 전이나 후, 반드시 모든 점이 연결이 가능한지부터 for문 유니언으로 확인
->모든 점이 연결이 가능하지 않은 경우, 크루스칼을 쓰면...
->1. 연결상태 상관없이 제일 짧은놈을 오름차순 선택
->2. 제일 짧은 놈들순으로 연결
->3. 최종적으로는 모든 점들이 안 연결되어 있는 상태가 될 수 있음
*/
#include <iostream>
#include <utility>
#include <queue>

#define MAX_ISLAND 6 + 1
#define INF 987654

using namespace std;

//변수
int N, M;
int map[10][10]; // 지도
int num; //섬 개수
int islandNum[10][10]; //섬별로 숫자 매겨서 저장용 배열
bool visited[10][10]; // 방문체크용
int islandDist[MAX_ISLAND][MAX_ISLAND]; // 섬사이 거리 인접행렬
int parent[MAX_ISLAND];
int dy[] = { 1,0,-1,0 }; //북 서 남 동
int dx[] = { 0,-1,0,1 };

int sum = 0;
priority_queue <pair<int, pair<int, int>>,vector< pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;

//섬 입력 받는 함수
void input_island()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];

	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << map[i][j] << ' ';
	//	cout << '\n';
	//}
}

//섬 정보 받는 BFS
void check_island_bfs(int y, int x ,int islNum)
{
	queue<pair<int, int>> Q;
	visited[y][x] = true;
	islandNum[y][x] = islNum;
	Q.push(make_pair(y, x));

	do {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				if(visited[ny][nx] == false && map[ny][nx] == 1)
				{
					visited[ny][nx] = true;
					islandNum[ny][nx] = islNum;
					Q.push(make_pair(ny, nx));

				}
		}
	} while (!Q.empty());
}
//섬의 엣지에서 다리 만들기 DFS
//일단 다리생성이 시작되면, 같은 방향으로 계속 파고들어서 만들어간다.
//가다가 다른섬 만나면 멈추고 음...그 섬간의 거리 저장쓰
void make_bridge_dfs(int y, int x, int start, int dir,  int dist)
{	
	int ny = y + dy[dir]; int nx = x + dx[dir]; //해당 방향 검사
	if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
		//if (map[ny][nx] == 0) //바다위면 다리 만들기(X)
		if(islandNum[ny][nx] == 0) //시작섬이랑 다르면 다리 만들기
			make_bridge_dfs(ny, nx, start, dir, dist + 1);

		if (islandNum[ny][nx] == start) //한칸 더 갔는데 똑같은 시작섬이면
			return;

		if (islandNum[ny][nx] != start) { //한칸 더 뻗어보니 다른 섬이면
			int end = islandNum[ny][nx];
			if (dist < 2) return; //다리길이 짧으면 탈출
			if (islandDist[start][end] > dist) { //현재까지 거리보다 짧으면 갱신
				islandDist[start][end] = dist;
				islandDist[end][start] = dist;
			}
			return;
		}
	}
}


//유니언-파인드, 크루스칼

int Find(int child)
{
	if (parent[child] == child) return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return  p;
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

//인접행렬에 크루스칼 적용
void kruscal()
{
	for (int i = 1; i <= num; ++i)
		parent[i] = i;

	while (!edgeSet.empty())
	{
		int cost, start, end;
		cost = edgeSet.top().first;
		start = edgeSet.top().second.first;
		end = edgeSet.top().second.second;
		//cout << cost << ' ' << start << ' ' << end << '\n';
		edgeSet.pop();
		
		if (!isUnion(start, end)) {
			Union(start, end);
			sum += cost;
		}
	}
	

}


int main()
{
	//map 만들기
	input_island();

	//돌면서 섬 번호 1씩 추가해서 메기기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == false && map[i][j] == 1) {
				num++;
				check_island_bfs(i, j, num);
			}
		}
	}

	//번호 잘 매겼는지 확인
	//cout << "번호매긴 배열" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << islandNum[i][j] << ' ';
	//	cout << '\n';
	//}

	//다리 길이 초기화 (섬번호는 1번부터 최대 6번까지  매겨짐에 주의
	for (int i = 1; i < MAX_ISLAND; ++i)
		for (int j = 1; j < MAX_ISLAND; ++j) {
			if (i == j) continue;
			islandDist[i][j] = INF;
		}

	//모든점 돌면서 다리 만들기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) { 
			if (islandNum[i][j] != 0) {
				for (int dir = 0; dir < 4; ++dir) { //각 점의 4방향에서 발사
					make_bridge_dfs(i, j, islandNum[i][j], dir, 0);
				}
			}
		}
	}

	//섬간 거리 출력
	//cout << "섬간 거리 \n";
	//for (int i = 1; i <= num; ++i) {
	//	for (int j = 1; j <= num; ++j)
	//		cout << islandDist[i][j] << ' ';
	//	cout << '\n';
	//}

	//섬간 경로에 크루스칼 적용
	for (int i =1 ; i<=num;++i)
		for (int j = i+1; j <= num; ++j) {
			if (i == j) continue;
			if(islandDist[i][j] != INF && islandDist[i][j] != 0){
				edgeSet.push(make_pair(islandDist[i][j], make_pair(i, j)));
			}
		}

	kruscal();

	
	//모든 선들이 다 연결되었는지 isUnion으로 확인
	bool isConnected = true;
	for (int i = 1; i <= num; ++i)
		for (int j = i + 1; j <= num; ++j)
			if (!isUnion(i, j)) isConnected = false;

	if (isConnected) cout << sum;
	else cout << -1;
			
}