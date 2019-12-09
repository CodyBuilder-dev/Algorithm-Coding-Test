//제목 : 지영 공주님의 마법 거울
//목적 : 거울의 심리상태에 따라 공주님의 상태를 다르게 표현하라
//조건 : 심리상태는 3가지, 거울의 크기는 최대 100x100

/*아이디어 : 2차원으로 나열된 문자열을 처리하는 알고리즘 짜기
1. Vector of strings
2. char array
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N, K;
	vector<string> board;
	
	cin >> N;

	for (int i = 1 ; i <= N; ++i)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	cin >> K;

	switch (K) {
	case 1: 
		break;
	case 2:
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N / 2; ++j)
				swap(board[i][j], board[i][N - 1 - j]);
		break;
	case 3:
		for (int i = 0; i < N / 2; ++i)
			swap(board[i], board[N - 1 - i]);
		break;
	}

	for (int i = 0; i < N; ++i)
		cout << board[i] << '\n';
}