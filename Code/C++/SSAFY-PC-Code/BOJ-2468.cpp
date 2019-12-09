//���� : ���� ����
//���� : ���� �纸�� ���̰� ���� ���� ������ ����� �ʴ� ������ �����Ͽ� ����� �ʴ� ������ ������ ���϶�
//���� : ���� �ִ� 100x100 

/*���̵�� : �������� �迭 DFS/BFSŽ��
1. ���� DFS�� ���� ����ؼ� �������
2. ������ ���� ���� ���Ѵ�. 
3. �ش� ���� ���� �켱 ��ü�� Ž���ϸ鼭 ħ���Ǵ� ������ ã�Ƽ� üũ
4. �׸��� �ٽ� Ž���ϸ鼭 ħ������ ���� ������ ã��.
*/

/*������ : 
1.�迭 �پ����� �ʱ�ȭ�ϴ� ��� �˾ƾ� ��
2.ħ������ ã�� �� �׳� for�� ������ �ƾ��� ������
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
	//1. flooded üũ
	flooded[y][x] = true;

	//2. ���� �ϱ�

	//3. ���ÿ� �ֱ�
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));

	//4. while�� ����
	while (!route.empty())
	{
		//5. top�� ���� �� �ٷ� pop�ϰų� �ƴϸ� ���߿� flag�� pop�ϰų�
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
	//1. flooded üũ
	visited[y][x] = true;

	//2. ���� �ϱ�

	//3. ���ÿ� �ֱ�
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));

	//4. while�� ����
	while (!route.empty())
	{
		//5. top�� ���� �� �ٷ� pop�ϰų� �ƴϸ� ���߿� flag�� pop�ϰų�
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

	//land Ȯ�� - okay(�ּ�ó���� ^e���¿��� c. ������ ^e���¿��� u)
	//for (int i = 0; i < N; ++i)
	//	for (int j = 0; j < N; ++j)
	//		cout << land[i][j];

	int area = 0;
	int maxima = 0;
	//���⼭���� DFS ����
	for (int i = 0; i <= 100; ++i) {//���� ��
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
		//fill_n(&visited[0][0], N*N, false); <-for�� ���� ȥ�� ���� ���۵�

		//memset(flooded, 0, N*N); �ſ� ������? ����
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

