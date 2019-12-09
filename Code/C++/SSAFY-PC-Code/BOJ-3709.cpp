//제목 : 레이저빔은 어디로
//목적 : 우향우 거울이 놓여져 있는 보드판위에 레이저를 쏘면 레이저의 좌표

//조건 : 주의! 행과 열을 반대로 써놓음. 번역이 짜증나서 못풀겠음

//행 : 세로, 열 : 가로 

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N, r;
	int x, y;

	bool **board;

	cin >> T;

	for (int i = 1; i<=T;++i){
		cin >> N >> r;

		board = new bool*[N];
		for (int j = 0; j<N;++j)
			board[j] = new bool[N];

		for (int j = 0; j < r; ++j)
		{
			cin >> x >> y
		}
		cin >> x >> y; //레이저 좌표
	}
}