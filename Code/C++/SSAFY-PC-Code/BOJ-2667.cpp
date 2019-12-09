//제목 : 단지번호 붙이기
//목적 : 2차원 배열을 순회할 때 BFS/DFS를 쓸 수 있는가
/*아이디어
1. BFS로 해봤는데 철저히 실패함
2. 어차피 최단경로 등을 쓰는 것이 아니므로, DFS를 쓰는 것이 나을수 있다.
*/

/*구현
0. 그래프 전체 탐색하다 1 만나면 DFS 시작
1. 단지 번호를 전역변수로 놔서, 배열에 저장
2. 단지 갯수를 매번 초기화 후 카운팅
3. 더이상 갈 수 잇는 곳이 없으면 DFS 종료
*/

/*느낀점
1. 배열관련 문법에서 발목 안 잡히도록 제대로 외워야 함
2. 배열 인덱스를 초과하는 경계선에선 무조건 조심해야 함
3. 전역변수를 건드릴 때는 대충 생각하지 말고 순서를 정확히 확인할 것
4. 2차원배열 2개 쓸 떄는, board랑 visited 잘 쓰고 있는지 확인하기

*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int **board;
int **visited;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int danji_num = 0;
int apt_cnt[70] = {0};
int cnt = 0;

void DFS(int x, int y)
{
	//cout << "bug2_dfs"; 정상작동
	if (x >= N || y >= N || x < 0 || y < 0) return;
	if (visited[x][y] != 0) return;
	if (board[x][y] != 1) return;

	visited[x][y] = 1;
	cnt++;

	//cout << "bug3_dfs";
	//배열 인덱스 초과 에러네 이거
	for (int i = 0; i < 4; ++i)
		DFS(x+dx[i], y+dy[i]);

	apt_cnt[danji_num] = cnt;
}

int main()
{

	scanf("%d", &N);

	board = new int*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new int[N]();

	visited = new int*[N];
	for (int i = 0; i < N; ++i)
		visited[i] = new int[N]();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &board[i][j]);

	//DFS시작
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == 1 && visited[i][j] != 1) {
				DFS(i, j);

				danji_num++;
				cnt = 0;
			}
		}
	}

	cout << danji_num << '\n';
	if (danji_num == 0) cout << 0;
	else{
		sort(apt_cnt, apt_cnt + danji_num);
		for (int i = 0; i < danji_num; ++i)
			cout << apt_cnt[i] << '\n';
	}
	
}