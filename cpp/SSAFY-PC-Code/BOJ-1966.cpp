//제목 : 프린터 큐
//목적 : 우선순위에 따라 출력순서가 결정되는 큐를 만들 수 있는가

/*아이디어 : 단순히 말 그대로 구현
1. 큐 만들기
2. 맨 앞의값 보고 중요도 검사
3. queue의 모든 내용을 다 확인해 검사 O(n)
4. 매번 반복 O(n2)
*/

//느낀점 :  vector의 iterator 쓰는 법
//느낀점 : 이전 테케에서 썼던 큐를 그대로 쓰면, 큐의 잔존물이 그대로 남아있다.
// 그러므로 큐를 다 빼주거나,아예 테케 for문 안에서 선언해주거나 해야함
// 큐를 전역이나 메인에 선언한경우 주의해야함
#include <iostream>
#include <queue>
#include <utility>
using namespace std;



int main()
{
	int T;
	int total_paper, paper_idx;
	
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) { //케이스 시작
		int out_cnt = 0;
		scanf("%d %d", &total_paper, &paper_idx);

		vector<pair<int, int>> paper_vector;
		for (int j = 0; j < total_paper; ++j) {
			int importance;
			scanf("%d", &importance);
			paper_vector.push_back(make_pair(j, importance));
		}
		/* 벡터 체크
		while (!paper_vector.empty())
		{
			pair<int, int> tempPair = paper_vector.front();
			cout << tempPair.first << ' ' << tempPair.second<<'\n';
			paper_vector.erase(paper_vector.begin());
		}
		*/
		
		/* 구문 체크, 문제 없음
		for (int j = 0; j < paper_vector.size(); ++j)
		{
			cout << paper_vector[j].first << ' ' << paper_vector[j].second << '\n';
		}
		*/
		
		
		while (!paper_vector.empty()) {
			pair<int,int> tempPair = paper_vector.front();
			
			//뒷부분에 최대값 있나 검증
			int check = 1;
	
			for (int k = 0; k < paper_vector.size(); ++k) {
				if (paper_vector[k].second > tempPair.second)
					check = 0;
				
			}
			
			//최대값이 아닐 경우
			if (check != 1)
			{
				paper_vector.push_back(tempPair);
				paper_vector.erase(paper_vector.begin());
				check = 1;
			}
			else//최대값일 경우, idx비교
			{
				out_cnt += 1;
				if (tempPair.first != paper_idx) { //idx랑 안 맞으면
					paper_vector.erase(paper_vector.begin());
					
				}
				else {
					
					break;
				}
			

			}
		}

		cout << out_cnt << '\n';
	
		
	}
}