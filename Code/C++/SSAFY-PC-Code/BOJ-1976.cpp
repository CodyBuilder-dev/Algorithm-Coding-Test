//���� : ���� ����
//���� : �����ΰ� ���ڿ��� �־�����, ����Ǿ����� �Ǵ�
//���� : ������ ������ 200����, 

/*���̵�� : �ܼ� ���Կ��θ� �����°Ÿ� ���Ͼ� ���ε�� ����
*/

#include <iostream>
#include <vector>

using namespace std;

int  N, M;
int parent[200];
int graph[200][200];
vector<int> route;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];
}


int Find(int child)
{
	if (parent[child] == child) return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
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
void make_parent()
{
	for (int i = 0; i < N; ++i)
		parent[i] = i;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (graph[i][j] == 1) Union(i, j);
}

int main()
{
	input();
	make_parent();

	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;
		route.push_back(temp);
	}

	bool canGo = true;

	for (int i = 0; i < M - 1; ++i)
	{
		if (!isUnion(route[i], route[i + 1])) {
			canGo = false;
			break;
		}
	}

	if (canGo) cout << "YES";
	else cout << "NO";

	return 0;
}