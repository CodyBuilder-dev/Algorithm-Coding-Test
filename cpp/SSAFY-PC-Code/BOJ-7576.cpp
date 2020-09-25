//���� : �丶��
//���� : �丶�䰡 �� ������ ���¸� �޾�, ��� ���� ���ϴ� ��Ȳ�̸� -1��, ��� ������ �ʹ� �ּ� ���ڸ� ���
//���� : ���ڴ� �ִ� 10^3^2 = 10^6

/*���̵�� : 4�������� �����ǰ�, �ּ����ڸ� ���ؾ� �ϹǷ� BFS�� �´� ��
1. �켱 0�� ã�Ƽ�, BFS�� DFS�� ������ 1�� ������ ������ ����� -1
2. ���� -1�� �ƴ϶�� �׶����� 1 ã�Ƽ� BFS
or
1. �ϴ� 1ã�Ƽ� BFS
2. �ѹ��� �� ���� �������� �� ã�Ƽ� 0�ֳ����� �˻�
*/

/*���� :
1. �������� �� ��ĵ�ؼ�, 1�� ���� ��ǥ�� ã�Ƽ� ť�� ��� �ִ´�
2. ť���� �ϳ��� �����鼭 BFS
3. �׷� time�� ��� ã��? �ϳ��� �� ���� �Ŀ� time 1����
4. BFS�� �ݺ�
5. BFS������ ������ �� ������ 0 ã��
*/

/*������ :
1. ����ü�� ¥�� �ð��ʰ� �ɸ��µ�, ��� �������� �𸣰���.
2. ����ü��� �Ÿ��� ����. �׷��� �ȵǴµ�. ������ �����ε�
3. ���͸� ť�� ���ƴ��� �ٷ� ���. ���ʹ� ťó�� �ᵵ �������� ��û ������
4. �������� ��� -1, ��� 0���� �������ߵǴ��� �� �����༭ ��� ��û��
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int **board;
int **time;
bool **visited;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

queue<pair<int, int>> tomato;

void BFS(int y, int x)
{
	//time�� ��� ������ ������ų ���ΰ�
	//ť���� �ϳ� �̱�
	//���� 4���� �� ã����, ���� �丶�� �̱�
	//tomato ��ǥ�� ���� ť�� �ѹ��� �� ���� time 1 ����...�Ϸ��� ������ �ѹ������ ������ ����
	//�ᱹ ���� ��ü�� �ð����� �����ϴ� �� �ۿ� ����
	visited[y][x] = true;
	while (!tomato.empty())
	{
		y = tomato.front().first;
		x = tomato.front().second;
		tomato.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (visited[ny][nx] == false && board[ny][nx] == 0)
				{
					visited[ny][nx] = true;
					board[ny][nx] = 1;
					time[ny][nx] = time[y][x] + 1;
					tomato.push(make_pair(ny, nx));
				}
			}
		}

	}
}

int main()
{
	cin >> M >> N;

	board = new int*[N];
	time = new int*[N];
	visited = new bool*[N];

	for (int i = 0; i < N; ++i)
	{
		board[i] = new int[M];
		time[i] = new int[M]{0};
		visited[i] = new bool[M]{false};
	}

	for (int i = 0; i < N; ++i) //��ĵ�����鼭 1�� ���� ��� ���Ϳ� �ֱ�
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) tomato.push(make_pair(i, j));
		}
	//���⼭���� �������� �ڵ� ����
	int result;
	int minusCnt=0;
	if (tomato.empty()) {
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < M; ++j) //�ѹ��� ���鼭 -1���� ��
				if (board[i][j] == -1) minusCnt++;
		if (minusCnt == M * N) result = 0;
		else result = -1;
	}
	else {
		BFS(tomato.front().first, tomato.front().second);

		result = 0;
		for (int i = 0; i < N; ++i) { //�ѹ��� ���鼭 0 ������ -1
			for (int j = 0; j < M; ++j) //�ѹ��� ���鼭 �ִ밪 ã�Ƽ� cout
			{
				if (board[i][j] == 0) {
					result = -1; break;
				}
				result = max(result, time[i][j]);
			}
			if (result == -1) break;
		}
	}
				
	cout <<result;
}