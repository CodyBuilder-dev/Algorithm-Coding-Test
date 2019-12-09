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

//������ : �̷��� ¥�� �ð��ʰ� �ɸ��µ�, ��� �������� �𸣰���.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef struct {
	int value;
	int time = 0;
} BLOCK;

int N, M;
BLOCK **board;
bool **visited;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

vector<pair<int,int>> tomato;

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
		tomato.erase(tomato.begin());
	
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
			{
				if (visited[ny][nx] == false && board[ny][nx].value == 0)
				{
					visited[ny][nx] = true;
					board[ny][nx].value = 1;
					board[ny][nx].time = board[y][x].time + 1;
					tomato.push_back(make_pair(ny, nx));
				}
			}
		}

	}
}

int main()
{
	cin >> M >> N;

	board = new BLOCK*[N];
	visited = new bool*[N];

	for (int i = 0; i < N; ++i)
	{
		board[i] = new BLOCK[M];
		visited[i] = new bool[M]();
	}
	
	for(int i = 0; i<N;++i) //��ĵ�����鼭 1�� ���� ��� ���Ϳ� �ֱ�
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j].value;
			if (board[i][j].value == 1) tomato.push_back(make_pair(i, j));
		}
	//���⼭���� �������� �ڵ� ����
	int result;
	if (tomato.empty()) result = -1;
	else {
		BFS(tomato.front().first, tomato.front().second);

		
		for (int i = 0; i < N; ++i) { //�ѹ��� ���鼭 0 ������ -1
			for (int j = 0; j < M; ++j) //�ѹ��� ���鼭 �ִ밪 ã�Ƽ� cout
			{
				if (board[i][j].value == 0) {
					result = -1; break;
				}
				result = max(result, board[i][j].time);
			}
			if (result == -1) break;
		}
	}
	cout << result;
}