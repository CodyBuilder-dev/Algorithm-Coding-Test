//제목 : 바이러스
//목적 : 1번 컴퓨터로부터 번져나가는 컴퓨터 대수 세기
//조건 : 

/*아이디어3 : 인접행렬로 받고 유니언 파인드 통한 구현
1. 각 원소들간의 구현 관계를 일단은 그래프로 받음
2. 그래프로부터 유니온 파인드 도출
3. for문으로 전체 돌면서 부모가 1번인 애들 찾아서 개수 파악
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
		parent[i] = i; //자기자신 부모로 초기화
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