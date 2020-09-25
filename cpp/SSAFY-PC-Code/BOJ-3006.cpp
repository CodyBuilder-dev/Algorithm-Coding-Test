//제목 : 터보소트
//목적 : 터보소트 규칙에 따라 정렬하고, 정렬과정 중에서 숫자 위치 바뀐 횟수
//(즉 어떤 소팅 알고리즘을 만들고 성능을 검증하는 것인듯)
//조건 : 배열의 크기는 10^5. 즉  O(N^2)을 쓰면 터짐

/*구현 : 터보소팅 알고리즘을 짠다
1. 현재 횟수 홀/짝 확인
2. 홀이면 안 고른놈 중에 제일 작은놈. N번째면 아마 N/2일 듯
3. 짝이면 안 고른놈 중에 제일 큰놈. N번째면 아마  N/2+1
4. 아무튼 그놈을 일단 순차적으로 찾음 O(N)
5. 찾으면 버블소팅 및 횟수 세기 O(N)
6. 무한반복
*/

/*구현 : 함수사용
1. 입력함수 속도 신경써야될수 있음 (O)
2. 정적할당. 동적할당 신경써야할 수 있음 (별 차이 없음)
3. 결정적으로, 자리 바꾸는걸 직접 수행하느냐 안하느냐 차이인듯
(진짜 swap하면서 바꾸느냐, 아니면 그냥 결과만 바로 만들어 내느냐)
*/

/*느낀점 :
1. 조건문 안에서 조건문의 i<N의 N을 바꿀 수도 있다.
*/
#include <iostream>

using namespace std;

int main()
{
	int N;
	int numArray[100000] = { 0 }; //0 초기화

	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d",&numArray[i]); //번지랑 숫자 차이 주의

	for (int i = 1; i <= N; ++i) {
		int target;
		int idx;
		int dist;
		int cnt;

		if ((i & (1<<0)) == 1) //홀수.작은놈
		{
			target = i / 2 + 1; //이번에 찾을놈 선택

			for (int j = 0; j < N-(i-1); ++j) //찾을놈 현 위치 파악
				if (numArray[j] == target) {
					idx = j; break;
				}

			//현 위치로부터 맨 앞 base까지 거리 구하기
			dist = idx;

			//중간에 그놈 빼고, 그 뒤에놈들 다 땡겨오기
			memmove(numArray + idx, numArray+(idx+1), sizeof(int)*(N-i-idx));
			//마지막은 0으로 채우기
			numArray[N - (i - 3)] = 0;
			//cnt는 그냥 계산
			cnt = dist;

			/*//target-1에 위치할 때 까지 직접 옮기면 시간초과
			while (idx > target - 1)
			{
				swap(numArray[idx], numArray[idx - 1]);
				cnt++;
				idx--;
			}
			*/

		}
		else //짝수. 큰놈
		{
	
			target = N - (i / 2 - 1); //이번에 찾을놈 선택

			for (int j = 0; j < N-(i-1); ++j) //찾을놈 현 위치 파악
				if (numArray[j] == target) {
					idx = j; break;
				}
			//현 위치로부터 맨 뒤까지 거리 구하기
			dist = N - i - 2 - idx;
			//중간에 그놈 빼고, 그 뒤에놈들 다 땡겨오기
			memmove(numArray + idx, numArray + (idx + 1),sizeof(int)*(N - i -idx));
			//마지막은 0으로 채우기
			numArray[N - (i - 3)] = 0;
			//cnt는 그냥 계산
			cnt = dist;
		}
		printf("%d\n",cnt);
	}
}