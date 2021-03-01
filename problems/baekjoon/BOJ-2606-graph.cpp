//���� : ���̷���
//���� : 1�� ��ǻ�ͷκ��� ���������� ��ǻ�� ��� ����
//���� : 

/*���̵��3 : ������ķ� �ް� ���Ͼ� ���ε� ���� ����
1. �� ���ҵ鰣�� ���� ���踦 �ϴ��� �׷����� ����
2. �׷����κ��� ���Ͽ� ���ε� ����
3. for������ ��ü ���鼭 �θ� 1���� �ֵ� ã�Ƽ� ���� �ľ�
*/


#include <iostream>

using namespace std;

int N, M;
bool graph[101][101];
int parent[101];

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int left, right;
		cin >> left >> right;
		graph[left][right] = true;
		graph[right][left] = true;
	}
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

void Union(int left,int right)
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
	return true;
}

void make_parent()
{
	for (int i = 1; i <= N; ++i)
		parent[i] = i; //�ڱ��ڽ� �θ�� �ʱ�ȭ
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			if (graph[i][j]) Union(i, j);
}

int main()
{
	input();
	make_parent();


	int cnt = 0;
	for (int i = 2; i <= N; ++i) {
		if(isUnion(1,i)) cnt++;
	}
	cout << cnt;
}