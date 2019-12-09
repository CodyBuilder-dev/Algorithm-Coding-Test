///제목 : 가장 긴 감소하는 부분 수열
//목적 : 수열이 주어진 경우, 감소하는 수열의 길이 중 가장 긴 것을 구하여라
//조건 : 수열의 길이는 최대 1000

/*아이디어 :
1.그냥 길이 N부터 1까지 다 찾아보기 = O(N^2) 해결가능
*/

/*구현 : 3중 for문으로 해결가능*/

/*
문제점 : 부분수열이란, 서로 멀리 떨어져 있어도 부분 수열이라고 볼 수 있음
->단순 for문으로만 풀 경우 떨어진 수열 찾기가 매우 힘들어짐
*/

#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> numArray;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		numArray.push_back(temp);
	}
	
	int maxLength = 0;
	bool isDeclined = false;

	for (int i = N; i >0; --i) //길이 N짜리 수열부터 검사
	{
		for (int j = 0; j < N - i + 1; ++j) //0번지부터 N-i번지까지 
		{
			for (int k = j; k < j+i-1; ++k) {
				if (numArray[k] < numArray[k + 1]) break;
				if (k == j+i-2) isDeclined = true;
			}
			if (isDeclined) break;
		}

		if (isDeclined) {
			maxLength = i;
			break;
		}
	}

	cout << maxLength;
}