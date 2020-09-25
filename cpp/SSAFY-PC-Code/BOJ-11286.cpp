//제목 : 절댓값 힙
//목적 : 힙은 힙인데, 절댓값이 가장 큰 순서대로 정렬

/*
아이디어
1. 우선순위 큐 그대로 쓰고, 그냥 받을 시점에 음수면 양수로 저장한다.
->문제점. 내보낼때 그대로 음수로 내보내야 함.
->그냥 pair를 쓴다?
2. 절대값을 규칙으로 갖도록 큐를 건드린다.
-> 절대값 함수를 만들어서 쓴다.
*/


#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;
struct less_absolute {
	bool operator()(int lower,int higher) {
		return abs(lower) > abs(higher);
	}
};

int main()
{
	int N;
	priority_queue<int, vector<int>, less_absolute> pri_que;
	int temp;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &temp);
		if (temp == 0) {
			if (!pri_que.empty()) {
				printf("%d\n", pri_que.top());
				pri_que.pop();
			}
			else printf("%d\n", 0);
		}
		else pri_que.push(temp);
	}
}