//제목 : 로프
//목적 : 로프 여러개가 주어질 때 이로부터 구할 수 있는 최대 중량
/*
예시 이해 : 2개, 10, 15인 경우 최대 중량이 왜 20?
여러개 쓸꺼면 무조건 병렬로 써야 하는듯, 그러니 N/2<=10 라 N=20
*/

/*아이디어 : 수학적으로다가 N/k <= 최소값 식을 세운 후 완전탐색
*/

/*아이디어 2 : 탐색을 할거면 일단 센놈부터 한명씩 뽑아보자
*/

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}


int main()
{
	int N;
	cin >> N;
	int *rope;
	int max=0;
	int temp;

	rope = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> rope[i];
	}

	//내림차순으로 정렬
	sort(rope,rope+N,desc);

	//최대값부터, 로프 한개씩 넣으면서 최대값 검출
	for (int i = 0; i <N; ++i)
	{
		//하나 추가되면 분모 +1, N은 로프의 최소값 *분모
		temp = rope[i] * (i + 1);
		if (max < temp) max = temp;
	}
	cout << max;
	delete[] rope;
	return 0;
}