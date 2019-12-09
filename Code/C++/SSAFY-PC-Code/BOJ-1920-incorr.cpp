//제목 : 수 찾기
//목적 : N개의 나열된 수 안에서 X가 존재하는지 찾기
/*조건 : 수는 당연히 정렬 안된 채로 들어온다.
개수는 최대 10^5로, N^2쓸 경우 10^10으로 10초가 넘을 수도 있다.
*/
/*
아이디어 : 정렬 안하고 풀면 겁나 오래걸릴텐데 ㅋㅋ
무식한 탐색 고고
*/
//문제점: 응 시간초과~

/*아이디어 2: 정렬한 다음에, 딱 자기 찾는 거 찾으면 탐색 중단
하려고 했으나, 그럼 find array까지 정렬해야 하므로 답이 달라짐
*/
//문제점 : 그래도 시간초과~
#include <iostream>

using namespace std;

int N, M;
int *target_array;
int *find_array;
int *answer_array;

int main()
{
	scanf("%d", &N);

	target_array = new int[N];

	for (int i = 0; i < N; ++i)
		scanf("%d", &target_array[i]);
	
	scanf("%d", &M);

	find_array = new int[M];
	answer_array = new int[M]();

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (target_array[j] == find_array[i])
				answer_array[i] = 1;
	
	for (int i = 0; i < M; ++i)
		printf("%d\n", answer_array[i]);
}