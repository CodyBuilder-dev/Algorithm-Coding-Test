//제목 : 여행 가자
//목적 : 여행경로가 문자열로 주어지고, 연결되었는지 판단
//조건 : 도시의 개수는 200이하, 

/*아이디어 : 단순 포함여부만 따지는거면 유니언 파인드로 가능
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