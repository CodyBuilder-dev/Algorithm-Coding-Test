//제목 : 수 정렬하기
//목적 : n^2. 대표적인건 버블소트,인서트소트를 쓸 줄 아는가
//아이디어 : 인서트소트 구현

/*개념 :인서트소트란, 자료를 배열에 넣고, 배열 안에서 크기 비교 후 배열에넣기
 1 3 7 배열에 6이 들어올 경우, 7과 비교해 작고, 3과 비교해 크므로 3과 7사이에 들어간다
장점 : 매우 쉬움. 배열의 크기가 작은 경우에는 퀵소트보다 나음
단점 : 자료구조의 수정이 어렵다.
*/
/*
구현 : 맨 앞에놈 선택
그 전 놈이랑 비교해서 자기보다 크면 swap
자기보다 작은놈 만날때까지 반복
*/

//주의 : 마찬가지로 인덱스 위치에 주의할 것
#include <iostream>

using namespace std;

void insert_sort(int* numarray, int len)
{
	for (int i = 0; i < len-1; ++i) {
		for (int j = i + 1; j > 0; --j) {
			if (numarray[j] < numarray[j - 1]) swap(numarray[j], numarray[j - 1]);
		}
	}
}
int main()
{
	int N;
	cin >> N;
	
	int *numarray;
	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	insert_sort(numarray, N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';

	return 0;
}
using namespace std;