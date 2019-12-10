//제목 : 그래도 수명이 절반이 되어서는...
//목적 : 메모리에 데이터를 저장할 때, 데이터 블록의 wear level이 최소가 되게 하라
/*조건 : 
0. 라이브러리 사용 없이 풀어보기
덩어리는 나온 순서대로 해야됨!
*/

/*아이디어 : 완전 브루트 포스
덩어리 1 배치
그 다음부터 덩어리 2 배치
그 다음부터 덩어리 3 배치
...
덩어리 N 배치

결과 계산
결과 저장
반복
결과 비교
*/

/*덩어리 배치 로직 : 브루트 포스
0번부터 그냥 배치 고고
한두개면 N중 for문으로 하는데, 안되니까 재귀로

*/
/*아이디어 : 그리디하게 최소값 근처부터?
1. 입력 받기

2.1 덩어리 길이 최대값 확인
2.2 최소 wear level 확인
2.3 최소 wear level 근처에서 탐색시작
2.4 최소 wear level 근처에서 window moving으로 탐색
2.5
*/


#include <iostream>

using namespace std;

int T;
int N, K;
int memory[200000];
int block[200000];
int minWear = -987654321;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> memory[i];

	for (int i = 0; i < K; ++i)
		cin >> block[i];
}

void put_memory_recur(int startIdx, int order, int nowMin) { //시작위치와 길이를 전달해 재귀 돌리기
	//블록 다 쓰면 돌아감
	if (order >= K || startIdx + block[order] >= N) {
		if (minWear <= nowMin) minWear = nowMin;
		return;
	}

	for (int i = startIdx; i < startIdx + block[order]; ++i)
		if (memory[i] > nowMin) nowMin = memory[i];

	for (int i = startIdx + block[order]; i < N; ++i)
		put_memory_recur(i, order + 1, nowMin);

}

int main() {
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		minWear = -987654321;
		input();
		for (int j = 0; j < N; ++j)
			put_memory_recur(j, 0, minWear);
		cout << '#'<< i << ' ' << minWear << '\n';
	}
}
