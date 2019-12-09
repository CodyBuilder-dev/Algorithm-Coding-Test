//제목 : 프린터 큐
//목적 : 우선순위에 따라 출력순서가 결정되는 큐를 만들 수 있는가

/*아이디어 2 :최대 우선순위를 구한다. 어차피 이놈말고는 절대로 안나옴
1. 내림차순으로 정렬
2. 앞에서부터 뽑으며 cnt 증가
3. 목표값 도달시 cnt 반환
*/

//문제점 :같은 우선순위가 있는 경우 파악 불가
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int total_paper, paper_idx;
	
	int out_cnt = 0;
	int paper_num;
	vector<int> paper_array;
	

	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%d %d", &total_paper, &paper_idx);

		
		for (int j = 0; j < total_paper; ++j){
			int importance;
			scanf("%d", &importance);
			paper_array.push_back(importance);
		}

		paper_num = paper_array[paper_idx];

		sort(paper_array.begin(), paper_array.end(),less<int>());

		while (!paper_array.empty())
		{
			//맨 처음값이 크거나,작거나,같거나 따라 다름
			if (paper_array.front() > paper_num) {
				paper_array.erase(paper_array.begin());
					out_cnt++;
			}

			else if (paper_array.front() == paper_num)
				out_cnt++;

		}
		cout << out_cnt;
	}
}