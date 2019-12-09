//제목 : 수 찾기
//목적 : N개의 나열된 수 안에서 X가 존재하는지 찾기
/*조건 : 수는 당연히 정렬 안된 채로 들어온다.
개수는 최대 10^5로, N^2쓸 경우 10^10으로 10초가 넘을 수도 있다.
*/
/*
아이디어 : 그냥 얌전히 이분탐색 쓰면 됨.
for문 한개 돌리고, 나누기 2는 재귀로 돌리면 되겠네
*/

/*이진 탐색 구현
1. 배열 
2. 왼쪽 끝, 오른쪽 끝으로부터 mid구해서 비교
3. 크거나 작으면 새롭게 bs
4. 정지조건은 어떻게 하는가....
주의점 : mid+-1 해줘야하고, left>right해줘야 하는듯
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int* target_array;
int* find_array;
int* answer_array;

int binary_search(int left,int right,int find)
{
	if (left > right) return 0;
	
	int mid = (left+right)/2;
	if (target_array[mid] > find)
		binary_search(left, mid-1, find);
	else if (target_array[mid] < find)
		binary_search(mid+1, right, find);
	else
		return 1;
	
}

int main()
{
	scanf("%d", &N);

	target_array = new int[N];

	for (int i = 0; i < N; ++i)
		scanf("%d", &target_array[i]);

	sort(target_array, target_array + N);

	scanf("%d", &M);

	find_array = new int[M];
	answer_array = new int[M]();

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);

	
	//아랫부분에 코딩
	for (int i = 0; i < M; ++i)
		if(binary_search(0, N-1, find_array[i]))
			answer_array[i] = 1;
	
	for (int i = 0; i < M; ++i)
		printf("%d\n", answer_array[i]);
}