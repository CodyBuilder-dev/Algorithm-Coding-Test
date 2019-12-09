//아이디어 : 
#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

pair<int, int> find_first_min(int start, int n, vector<int> P)
{
	pair<int, int> min = make_pair(start,P[start]);
	for (int i = start; i < n; ++i) {
		if (P[i] < P[start]) {
			min.first = i;
			min.second = P[i];
			break;
		}
	}
	return min;
}

int solution(int n, vector<int> P) {
	int answer = 0;
	pair<int, int> min;

	int i = 0;
	while (i < n)
	{
		min = find_first_min(i, n, P);
		if(min.first == i){
			answer += (n - min.first) * min.second;
			break;
		}
		else
		{
			answer += (min.first - i) * P[i];
			int idx_diff = min.first - i;
			i += idx_diff;
		}
	}

	return answer;
}

int main()
{
	vector<int> P ={5, 7, 8, 2, 4, 6, 1, 8, 9, 10
};
	int n = 10;
	int answer = solution(n, P);
	cout << answer;
}