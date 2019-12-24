//제목 : 수 정렬하기
//목적 : n^2. 대표적인건 버블소트,인서트소트를 쓸 줄 아는가
//아이디어 : 버블소트 구현. 자료구조는 그냥 배열
//주의점 : 버블소트시 인덱스 위치 정확히 파악.
//포인터를 함수에 넣고 포인터를 리턴한다면 그때 어떻게 되는지 확인

#include <iostream>

using namespace std;
//스왑함수를 구현을 해야되나

//버블소트 구현. 함수로 하면 깔끔하거든
//포인터를 리턴하기 보단, 그냥 void로 하는게 나음

void bubble_sort(int *numarray,int len)
{
	int temp = numarray[0];
	//for 2중으로 돌리면 끝
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len -1-i; ++j) {
			if (numarray[j] > numarray[j + 1])
			{
				temp = numarray[j];
				numarray[j] = numarray[j + 1];
				numarray[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int N;
	int *numarray;
	cin >> N;

	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	bubble_sort(numarray,N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';
	
}