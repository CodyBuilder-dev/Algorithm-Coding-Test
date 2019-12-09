//���� : ���� ���ϱ�
//���� : ���簢������ �и��� ������ ������ �� ������ ���̸� ���ϱ�

/*���̵�� : �������� �迭 DFS/BFS����
1.�켱 ���簢�� ���� ���ϰ�
2. DFS�� Ž���ϴ� �Լ� �����
3. ������ ����, ���̴� ���� ���ϱ�� ����ϰ� ���Ѵ�.
(DFS�� ���������� ���� 1���� up. ���̴� ��ĭ ����ɶ����� up
*/

/*����
1. ��ͷ� ¥�� ��̾����� Stack���� �ѹ� �����غ���
2. ��ǥ�� ���� �Ʒ����� (0,0)�ӿ� ����
(x��ǥ�� ������ ���� ĥ�����°��� x, 
y��ǥ�� ������ ���� ĥ�����°��� N-1-y���� N-y����
*/

//������ : DFS �������� ������ �� ������ �� �������
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int M, N, K;

int** board;
bool** visited;

int area = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
void DFS1(int y, int x) //�÷��� ���� pop�ٷ� ������ ���
{
	//�������� © �� ���� ���
	//1. visit �湮�ϱ�
	visited[y][x] = true;
	//2. ��忡�� ���� �ϱ�
	area++;
	//3. ù�κ� ���ÿ� �ֱ�(while �ݺ�����)
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));
	//---������� while��----
	while (!route.empty())
	{
		//4. ������ top�κ��� ���� ��ġ�� ����
		y = route.top().first;
		x = route.top().second;
		route.pop();
		//5.����� ���� ���ƺ��鼭 �� �湮�Ѱ� ã�Ƽ� ���óֱ�
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (visited[ny][nx] == false && board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					route.push(make_pair(y, x));
					route.push(make_pair(ny, nx));
					area++;
					break;
				}

			}

		}
		
	}
}
void DFS2(int y, int x) //�÷��� ���� ���
{
	//�������� © �� ���� ���
	//1. visit �湮�ϱ�
	visited[y][x] = true;
	//2. ��忡�� ���� �ϱ�
	area++;
	//3. ù�κ� ���ÿ� �ֱ�(while �ݺ�����)
	stack<pair<int, int>> route;
	route.push(make_pair(y, x));
	//---������� while��----
	//4. ������ top�κ��� ���� ��ġ�� ����
	while (!route.empty())
	{
		y = route.top().first;
		x = route.top().second;
	
		bool flag = false;
		//����� ���� ���ƺ��鼭 �� �湮�Ѱ� ã�Ƽ� ���óֱ�
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny >= 0 && ny<M && nx >=0 && nx<N){
				if (visited[ny][nx] == false && board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					route.push(make_pair(ny, nx));
					area++;
					flag = true;
					break;
				}

			}
			
		}
		if (flag == false) route.pop();
	}

}
int main()
{
	cin >> M >> N >> K;
	
	board = new int* [M];
	visited = new bool* [M];
	for (int i = 0; i < M; ++i)
	{
		board[i] = new int[N]();
		visited[i] = new bool[N]();
	}
	/*
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j)
			cout << visited[i][j];
		cout << '\n';
	}
	*/
	

	int leftX, leftY, rightX, rightY;
	for (int i = 0; i < K; ++i)
	{
		cin >> leftX >> leftY >> rightX >> rightY;
		for (int j = M - rightY; j < M - leftY; ++j)
			for (int k = leftX; k < rightX; ++k)
				board[j][k] = 1;
	}
	/*
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			cout << board[i][j];
		cout << '\n';
	}
	*/

	int square = 0;
	vector<int> areaArray;

	//������� DFS ����
	for(int i = 0 ; i<M;++i)
		for(int j =0; j<N;++j)
			if (visited[i][j] == false && board[i][j] == 0) {
				DFS1(i, j);
				areaArray.push_back(area);
				area = 0;
				square++;
			}

	cout << square << '\n';
	sort(areaArray.begin(), areaArray.end());
	for (int i = 0; i < square; ++i)
		cout << areaArray[i] <<' ';
}