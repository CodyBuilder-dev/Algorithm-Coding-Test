//제목 : X보다 작은 수
//목적 : 배열에 for문을 쓸 줄 아는가

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, X;
	vector<int> numarray;

	cin >> N >> X;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		numarray.push_back(temp);
	}
	//정렬 하면 안됨 ㅋㅋ
	//sort(numarray.begin(), numarray.end());

	
	for (int i = 0; i < N; ++i)
		if (numarray[i] < X) cout << numarray[i] << ' ';
	
}