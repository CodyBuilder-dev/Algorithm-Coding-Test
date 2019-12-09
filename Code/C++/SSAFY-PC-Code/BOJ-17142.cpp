//���� : ������3
//���� : 2�����迭���� ���̷��� 3�� �����ؼ� ����
//���� : ������ ũ�� 50x50. ���̷��� �ִ� 10��

/*���̵�� :
1.���̷��� 10���߿� 3�� ����
->������ ��, ���̷����� ��ǥ�� ��򰡿� ���� �� �ε����� ���̽��ؾ���
2. 3���κ��� BFS ������(�ּ� �ð��̹Ƿ�)
->2�������� ���ÿ� BFS �����°� �丶��2 ����
(�ð��� ���忡 ���� �����ؾ� �Ѵ� �̤�
3. ���̷����� �����ϴ� ���̷����� ���� ��� ���������� ���̷����� ����
4. ������ ���� ĭ�� �ٸ���� ��� ���� �� Ÿ�� �� �� ���� ��
(�̰� ��� ó���ϴ��İ� ����)
*/

/*������ : 74%���� Ʋ�� <- �� ����
���̵�� ��ȯ �ʿ� 
1. ������ ����ü�� �������� ����?
2. ������ VIRUS�� ũ�Ⱑ 990�ۿ� �ȵǴµ�, ��찡 ��û Ŀ���� ��쿡 �ʰ��Ǵ°� �������� ����������
*/

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <list>

#define VIRUS 9900

using namespace std;

int N, M;

int board[50][50];
int time[50][50];
bool visited[50][50];
int minimum = 987654;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };

int virusNum; //���� �� ���̷����� ����
deque<pair<int, int>> virusCoord; //���� �� ���̷����� ��ǥ
deque<int> virusChoice; // ���̷��� ���� vector
queue<pair<int, int>> route; //��� ť
vector<int> timeSet;

//���� �Է� �ޱ�
void input_board()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virusCoord.push_back(make_pair(i, j));
				virusNum++;
			}
		}
}

//time�迭 �ִ밪 ã��
void check_maxtime()
{
	int max = -987654;
	bool isBlank = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] != 1 && visited[i][j] == false) isBlank = true;
			if (time[i][j] > VIRUS && board[i][j] == 2)
				continue;
			if (max < time[i][j]) max = time[i][j];

		}
	}
	if (!isBlank) timeSet.push_back(max);
}

//���̷��� ����
void grow_virus(int y, int x)
{
	do {
		y = route.front().first;
		x = route.front().second;
		route.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (visited[ny][nx] == false) {
					if (time[y][x] >= VIRUS) //����ĭ�� ��Ȱ�� ���̷����� ���
					{
						if (board[ny][nx] == 0)//����ĭ�� �׳� ������ ���
						{
							visited[ny][nx] = true;
							time[y][x] -= VIRUS;
							time[ny][nx] = time[y][x] + 1;

							route.push(make_pair(ny, nx));
						}
						else if (board[ny][nx] == 2) //�� virus�� ���
						{
							visited[ny][nx] = true;
							time[ny][nx] = time[y][x] + 1;
							route.push(make_pair(ny, nx));
						}
					}
					else { //����ĭ�� �׳� ����� ���
						if (board[ny][nx] == 0)//�׳� ������ ���
						{
							visited[ny][nx] = true;
							time[ny][nx] = time[y][x] + 1;

							route.push(make_pair(ny, nx));

						}
						else if (board[ny][nx] == 2) //virus�� ���
						{
							visited[ny][nx] = true;
							time[ny][nx] = VIRUS + time[y][x] +1;
							route.push(make_pair(ny, nx));
						}

					}
					
					
	/*				for (int k = 0; k < N; ++k) {
						for (int l = 0; l < N; ++l)
							cout << time[k][l];
						cout << '\n';
						
					}
					cout << "----------------\n";*/
					
				}
			}
		}

	} while (!route.empty());
}

//���̷��� ����
void choice_virus()
{
	for (int i = 0; i < virusNum - M; ++i)
		virusChoice.push_back(0);
	for (int i = virusNum - M; i < virusNum ; ++i)
		virusChoice.push_back(1);
	
	do {
		
		while (!route.empty())
		{
			route.pop();
		}

		//for (int i = 0; i < virusNum; ++i)
		//	cout << virusChoice[i] ;
		//cout << '\n' << virusNum << virusChoice.size() << '\n';

		//for (int k = 0; k < N; ++k) {
		//	for (int l = 0; l < N; ++l)
		//		cout << board[k][l];
		//	cout << '\n';

		//}
		/*
		for (int i = 0; i < virusNum; ++i)
			cout << virusCoord[i].first << ' ' << virusCoord[i].second << '\n';
		*/

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				time[i][j] = 0;
				visited[i][j] = false;
			}
		}


		for (int i = 0; i < virusChoice.size(); ++i) {
			if (virusChoice[i] == 1) { 
				route.push(virusCoord[i]); 
				visited[virusCoord[i].first][virusCoord[i].second] = true;
			}
		}

		int y = route.front().first;
		int x = route.front().second;

		grow_virus(y, x);

		check_maxtime();

	} while (next_permutation(virusChoice.begin(), virusChoice.end()));
	
	if (timeSet.size() > 0) {//�� ���� ������ ���
		for (int i = 0; i < timeSet.size(); ++i)
			if (timeSet[i] < minimum) minimum = timeSet[i];
	}
	
	else minimum = -1;
}



int main()
{
	input_board();

	choice_virus();
	cout << minimum;
}