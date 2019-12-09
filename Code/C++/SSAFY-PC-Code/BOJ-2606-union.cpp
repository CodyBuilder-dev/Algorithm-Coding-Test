//제목 : 바이러스
//목적 : 1번 컴퓨터로부터 번져나가는 컴퓨터 대수 세기
//조건 : 

/*아이디어2 : 유니언 파인드 통한 구현
1. 각 원소들간의 구현 관계를 그래프/parent 배열로 받음
2. for문으로 전체 돌면서 부모가 1번인 애들 찾아서 개수 파악
*/

//느낀점 : 유니언 파인드는 반드시 parent 초기화 해줘야됨!!!!!

#include <iostream>

using namespace std;

int N, M;
int parent[101];


//파인드
int Find(int child)
{
	if (parent[child] == child) //자기자신이 부모일 경우
		return child;
	else {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
	}
}
//유니온
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

//입력 받기-그냥 바로 패런트 형태
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
		//계층구조를 모르므로 이딴식으로 비교 불가능
		//if (parent[i] == 1) cnt++; 
		if (isUnion(1, i)) cnt++;
	}
	cout << cnt;
}
