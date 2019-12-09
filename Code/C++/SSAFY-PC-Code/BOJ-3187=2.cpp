//제목 : 양치기 꿍
//목적 : 울타리 안 양과 늑대 중 어느 쪽이 얼마나 살아남는지 구하시오
//조건 : 영역은 최대 250x250 = 62500

/*아이디어 : BFS문제는, 대체 왜 BFS로 접근해야 하는지 그 이유를 밝히는게 중요함
1. 울타리로 둘러쌓여 있으므로, 울타리 내의 상황을 아는 것이 중요함
2. 사실 이건 DFS로 해도 될거같긴 함
3. 그럼에도 불구하고, 2차원 배열 상에서 별로 깊지 않게 탐색하므로 BFS 고고
*/

/*구현
1. BFS구현. 이때 각 y,x좌표는 pair로 구현하면 편한 듯
2. 보드는 int의 2차원 배열로 구현
3. 값 받아들이기는 어떻게 해야될지 좀 헷갈리긴한데 일단 scanf
4. 배열을 for문으로 순회하면서 BFS시전
*/

#include <iostream>

using namespace std;

int R, C;
int** board;
int** visited;

void BFS(int y, int x)
{
	/*구현 순서 기억하기
	1. 현재 위치를 visited에 넣는다
	2. 현재 위치에서 작업(양,늑대 세기)을 수행한다.
	3. 현재 위치를 큐에 일단 한번 넣는다(empty를 막기 위함) 
	4.큐에서 꺼내서 현재좌표로 설정한다.
	4. 현재 위치 주변의 4점을 탐색한다.
	5. 각 점이 방문되지 않았을 경우, 각 점을 방문하고 작업을 수행한 뒤 visited 표기한다.
	6. visited 표기한 후에는 queue에 넣는다.
	7. 
	*/
}
int main()
{
	cin >> R >> C;

	board = new int* [R];
	for (int i = 0; i < R; ++i)
		board[i] = new int[C];
	int temp;

	for (int i = 0; i < R; ++i)
		for (int j = 0; i < C; ++i) {
			scanf("%d", &temp);
			board[i][j] = temp;
		}
	return 0;
}

