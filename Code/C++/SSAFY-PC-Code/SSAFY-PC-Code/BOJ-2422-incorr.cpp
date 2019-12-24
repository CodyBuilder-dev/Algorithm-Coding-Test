//제목 : 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
//목적 : N가지 중 3가지 아이스크림을 고르되, 특정 조합을 제외한 경우의 수
//조건 : 아이스크림은 최대 200가지, 금지 조합은 최대 1만개

/*아이디어 : 그냥 간단한 조합문제
1. 넥퍼뮤로 돌리기 = 200C3 = 160만
2. 조합 들어가있으면 배제 = 만
->시간이 되나? 너무 큰데?


*/
/*아이디어2 : 개수만 구하면 되므로,
수식적으로 nC3 - 금지조합중 2개가 들어가는 경우 - 금지조합중 3개가 들어가는 경우
->잘 모르겠음
금지조합 0개 들어가는 경우 + 금지조합 1개
-> 되는 조합 : 
*/

/*아이디어3 : 아! 3중 for문에 인접행렬로 접근해보자*/

/*느낀점
1. deque지만 헤더로 queue써도 상관없음
*/
#include <iostream>
#include <set>
#include <queue>
//#include <deque>
#include <algorithm>
using namespace std;

int N, M;

bool banned[201][201];
deque<int> combi;
set<deque<int>> combiSet;
//priority_queue<int>  combi;

void make_combi(deque<int> dq)
{
	if (dq.size() == 3) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (banned[dq[i]][dq[j]] == true) return;
		
		sort(dq.begin(), dq.end());
		combiSet.insert(dq); return;
	}

	for (int i = 1; i <= N; ++i) {
		if (find(dq.begin(), dq.end(), i) != dq.end()) continue;
		//deque<int> newdq=dq; //복사 되는지 확인해봐야함
		deque<int> newdq(dq);
		newdq.push_back(i);
		make_combi(newdq);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		banned[x][y] = true;
		banned[y][x] = true;
	}

	make_combi(combi);
	cout << combiSet.size();
}