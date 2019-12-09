//제목 : 집합의 표현
//목적 : 여러개의 집합이 있을 때, 합집합, 집합 포함여부 확인 연산 함수 작성
//조건 : 원소의 종류는 최대 100만개, 연산의 개수는 최대 10만개
//시간복잡도 : 연산을 10만번 해야되므로, 각 연산당 회수 N이면 O(N*10^6)

/*아이디어 : set 쓰지 말고 union /find로 풀기
1. for문 돌면서 명령어 처리
2. 만약 0이면 합집합 수행
3. 만약 1이면 파인드 수행
왼쪽놈의 집합을 찾고, 그 후 오른족놈이 그 집합에 속한지 확인
*/

//느낀점 : 입출력이 10만번이면 입력 '치트키' 써야됨

#include <iostream>

using namespace std;

int N, M;
int parent[1000001];

int Find(int child) //child로 들어온 원소의 root 반환
{
	if (parent[child] == child) //자기자신이 부모일 경우
		return child;
	else {
		int p = Find(parent[child]);//자기자신의 부모에 대해서 find를 재귀적으로 수행
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
		parent[i] = i; //자기자신을 부모로 갖음

	for (int i = 0; i < M; ++i) {
		int op,left,right;
		cin >> op >> left >> right;
		if (!op) Union(left, right);
		else if (check_Union(left, right)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}