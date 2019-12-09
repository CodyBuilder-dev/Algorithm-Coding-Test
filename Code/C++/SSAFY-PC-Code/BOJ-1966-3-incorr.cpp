//제목 : 프린터 큐
//목적 : 우선순위에 따라 출력순서가 결정되는 큐를 만들 수 있는가

/*아이디어 3 :  map써서 sort
*/
//느낀점 : 맵 값으로 정렬하는 방법
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<template <typename> class P = std::less >
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};

int main()
{
	int T;
	int total_paper, paper_idx;
	map<int, int> paper_map;
	
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%d %d", &total_paper, &paper_idx);

		for (int j = 0; j < total_paper; ++j) {
			int importance;
			scanf("%d", &importance);
			paper_map[j] = importance;
		}
		//맵을 페어 벡터로 베끼기
		vector<pair<int, int>> vec(paper_map.begin(), paper_map.end());

		sort(vec.begin(), vec.end(), compare_pair_second<less>());
		//페어의 2번째 원소 기준으로 정렬
		
		cout <<
	}
	
	
		

}