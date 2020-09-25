//제목 : 수 정렬하기 2
//목적 : n. 대표적으로는 병합 정렬, 힙 정렬을 쓸줄 아는가
//아이디어 : quick sort를 구현하기는 너무 귀찮고, 
//sort 써서 성능을 눈으로 한번 보자
//느낀점 : 내가 짠 heap sort보다 빠름ㅋㅋ

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int *numarray;
	cin >> N;

	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	sort(numarray,numarray+N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';
}