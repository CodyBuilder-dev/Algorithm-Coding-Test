//제목 : 수 정렬하기 3
//목적 : 숫자가 적은 경우 카운팅 정렬 사용
//제대로 쓸 줄 몰라서 stl 벡터 사용함
//메모리 초과 문제 발생 가능
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	int max;
	int *numarray;
	int *cntarray;
	vector<int> ans;
	cin >> N;

	numarray = new int[N];
	

	for (int i = 0; i < N; ++i)
	{
		cin >> numarray[i];
	}
	max = *max_element(numarray, numarray+N);
	//cout << max;
	
	cntarray = new int[max+1]();
	
	for (int i = 0; i < N; ++i)
	{
		cntarray[numarray[i]]++;
	}

	for (int i = 0; i <= max; ++i)
	{
		while (cntarray[i] != 0) {
			cntarray[i]--;
			ans.push_back(i);
		}
	}

	for (int i = 0; i < N; ++i)
		cout << ans[i] << '\n';

	delete[] numarray;
	delete[] cntarray;
	return 0;
}