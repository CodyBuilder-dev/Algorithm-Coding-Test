/*제목 : 한길이의 생일 선물
목적 : 원판이 주어졌을 경우, 원판이 떨어지는 위치를 계산하라
조건 : 구멍, 디스크는 300,000 반지름은 최대 10^9
*/

/*아이디어 :
브루트 포스 = 300,000^2 = 무조건 터짐
이분 탐색 = 가능
*/

/*아이디어 2 : 거꾸로 생각하기 -> 만약 크기 k짜리가 들어오면, 어디까지 갈 수 있을까? 를 미리 생각

중가으로 위치를 잡음, 처음부터 중간까지 쭉 탐색해서 제일 작은 구멍 찾기
-> 구멍보다 큰놈은 그 앞, 구멍보다 작은놈은 그 뒤,부터 중간, 

처음에 보고 중간값보다 큰놈, 중간값보다 작은놈들을 걸러냄


*/

/*아이디어 3 : 넓이, 깊이 pair를 dequeue에 넣고 돌리기
1. 자기보다 1단계 작은놈의  depth를 찾는다
2. 그 depth 앞에 있는 놈 중 가장 작은놈 찾는다
3. 
*/

/*아이디어 4 : 위에서 봤다고 생각하고, 배열을 다 뒤엎어버리기
1. 68312 이딴식이면, 66311 이런식으로
*/
#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int T;
int N, Q;
int r[300000];
int q[300000];
int blocked[300000];

//deque<pair<int, int>> width_first;
//deque<pair<int, int>> depth_first;


void input(int N, int Q) {
	for (int i = 0; i < N; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < Q; ++i) {
		cin >> q[i];
	}
}

//내림차순 정렬
void desc() {
	int min = r[0];
	for (int i = 0; i < N; ++i) {
		if (r[i] > min) r[i] = min;
		else min = r[i];
	}
}

//이진탐색 수행
int binarySearch(int q) {
	int left, right, mid;
	left = 0; right = sizeof(r); mid = (left + right) / 2;

	while (left < right) {
		if (q > mid) right = mid;
		else left = mid;

	}
	return mid;
}

void solution() {
	//binary search를 계속 여러번 돌려서, 최종적으로 나오는 위치값 찾기
	//0 미만일 경우  0, 아니면 마지막 디스크 위치 출력
}
int main() {
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N >> Q;
		input(N, Q);

		//이진탐색 start
		for (int j = 0; j < Q; ++j) {
			q[j] 
		}
	}
	return 0;
}