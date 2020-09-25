//���� : ������ ǥ��
//���� : �������� ������ ���� ��, ������, ���� ���Կ��� Ȯ�� ���� �Լ� �ۼ�
//���� : ������ ������ �ִ� 100����, ������ ������ �ִ� 10����
//�ð����⵵ : ������ 10���� �ؾߵǹǷ�, �� ����� ȸ�� N�̸� O(N*10^6)

/*���̵�� : set ���� ���� union /find�� Ǯ��
1. for�� ���鼭 ��ɾ� ó��
2. ���� 0�̸� ������ ����
3. ���� 1�̸� ���ε� ����
���ʳ��� ������ ã��, �� �� ���������� �� ���տ� ������ Ȯ��
*/

//������ : ������� 10�����̸� �Է� 'ġƮŰ' ��ߵ�

#include <iostream>

using namespace std;

int N, M;
int parent[1000001];

int Find(int child) //child�� ���� ������ root ��ȯ
{
	if (parent[child] == child) //�ڱ��ڽ��� �θ��� ���
		return child;
	else {
		int p = Find(parent[child]);//�ڱ��ڽ��� �θ� ���ؼ� find�� ��������� ����
		parent[child] = p;
		return p;
	}
}

bool check_Union(int left, int right)
{
	int left_parent, right_parent;
	left_parent = Find(left);
	right_parent = Find(right);
	if (left_parent != right_parent) return false;
	else return true;
}

void Union(int left, int right)
{
	int left_parent, right_parent;
	left_parent = Find(left);
	right_parent = Find(right);

	if (left_parent != right_parent)
		parent[right_parent] = left_parent;
}
int main()
{
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N; ++i)
		parent[i] = i; //�ڱ��ڽ��� �θ�� ����

	for (int i = 0; i < M; ++i) {
		int op,left,right;
		cin >> op >> left >> right;
		if (!op) Union(left, right);
		else if (check_Union(left, right)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}