//제목 : 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
//목적 : 아이스크림에 포함되어서는 안되는 조합을 찾기
//조건 : 아이스크림은 최대 200가지. 선택은 3이므로 200C3

/*아이디어 : 유니온 파인드로 풀면?ㄴ
1. 먹어선 안 되는 아이스크림의 세트들을 union으로 묶는다
2. next_permutation을 돌면서 조합을 찾는다
3. 조합의 원소들을 isUnion해서 같으면 fail (X)
-> 그냥 부모가 같은지 다른지만 보면 됨(X)
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
	//입력 받고 세팅하는 단계
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
	//여기서부터 본격적 코딩 시작

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