//제목 : 1로 만들기
//목적 : 3가지 연산을 적절히 배열하여 주어진 수를 1로 만들기
//조건 : 정수의 크기는 최대 10^6.이므로 경우의수 매우 많음

/*아이디어 : 생각해보면 방향이 3갈래인 트리의 탐색으로 생각할 수 있음
1. 어떤 방향으로 가야 1이 될지 어떻게 아는가? - 알지못함. 완탐 해야함
2. 1이 되었다면, 그 경우 최소의 값은 언제인가? - 최소값 저장 DP를 써야되네

점화식 -> 불가능함
메모이제이션 -> 오케이
바텀업으로? -> 바텀업이야말로 점화식을 알아야함. fail
탑다운으로? -> 함수 세가지 호출한 후 최소값을 리턴하는 식으로
*/


/*느낀점 : 
1.DFS+DP를 쓰려면, dp함수안에 가능한 진행 경우를 다 넣어줘야 한다
2.근데 어떻게 넣느냐에 따라서, 겁나 느리거나 겁나 빠르거나 한다.


*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int minCnt[1000001];

int find_min_op(int start)
{
	if (start == 1) return 0;
	if (minCnt[start] != 0) return minCnt[start]; //start =1 말고는 0인 경우 없으므로 안전
	
	priority_queue<int, vector<int>, greater<int>> minima;
	if (start % 6 == 0) { //2,3나눠떨어지는 경우
		minima.push(find_min_op(start / 3)+1);
		minima.push(find_min_op(start / 2)+1);
		minima.push(find_min_op(start - 1)+1);

		minCnt[start] = minima.top();
		return minCnt[start];
	}

	else if (start % 2 == 0) {
		minima.push(find_min_op(start / 2)+1);
		minima.push(find_min_op(start - 1)+1);
		minCnt[start] = minima.top();
		return minCnt[start];
	}
	else if (start % 3 == 0) {
		minima.push(find_min_op(start / 3)+1);
		minima.push(find_min_op(start - 1)+1);
		minCnt[start] = minima.top();
		return minCnt[start];
	}
	else {
		minCnt[start] = find_min_op(start - 1)+1;
		return minCnt[start];
	}
}
int main()
{
	cin >> N;
	find_min_op(N);
	cout << minCnt[N];
	
	
	
	return 0;
}