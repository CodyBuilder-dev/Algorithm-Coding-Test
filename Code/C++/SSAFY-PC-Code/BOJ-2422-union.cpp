//���� : �������� ��Ż���ƿ� ���� ���̽�ũ���� ��Դµ�
//���� : ���̽�ũ���� ���ԵǾ�� �ȵǴ� ������ ã��
//���� : ���̽�ũ���� �ִ� 200����. ������ 3�̹Ƿ� 200C3

/*���̵�� : ���Ͽ� ���ε�� Ǯ��?��
1. �Ծ �� �Ǵ� ���̽�ũ���� ��Ʈ���� union���� ���´�
2. next_permutation�� ���鼭 ������ ã�´�
3. ������ ���ҵ��� isUnion�ؼ� ������ fail (X)
-> �׳� �θ� ������ �ٸ����� ���� ��(X)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int parent[201];
vector<int> comb;
vector<int> selected;

int Find(int child)
{
	if (parent[child] == child)
		return child;

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

int main()
{
	//�Է� �ް� �����ϴ� �ܰ�
	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	
	for (int i = 0; i < N - 3; ++i)
		comb.push_back(0);
	for (int i = 0; i < 3; ++i)
		comb.push_back(1);

	for (int i = 0; i < M; ++i) {
		int s, e;
		cin >> s >> e;
		Union(s, e);
	}

	/*for (int i = 0; i < N; ++i)
		cout << comb[i];*/
	//���⼭���� ������ �ڵ� ����

	/*for (int i = 1; i <= N; ++i)
		cout << parent[i];
	cout << '\n';
*/
	int cnt = 0;
	do {
		selected.clear();

		for (int i = 0; i < comb.size(); ++i)
			if(comb[i] == 1)
				selected.push_back(i+1);
	/*	for (int i = 0; i < selected.size(); ++i)
			cout << selected[i];
		cout << '\n';*/
		if (parent[selected[0]] == parent[selected[1]]
			|| parent[selected[1]] == parent[selected[2]]
			|| parent[selected[0]] == parent[selected[2]])
			continue;
		else cnt++;
	} while (next_permutation(comb.begin(), comb.end()));

	cout << cnt;
}