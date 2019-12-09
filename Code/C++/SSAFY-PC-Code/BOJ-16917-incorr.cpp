//제목 : 양념 반 후라이드 반
//목적 : 양념 X마리, 후라이드 Y마리를 살 때 가장 작은 가격으로 사는 법
//조건 : 가격은 각각 최대 5천원, 마리수는 최대 10만마리까지 가능

/*아이디어 : 말이 양념반 후라이드반이지 사실상 동전 선택
1. 양념 후라이드를 pair로 만듬
2. 재귀적으로 DFS로 pair를 넘기면서 추가
3. X,Y가 모두 만족되면 탈출
->이때, X Y를 소수로하면 애매하므로 *2해서 사용
*/


/*구현 :
1. 일종의 pair로 생성
2. 양념을 dx, 후라이드를 dy로 선언
3. bfs돌면서 체크?
*/

/*문제점 :
1. 마리수가 10만마리이므로, DFS시 depth가 깊어져 메모리 초과 가능
->cnt를 넘겨주지 않고 진행한다면? 그래도 메모리 초과
2. BFS로 하면? 
->잘못 짰는지 몰라도 메모리 초과
*/

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef struct {
	int a, b, c;
}CHICKEN;
int X2,Y2;
int A, B, C;
int da[] = { 1,0,0};
int db[] = { 0,1,0};
int dc[] = { 0,0,1};
pair<int, int> chickenCnt;
priority_queue<int, vector<int>, greater<int>> costQueue;


void select_chicken_dfs(int a, int b, int c)
{
	if ((2*a+c >= X2) && (2 * b + c >= Y2)) {//조건 달성시
		int sum = a * A + b * B + c * C;
		costQueue.push(sum);
		return;
	}
	
	if (a > X2 || b > Y2) return;

	for (int i = 0; i < 3; ++i) {
		int na = a + da[i];
		int nb = b + db[i];
		int nc = c + dc[i];

		select_chicken_dfs(na, nb, nc);
	}
}

void select_chicken_bfs(int x,int y)
{
	queue<pair<int,int>> route;
	queue<CHICKEN> route_chick;

	CHICKEN chic = { 0,0,0 };

	route.push(make_pair(x, y));
	route_chick.push(chic);
	
	do {
		x = route.front().first;
		y = route.front().second;
		chic = route_chick.front();
		route.pop();
		route_chick.pop();

		if (x >= X2 && y >= Y2) {
			int sum = chic.a * A + chic.b * B + chic.c * C;
			costQueue.push(sum);
			break;
		}


		for (int i = 0; i < 3; ++i) {
			int na = chic.a + da[i]; int nb = chic.b + db[i]; int nc = chic.c + dc[i];
			int nx = 2*na + nc; int ny = 2*nb + nc;
			if (2*na <= X2 || 2*nb <= Y2 || nc <= X2 || nc <= Y2) {
				chic.a = na; chic.b = nb; chic.c = nc;
				route.push(make_pair(nx, ny));
				route_chick.push(chic);
			}
		}

	} while (!route.empty());

}
int main()
{
	cin >> A >> B >> C >> X2 >> Y2;
	X2 *= 2;
	Y2 *= 2;
	//cout << X2 << ' ' << Y2;

	//select_chicken_dfs(0, 0, 0); //에러 오짐
	select_chicken_bfs(0, 0);

	while (!costQueue.empty()) {
		cout << costQueue.top()<<'\n';
		costQueue.pop();
	}
	//cout << costQueue.top();
}
