//제목 : 이장님 초대
//목적 : 이장님을 초대하는 가장 빠른 날짜
//조건 : 나무는 최대 10만개가 100만 일까지 가능

/*아이디어 :
1. 당연히 제일 오래 걸리는 놈을 가장 먼저 심는게 맞음
2. 1일차에 n일짜리를 심으면 n일, 2일차에 n2짜리를 심으면 2+n2일...
3. 매일 심어가면서, 가장 큰 값을 찾으면 됨
*/

/*구현1 :
시뮬레이션 식으로 1일씩 검사하는 방법? 너무 큼 (X)
*/

/*구현2 : 
크기를 비교하는 방법 Okay
1.나무 개수 입력, 나무 일자 배열 입력
2.내림차순 정렬
3.for문으로 배열 인덱스+배열값
*/

/*주의점
나무를 심는데 걸리는 시간 + 나무가 자라는 시간 + 이장님 오는 시간
을 
배열 인덱스와 주의해서 계산할 것
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N; //나무 N개
int days[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> days[i];

	sort(days, days + N,greater<int>()); //0번지부터,, 

	int minday = -987987987;
	for (int i = 0; i < N; ++i)
		minday = max(minday, i + days[i] + 2);
	
	cout << minday;
	
}

