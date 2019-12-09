//제목 : 카드2
//목적 : 주어진 규칙에 따라 카드를 움직이고 마지막에 남는 카드
//조건 : 카드 1에서는 카드가 1000장이지만, 카드 2에서는 카드가 500,000장

/*아이디어 : 그냥 큐 쓰면 알아서 통과됨;*/
#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> que;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		que.push(i);

	/*사이즈 확인은 가능
	cout << que.size();*/

	/* 임의접근 불가능
	for (int i = 0; i < 5; ++i)
		cout << que[i];
	*/
	while (que.size() > 1)
	{
		//cout << que.front() << ' ';
		que.pop();

		int first = que.front();
		que.pop();
		que.push(first);
	}
	cout << que.front();

}