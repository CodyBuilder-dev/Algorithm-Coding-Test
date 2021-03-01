//���� : ������
//���� : 2�����迭���� �� 3���� ���� ���̷����� ������ �� �������� �ִ�
//���� : DFS 2�� ��ø

/*���̵�� : 
1. ���� ����� ����� ������ �ϴ� Ʈ�������� ������Ƿ� DFS
2. ���� ��� ������ ���Ŀ� ���̷����� ������ ã�°͵� DFS/BFS
*/

//������ : DFS�ȿ� DFS�� ���� �����, stack�� ���̿��ؼ� ���ϴ� ������ ��� �� �ִ�.
//��� stack�� ���� ��� push pop ������ �� �����ؼ� Ǯ��� �Ѵ�.
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int N,M;

int **lab;
bool **walled;
bool **visited;

stack<pair<int,int>> route;

int maxima=-987654;
int safe = 0;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1 };

void DFS(int y, int x) //���� DFS ���� �Լ�
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M)
		{
			if (visited[ny][nx] == false && walled[ny][nx] == false
				&& lab[ny][nx] != 1)
				DFS(ny, nx);
		}
	}
}

void make_wall(int cnt) //���� �� ����� �Լ�
{
	if (cnt > 2) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (lab[i][j] == 2 && visited[i][j] == false && walled[i][j] == false)
					DFS(i, j);
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (visited[i][j] == false && walled[i][j] ==false
					&& lab[i][j] == 0)
					safe++;
		maxima = (safe > maxima) ? safe : maxima;
		//cout << "����" << safe << '\n';
		safe = 0;
		int dely = route.top().first;
		int delx = route.top().second;
		//cout << "������ ��" <<dely << ' ' << delx << '\n';
		route.pop();
		walled[dely][delx] = false;
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				visited[i][j] = false;
		return;
	}
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			
			if (!walled[i][j] && lab[i][j] == 0) {
				walled[i][j] = true;
				route.push(make_pair(i, j));
				//cout << "���� " << cnt << "��° ��" << i << ' ' << j << ',';
				make_wall(cnt + 1); //���� ����


			}
		
		}
	}
	if (!route.empty())
	{
		int dely = route.top().first;
		int delx = route.top().second;
		walled[dely][delx] = false;
		route.pop();
	}
}

//���� : �ѹ� walled�Ǹ� �� �ʱ�ȭ��

int main()
{
	cin >> N >> M;
	lab = new int*[N];
	walled = new bool*[N];
	visited = new bool*[N];
	for (int i = 0; i < N; ++i){
		lab[i] = new int[M];
		walled[i] = new bool[M]();
		visited[i] = new bool[M](); 
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> lab[i][j];
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << lab[i][j] << ' ';
		cout << '\n';
	}
	*/
	make_wall(0);
	//cout << "�ش� " << maxima;
	cout << maxima;
}
