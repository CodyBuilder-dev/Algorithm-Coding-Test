//제목 : 덩치
//목적 : 몸무게와 키가 주어질 때, 각 사람들의 덩치 랭킹 계산
//조건 : 사람은 최대 50명, 키, 몸무게는 최대 200

/*아이디어 및 구현: 힌트는 각 사람보다 덩치가 큰 사람이 n명이면 그 사람은 n+1등이라는 것
1. n명중에 2명씩 비교해야 하므로 O(0.5*N^2)
2. 사람마다 값이 2개씩 존재하므로, pair를 이용해 구현
3. pair의 vector를 이용해 구현해보자
*/

/*느낀점 : 힌트를 봤으니 쉽게 풀었지만, 힌트가 없었으면 못 풀었을 수도 있음.
힌트 없이도 n이면 n+1등이 되는 원리를 정확하게 나중에 도출해보기
*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<pair<int, int>> people;
	vector<int> ranking;

	cin >> N;
	int weight, height;
	for (int i = 0; i < N; ++i)
	{
		cin >> weight >> height;
		people.push_back(make_pair(weight, height));
	}
	int upper;
	for (int i = 0; i < N; ++i) {
		upper = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;

			if (people[i].first < people[j].first && people[i].second < people[j].second)
				upper++;
		}
		ranking.push_back(upper);
	}

	for (int i = 0; i < N; ++i)
		cout << ranking[i] + 1 << ' ';
}