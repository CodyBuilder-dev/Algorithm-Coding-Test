//제목 : Shuffle-O-Matic 2019
//목적 : 셔플오매틱 기구의 동작을 이해하고, 구현한 뒤 최소횟수 구하기
//유형 : 시뮬레이션 + 브루트포스
//조건 : N<=12 이므로 12^5 = 248000 할만함
/*
아이디어1 : 일단 셔플오매틱 기구의 동작 자체를 이해하는 것이 중요
x는 0~N-1에서 고를 수 있고,식을 수학적으로 좀 나타내 보자

x = 0일때 123456 그대로
x = 1일때 124356 중간값 +1, -1 
x = 2일때 142536 중간값 반대로 +2, 그 바깥쪽값 반대로 +1
x = 3일때 415263 중간값 반대로+3 , 그 바깥쪽값 반대로 +2  최외각값 반대로 +1
x = 4일때 451623 중간값은 초과되므로 정지,
x = 5일때 456123 swap보다는 숫자로 나타내는게 좋은듯

엄청 어려워보이지만 사실 +1되면 조금의 규칙만 넣어주면 된다.
*/

/*아이디어2 : 브루트 포스.
최대 5회이므로 즉 (n)^5 가지 경우의 수를 모두 따져봐야 한다.
5회까지 모든 경우의 셔플을 수행하고, 되면 최소값 안되면 -1
*/

/*아이디어 3: 마지막으로 정렬상태 확인
정렬상태 확인은 어떻게 할 것인가...
하나하나 비교하면서 순서대로 되어있는지 확인?
DFS의 재귀를 이용하즈아
*/

#include <iostream>

using namespace std;

int x;
int T;
int N;
int *card_array;

bool check_sorted()
{
	int parity_up, parity_down;
	for (int i = 0; i < N; ++i) {
		if (card_array[i] < card_array[i + 1]) parity_up++;
		if (card_array[i] < card_array[i + 1]) parity_down++;
	}
	return (parity_up == N || parity_down == N);
}

void shuffle(int x)
{
	card_array[N/2]
}

void DFS()
{
	//여기 안에 1~n-1가지 경우의수 체크 배열을 만들고
	//배열을 체크하면서 돌기? 아니 이거 BFS인가? 습

}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> N;

		card_array = new int[N];

		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			card_array[j] = temp;
		}
		

	}
}