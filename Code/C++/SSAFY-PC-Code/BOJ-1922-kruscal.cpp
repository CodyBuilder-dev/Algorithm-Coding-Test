//���� : ��Ʈ��ũ ����
//���� : ��� ��ǻ�͸� �����ϴ� ��� �� ���� �ּҰ� �Ǵ� ���� �����϶�
//���� : ��ǻ�� �ִ� 1000��, ���� �� �ִ� 10����, ����� �ִ� 1��

/*���̵�� :
��� ��带 �� �����ϴ� �� = �ּ� ���д� Ʈ��
�ּ� ���д� Ʈ�� = DFS(���� ��)/ũ�罺Į/����(���� ��)
���⼭�� ũ�罺Į ���
*/

/*���� : 
1.����
1.1����ü�� ����
1.2����ü�� priority queue ����
->���� ����� ���?
->������ �ڵ� ������ ���? ���� ���� ��������?

1.2 �� ����ϰ� ���� �ϰ� ����

2. ���Ͽ� ���ε�
*/

//������ : ����� ���Ͼ��� üũ�ϴ°� �ƴ϶� ������ ���Ͼ��� üũ�ؾ��� ����

//�켱���� ť �˻� ����, ����ü�� ������ ��~ �˻������� ������
//comp ����ü�� ���� ������ְ�, operator()�� �Լ��� ����� ��� ��
// pq�� comp�� �Ź� ȣ���ϸ鼭
//less���ϸ� max heap
//greater

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

//typedef struct edge edge;
//struct edge {
//	edge *pNext;
//};

//typedef struct edge{
//	int cost;
//	int start;
//	int end;
//
//	bool operator()(const edge &x, const edge &y)
//	{
//		return x.cost > y.cost;
//	}
//}EDGE;

pair<int, pair<int, int>> EDGE;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> edgeSet;
deque<pair<int, pair<int, int>>> MST;

int N, M;
int graph[1000][1000]; //0������ �����ؾ��Կ� ����
int parent[1000];

void input()
{ //������� �����
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int start,end,cost;
		cin >> start >> end >> cost;
		if (graph[start - 1][end - 1] == 0) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
			
			EDGE.first = cost;
			EDGE.second.first = start - 1;
			EDGE.second.second = end - 1;
			edgeSet.push(EDGE);
			//cout << edgeSet.top().first << '\n';
		}
		else if (graph[start - 1][end - 1] > cost) {
			graph[start - 1][end - 1] = cost;
			graph[end - 1][start - 1] = cost;
			
			EDGE.first = cost;
			EDGE.second.first = start - 1;
			EDGE.second.second = end - 1;
			edgeSet.push(EDGE);
		}
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
	//���⼭ ���Ͽ��� �ϸ� �ȵ���!!!!
	/*for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			if (graph[i][j] != 0) Union(i, j);*/
}


int main()
{
	input();
	//�׷��� �˻�
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << graph[i][j];
		cout << '\n';
	}*/
	make_parent();

	while (!edgeSet.empty())
	{
		int s, e;
		s = edgeSet.top().second.first;
		e = edgeSet.top().second.second;
		//cout << s << ' ' << e << '\n'; //������� �� ���� Ȯ��
		bool doUnion = isUnion(s, e);

		if (doUnion == false) { //���Ͼ� ���� ������
			Union(s, e);
			MST.push_back(edgeSet.top()); //push back�� �ƿ� �ȵǴ� ��
		}
		edgeSet.pop();
	}

	//cout << MST.size();
	int sum = 0;
	for (int i = 0; i < MST.size(); ++i) {
		sum += MST[i].first;
	}
	cout << sum;
}

