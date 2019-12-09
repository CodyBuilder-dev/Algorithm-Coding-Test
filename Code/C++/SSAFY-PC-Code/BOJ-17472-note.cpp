//���� : �ٸ� �����2
//���� : ������ �ִ� �ٸ��� �����, ��� ���� �� ���� �ִܰŸ��� ���Ͽ���
//���� : ������ ũ��� �ִ� 10x10, ���� ������ �ִ� 6��, �ٸ����̴� �ּ� 2
//Ư���� : 2019.09 �Ｚ ��� �����׽�Ʈ A ����

/*���̵�� :
1. ���� ���� �Է� �ޱ�
-> 2�����迭�� �޾Ƶα�

2. ���� �������� ��� ã�� ��ȣ�� �ű��.
-> BFS�� �̿�, 2�����迭 �ϳ� �߰��ؼ� �� ��ȣ �ٿ��α�
-> ���� �����ڸ��� üũ�ؾ� �� �ʿ�� ����

3. ������ �Ÿ��� ���ҷ� ���� ������� �����
-> DFS �̿��ؼ� �ٸ��� ����� �� �ٸ��� �Ÿ��� ã��
-> ���� ��� edge��κ��� ��� �������� �� �ٸ� ����� ������ ����

4. ��������� DFS�� Ž���Ͽ� 4�� �� ���� �ִܰŸ�(�ſ� ����õ. �õ�X)
-> �տ��� BFS�� ��Ż ������ �Դµ� ���⼭ �� DFS�� �� �ʿ� ����
-> �ڵ尡 ��¥ �ſ� �ɰ��ϰ� ��������

4. ���Ͼ����ε�� ũ�罺Į�� �̿��� ������ MST����
-> ���Ͼ� ���ε� �Լ��� �ۼ��صα�
-> ũ�罺Į�� ������, ��尡 �ƴ� '����'�� ������ ���� �ϹǷ�
��������� Ž���ϸ� priority queue�� �������� ����
-> ũ�罺Į�� ����
-> ������ "�ݵ��" ��� ������ ����Ǿ����� Ȯ���Ѵ�.
*/

/*������ :
1.BFS -> DFS -> ũ�罺Į 3���޺� ����
(���� 2���� �Ѿ 3�߱��� ����ؾ��� �ʿ� ������ ����;;;;)

2.ũ�罺Į�� ���� ���̳� ��, �ݵ�� ��� ���� ������ ������������ for�� ���Ͼ����� Ȯ��
->��� ���� ������ �������� ���� ���, ũ�罺Į�� ����...
->1. ������� ������� ���� ª������ �������� ����
->2. ���� ª�� �������� ����
->3. ���������δ� ��� ������ �� ����Ǿ� �ִ� ���°� �� �� ����
*/
#include <iostream>
#include <utility>
#include <queue>

#define MAX_ISLAND 6 + 1
#define INF 987654

using namespace std;

//����
int N, M;
int map[10][10]; // ����
int num; //�� ����
int islandNum[10][10]; //������ ���� �Űܼ� ����� �迭
bool visited[10][10]; // �湮üũ��
int islandDist[MAX_ISLAND][MAX_ISLAND]; // ������ �Ÿ� �������
int parent[MAX_ISLAND];
int dy[] = { 1,0,-1,0 }; //�� �� �� ��
int dx[] = { 0,-1,0,1 };

int sum = 0;
priority_queue <pair<int, pair<int, int>>,vector< pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;

//�� �Է� �޴� �Լ�
void input_island()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];

	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << map[i][j] << ' ';
	//	cout << '\n';
	//}
}

//�� ���� �޴� BFS
void check_island_bfs(int y, int x ,int islNum)
{
	queue<pair<int, int>> Q;
	visited[y][x] = true;
	islandNum[y][x] = islNum;
	Q.push(make_pair(y, x));

	do {
		y = Q.front().first;
		x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i]; int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M)
				if(visited[ny][nx] == false && map[ny][nx] == 1)
				{
					visited[ny][nx] = true;
					islandNum[ny][nx] = islNum;
					Q.push(make_pair(ny, nx));

				}
		}
	} while (!Q.empty());
}
//���� �������� �ٸ� ����� DFS
//�ϴ� �ٸ������� ���۵Ǹ�, ���� �������� ��� �İ�� ������.
//���ٰ� �ٸ��� ������ ���߰� ��...�� ������ �Ÿ� ���徲
void make_bridge_dfs(int y, int x, int start, int dir,  int dist)
{	
	int ny = y + dy[dir]; int nx = x + dx[dir]; //�ش� ���� �˻�
	if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
		//if (map[ny][nx] == 0) //�ٴ����� �ٸ� �����(X)
		if(islandNum[ny][nx] == 0) //���ۼ��̶� �ٸ��� �ٸ� �����
			make_bridge_dfs(ny, nx, start, dir, dist + 1);

		if (islandNum[ny][nx] == start) //��ĭ �� ���µ� �Ȱ��� ���ۼ��̸�
			return;

		if (islandNum[ny][nx] != start) { //��ĭ �� ����� �ٸ� ���̸�
			int end = islandNum[ny][nx];
			if (dist < 2) return; //�ٸ����� ª���� Ż��
			if (islandDist[start][end] > dist) { //������� �Ÿ����� ª���� ����
				islandDist[start][end] = dist;
				islandDist[end][start] = dist;
			}
			return;
		}
	}
}


//���Ͼ�-���ε�, ũ�罺Į

int Find(int child)
{
	if (parent[child] == child) return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return  p;
	}
}
void Union(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);

	if (left_p != right_p) parent[right_p] = left_p;
}

bool isUnion(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);
	
	if (left_p != right_p) return false;
	else return true;
}

//������Ŀ� ũ�罺Į ����
void kruscal()
{
	for (int i = 1; i <= num; ++i)
		parent[i] = i;

	while (!edgeSet.empty())
	{
		int cost, start, end;
		cost = edgeSet.top().first;
		start = edgeSet.top().second.first;
		end = edgeSet.top().second.second;
		//cout << cost << ' ' << start << ' ' << end << '\n';
		edgeSet.pop();
		
		if (!isUnion(start, end)) {
			Union(start, end);
			sum += cost;
		}
	}
	

}


int main()
{
	//map �����
	input_island();

	//���鼭 �� ��ȣ 1�� �߰��ؼ� �ޱ��
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visited[i][j] == false && map[i][j] == 1) {
				num++;
				check_island_bfs(i, j, num);
			}
		}
	}

	//��ȣ �� �Ű���� Ȯ��
	//cout << "��ȣ�ű� �迭" << '\n';
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < M; ++j)
	//		cout << islandNum[i][j] << ' ';
	//	cout << '\n';
	//}

	//�ٸ� ���� �ʱ�ȭ (����ȣ�� 1������ �ִ� 6������  �Ű����� ����
	for (int i = 1; i < MAX_ISLAND; ++i)
		for (int j = 1; j < MAX_ISLAND; ++j) {
			if (i == j) continue;
			islandDist[i][j] = INF;
		}

	//����� ���鼭 �ٸ� �����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) { 
			if (islandNum[i][j] != 0) {
				for (int dir = 0; dir < 4; ++dir) { //�� ���� 4���⿡�� �߻�
					make_bridge_dfs(i, j, islandNum[i][j], dir, 0);
				}
			}
		}
	}

	//���� �Ÿ� ���
	//cout << "���� �Ÿ� \n";
	//for (int i = 1; i <= num; ++i) {
	//	for (int j = 1; j <= num; ++j)
	//		cout << islandDist[i][j] << ' ';
	//	cout << '\n';
	//}

	//���� ��ο� ũ�罺Į ����
	for (int i =1 ; i<=num;++i)
		for (int j = i+1; j <= num; ++j) {
			if (i == j) continue;
			if(islandDist[i][j] != INF && islandDist[i][j] != 0){
				edgeSet.push(make_pair(islandDist[i][j], make_pair(i, j)));
			}
		}

	kruscal();

	
	//��� ������ �� ����Ǿ����� isUnion���� Ȯ��
	bool isConnected = true;
	for (int i = 1; i <= num; ++i)
		for (int j = i + 1; j <= num; ++j)
			if (!isUnion(i, j)) isConnected = false;

	if (isConnected) cout << sum;
	else cout << -1;
			
}