//제목 : 하얀 칸
//목적 : 체스판에서 하얀칸 위에 놓인 말의 개수를 구하기
//조건 : 왼쪽 위는 흰 칸으로 고정. 체스판은 8x8

/*아이디어 : char의 2차원배열을 탐색할 수 있는가
1. char 2차원배열 생성
2. 특정 인덱스인 경우 검사 및 개수 체크
*/

/*구현 : 흰색 인덱스를 알아내는 법
1. (0,0)~(7,7)까지
2. 두 인덱스의 합이 짝수면 흰색, 홀수면 검은색

or
1. 0~63까지
2.
*/

//느낀점 : 
#include <iostream>

using namespace std;

char chessboard[8][8];

int main()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> chessboard[i][j];
			//scanf("%c", &chessboard[i][j]);

	int cnt = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
		{
			if ((i + j) % 2 == 0)
			{
				if (chessboard[i][j] == 'F') cnt++;
			}
		}

	cout << cnt;
}