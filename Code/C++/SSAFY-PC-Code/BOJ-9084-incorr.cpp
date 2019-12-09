//제목 : 동전
//목적 : 동전의 액면가가 주어지고, 해당 동전들로 특정 수를 만들 때 경우의 수
//조건 : 경우의 수는 int범위 내

/*아이디어 : 동전의 개수만큼 방향이 있는 트리라고 생각할 수 있음
1. 제일 작은 액면가부터 시작해서, DFS로 파고 올라가기
2. 파고 올라가면서 각 동전의 개수를 배열에 저장
3. 각기 다른 배열의 개수를 구하면 그게 바로 경우의 수
*/

//문제점 : 그냥 DFS쓰면 시간초과 뜸 ㅋㅋㅋ

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int T;
int N, M;
int coinArray[20]; //0번지 
int selectedCoin; //0번지의 코인은 10^0자리에, 1번지의 코인은 10^1자리에
set<int> arraySet;

void dfs(int sum, int selectedCoin)
{
	if (sum == M) { //딱 목표치면 저장후 리턴
		arraySet.insert(selectedCoin);
		return;
	}
	if (sum > M) return; //범위 벗어나면 그냥 return
	for (int i = 0; i < N; ++i)
	{
		dfs(sum + coinArray[i], selectedCoin + pow(10, i));
	}
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> coinArray[j];
		cin >> M;

		dfs(0, 0);
		cout << arraySet.size() << '\n';
	}
}