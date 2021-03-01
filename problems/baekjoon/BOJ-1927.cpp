//제목 :최소 힙
//목적 : 자연수 입력을 받아서, 배열에서 최소 순서대로 빼서 출력하는 최소 힙을 구현한다.
/*
아이디어 :
1. 배열이나 링크드 리스트 만들고, 최소 힙을 직접 구현한다.
2. stl의 priority que를 이용하되, 순서를 거꾸로 바꾼다
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	priority_queue<int,vector<int>,greater<int>> pri_que;
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