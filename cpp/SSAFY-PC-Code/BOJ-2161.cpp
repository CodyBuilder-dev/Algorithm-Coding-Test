//제목 : 카드1
//목적 : 카드 묶음을 주어진 조건대로 움직여서 마지막에 남는 카드 찾기
//조건 : 카드의 장수는 최대 1000장

/*아이디어 : 회전하는 큐 문제와 비슷함
1. 카드 묶음이 선형임
2. 동작이 맨 앞의 카드를 pop해서 맨 밑으로 push 하는것 뿐
-> queue를 이용하면 된다.
*/

/*구현 : 
1. queue 생성
2. 변수 집어넣기
3. 
*/
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
		cout << que.front() << ' ';
		que.pop();
			
		int first = que.front();
		que.pop();
		que.push(first);
	}
	cout << que.front();

}