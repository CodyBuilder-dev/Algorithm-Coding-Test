//제목 : 최대 힙
//목적 : 최대 힙을 이용해서, 여러 자연수를 입력받고, 제일 큰 값부터 출력하기
//조건 : 입력이 0인경우 출력, 그 외의 정수일 경우 배열에 넣는다. 자연수 범위는 2^31보다 작으므로 int로 가능하다.

/*
아이디어 : 여러가지 방법이 있는데
1. 순수 배열로 힙을 직접 만들고, 새로운 숫자 들어올 때마다 직접 만든다.
2. priority que를 쓰면 매우 쉽게 된다.
*/
//문제점 : priority queue를 쓰면 시간이 초과된다.
//해결 : 우선 cin cout부터 건드려보자. printf로 바꾸면 성공함

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	
	int N;
	scanf("%d",&N);
	
	priority_queue<int> pri_que;
	int temp;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d",&temp);
		if (temp == 0)
			if (!pri_que.empty()) {
				printf("%d\n",pri_que.top());
				pri_que.pop();
			}
			else printf("%d\n",0);
		else
			pri_que.push(temp);
	}
}