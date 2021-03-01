//���� : ��� �� �Ķ��̵� ��
//���� : ��� X����, �Ķ��̵� Y������ �� �� ���� ���� �������� ��� ��
//���� : ������ ���� �ִ� 5õ��, �������� �ִ� 10���������� ����

/*���̵�� : ���� ���� �Ķ��̵������ ��ǻ� ���� ����
1. ��� �Ķ��̵带 pair�� ����
2. ��������� DFS�� pair�� �ѱ�鼭 �߰�
3. X,Y�� ��� �����Ǹ� Ż��
->�̶�, X Y�� �Ҽ����ϸ� �ָ��ϹǷ� *2�ؼ� ���
*/


/*���� :
1. ������ pair�� ����
2. ����� dx, �Ķ��̵带 dy�� ����
3. bfs���鼭 üũ?
*/

/*������ :
1. �������� 10�������̹Ƿ�, DFS�� depth�� ����� �޸� �ʰ� ����
->cnt�� �Ѱ����� �ʰ� �����Ѵٸ�? �׷��� �޸� �ʰ�
2. BFS�� �ϸ�? 
->�߸� ®���� ���� �޸� �ʰ�
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
	if ((2*a+c >= X2) && (2 * b + c >= Y2)) {//���� �޼���
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

	//select_chicken_dfs(0, 0, 0); //���� ����
	select_chicken_bfs(0, 0);

	while (!costQueue.empty()) {
		cout << costQueue.top()<<'\n';
		costQueue.pop();
	}
	//cout << costQueue.top();
}
