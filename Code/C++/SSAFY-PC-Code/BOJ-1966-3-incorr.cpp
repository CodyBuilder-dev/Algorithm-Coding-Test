//���� : ������ ť
//���� : �켱������ ���� ��¼����� �����Ǵ� ť�� ���� �� �ִ°�

/*���̵�� 3 :  map�Ἥ sort
*/
//������ : �� ������ �����ϴ� ���
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
		//���� ��� ���ͷ� ������
		vector<pair<int, int>> vec(paper_map.begin(), paper_map.end());

		sort(vec.begin(), vec.end(), compare_pair_second<less>());
		//����� 2��° ���� �������� ����
		
		cout <<
	}
	
	
		

}