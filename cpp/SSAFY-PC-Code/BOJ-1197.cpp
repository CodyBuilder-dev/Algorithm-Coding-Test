//���� : �ּ� ���д� Ʈ��
//���� : �׷����� �־����� ��, �ּ� ���д� Ʈ���� ���ϱ�
/*���� : ������ �ִ� 1����, ������ �ִ� 10����
->�Է¹��� ������ �����Ƿ� ����� ����ȭ �ʿ�
���� ����ġ�� ������ int���� ��
*/


/*���̵�� : �������� ����� ���Ͼ� ���ε�-ũ�罺Į
*/
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int V, E;
//int graph[10001][10001]; //�������⿡ �׷��� ����°� ��ü�� ������
int parent[10001];

int mstCost;

//edge���� ��Ƶδ� pq
priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;

//�Է��Լ�
void input()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		//�ѹ� ���� ���� �� ���ü� ������?
		int s, e, c;
		cin >> s >> e >> c;
		//graph[s][e] = c;
		//graph[e][s] = c;
		//�����鼭 ������� �� �ƴ϶� pq���� �ֱ�
		edgeSet.push(make_pair(c, make_pair(s, e)));
	}
}

//���Ͼ� ���ε�
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
	else return true;
}

//kruscal
void kruscal()
{

	//parent �ʱ�ȭ
	for (int i = 1; i <= V; ++i)
		parent[i] = i;

	while (!edgeSet.empty()) {
		//1.�켱���� ť���� �� �տ��� ����
		int s = edgeSet.top().second.first;
		int e = edgeSet.top().second.second;
		int c = edgeSet.top().first;

		edgeSet.pop();

		if (isUnion(s, e)) continue;
		else {
			Union(s, e);
			mstCost += c;
		}

		//2.�ش� s,e�� isUnion���� �ľ�
		//3. ������ �н�, �ƴϸ� ���Ͼ����� ����
		//4. �ݺ�
	}
}

int main()
{
	input();
	kruscal();
	cout << mstCost;
}