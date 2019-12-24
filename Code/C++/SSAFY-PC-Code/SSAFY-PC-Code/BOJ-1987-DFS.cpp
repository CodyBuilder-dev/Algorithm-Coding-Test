//���� : ���ĺ�
//���� : ���带 ������, ���²� ��Ҵ� ���ĺ��� ���� ���� ������ �� ������

/*���̵�� :
1. 2�����迭 ������ ����Ž���̹Ƿ� DFS/BFS
2. �ִ� ������ �� �ִ� �Ÿ��� ���ϹǷ� DFS
3. ���²� �����Դ� ��ε��� ����� ��򰡿� ������ �ΰ� üũ�ؾ� ��
->No! �׳� �Ź����� ��θ� �� ���� ����, alphabet ��ܸ� üũ�ϸ� �ƾ���
*/

/*����
1. ����� �迭, DFS�� ���ýἭ
2. ��� ����� ���� ����/������ ������ �ϰ�, Ž���� ������ ��
(���Ի����� ���ø��Ѱ� ���µ�, Ž���� �ȵ�)
(�׳� ���� �Ẹ�� �ð��ʰ� �߸� �迭���°� ���̴�)
(26ĭ¥�� �迭�� �־��� ����)
3. Ž���� �׳� �������� std::find����,�ð��ʰ� �߸� �̺�Ž�����ų� ������
find�� �Լ� ���ǻ� ����� �������� �ʴ� �� �߰�.
���� for�� ������ ã��
4. DFS���� ����� ���� ����� 
��ε� ť�� ���ÿ� �ְų� 
flag ���ų� �� �� (���� �ʹ� ���̹Ƿ� x)
maxima�� ���ؼ� �ְų�
*/

//������ : DFS+stack���� ��� ���� ã�°� ���� ���� �ƴ�

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int R, C;

char **board;
bool **visited;
bool alphabet[26];

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int cnt = 1;
int maxima = -987654321;
bool dup;

//void DFS(int y, int x)
//{
//	visited[y][x] = true;
//	stack<pair<int, int>> route; //���²� ��� ��ǥ���� ����
//	route.push(make_pair(y, x));
//	
//	vector<char> check; //���²� ���ĺ����� �迭
//	check.push_back(board[y][x]);
//	
//	stack<int> far; //���²� ��� ���̵��� ����
//	far.push(cnt);
//	
//	while (!route.empty())
//	{
//		y = route.top().first; 
//		x = route.top().second;
//		route.pop();
//
//		cnt = far.top(); //���������� ����
//		far.pop();
//	
//	
//		for (int i = 0; i < 4; ++i)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			dup = false; //�ߺ� �ֳ� üũ�� �÷���
//			if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
//				if (visited[ny][nx] == false){ //�湮 ���߰�
//					
//					for (int i = 0; i < check.size(); ++i)
//						if (check[i] == board[ny][nx]) {
//							dup = true; 
//							break;
//						}
//				
//					if(dup == false)//���������� ���ĺ��� ��������� ��ο� ������ 
//					{
//					visited[ny][nx] = true;
//					route.push(make_pair(y, x));
//					route.push(make_pair(ny, nx));
//				
//					check.push_back(board[ny][nx]);
//					far.push(cnt);
//					far.push(cnt + 1);
//			
//					break;
//					}
//				}
//			}
//			dup = true;
//		
//		}
//		if (dup == true) //for�� �� ���� ������  ture�� �� ������ �ǹ�
//		{
//			maxima = (maxima < cnt) ? cnt : maxima;
//			check.pop_back();
//		}
//	}
//}

void DFS(int y, int x)
{
	visited[y][x] = true;
	alphabet[board[y][x] - 65] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i]; int nx = x + dx[i];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C)
			if (visited[ny][nx] == false && alphabet[board[ny][nx]-65] == false)
				DFS(ny, nx);
	}
}
int main()
{
	cin >> R >> C;

	board = new char*[R];
	visited = new bool*[R];
	for (int i = 0; i < R; ++i){
		board[i] = new char[C];
		visited[i] = new bool[C]();
	}

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];

	//���⼭���� DFS �ڵ� ����
	DFS(0, 0);
	cout << maxima;
	return 0;
}