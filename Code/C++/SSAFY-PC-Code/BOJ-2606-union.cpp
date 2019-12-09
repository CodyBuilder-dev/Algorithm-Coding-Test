//���� : ���̷���
//���� : 1�� ��ǻ�ͷκ��� ���������� ��ǻ�� ��� ����
//���� : 

/*���̵��2 : ���Ͼ� ���ε� ���� ����
1. �� ���ҵ鰣�� ���� ���踦 �׷���/parent �迭�� ����
2. for������ ��ü ���鼭 �θ� 1���� �ֵ� ã�Ƽ� ���� �ľ�
*/

//������ : ���Ͼ� ���ε�� �ݵ�� parent �ʱ�ȭ ����ߵ�!!!!!

#include <iostream>

using namespace std;

int N, M;
int parent[101];


//���ε�
int Find(int child)
{
	if (parent[child] == child) //�ڱ��ڽ��� �θ��� ���
		return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
	}
}
//���Ͽ�
void Union(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);

	if (left_p != right_p) {
		parent[right_p] = left_p;
	}
}

bool isUnion(int left, int right)
{
	int left_p = Find(left);
	int right_p = Find(right);

	if (left_p == right_p) return true;
	else return false;
}

//�Է� �ޱ�-�׳� �ٷ� �з�Ʈ ����
void inputParent()
{
	for (int i = 1; i < N; ++i)
		parent[i] = i;
	for (int i = 0; i < M; ++i) {
		int left, right;
		cin >> left >> right;
		if( right == 1) Union(right,left);
		else Union(left, right);
		//for (int j = 1; j <= N; ++j)
		//	cout << parent[j];
		//cout << '\n';
	}
}


int main()
{
	cin >> N >> M;
	inputParent();

	int cnt = 0;
	for (int i = 2; i <= N; ++i)
	{
		//���������� �𸣹Ƿ� �̵������� �� �Ұ���
		//if (parent[i] == 1) cnt++; 
		if (isUnion(1, i)) cnt++;
	}
	cout << cnt;
}
