//제목 : 수 정렬하기 3
//목적 : 숫자가 적은 경우 카운팅 정렬 사용

/*
카운팅 정렬의 이해 : 이해자체는 오케이
*/

/*
아이디어 : 제대로 쓸 줄 몰라서 자료구조로 STL과 벡터 사용.
그러나, 라이브러리 떡칠시 메모리 초과 문제 발생 가능
아마도 가장 병목이 되는 구간은, vector에 저장하는 구간같으니
저장하지 말고 바로 출력하자
*/

/*
아이디어 2: 그래도 해결 안 되는거 보니
역시 10,000,000를 어디에 저장하는 것 자체가 문제였음
입력 받아서 바로 cntarray로 가자
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int temp;
	int *cntarray;
	int maxidx;

	cin >> N;

	cntarray = new int[10001]();

	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		cntarray[temp]++;
	}

	maxidx = distance(cntarray, max_element(cntarray, cntarray + 10001));
	
	for (int i = 0; i <= maxidx; ++i)
	{
		while (cntarray[i] != 0) {
			cntarray[i]--;
			cout << i << '\n';
		}
	}

	delete[] cntarray;


	return 0;
}