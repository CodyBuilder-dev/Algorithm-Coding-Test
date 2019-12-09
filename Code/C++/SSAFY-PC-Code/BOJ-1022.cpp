//제목 : 소용돌이 예쁘게 출력하기
//목적 : 모눈종이 칸에 숫자를 소용돌이 규칙에 따라 채워넣은 후 출력
//조건 : 모눈종이 크기는 최대 최대 10000x10000. 그러나 실제 칸은 최대 49x4

/*아이디어 : 
1. 우선 종이를 소용돌이 모양으로 채운다
-> '종이'는 2차원배열로 구현하면 됨
-> 소용돌이는...1부터 올라가는 정수의 범위를 구분해 넣는다
2. 소용돌이 범위 계산
소용돌이가 들어갈 네모 칸은 안에서부터 1^2, 3^2, 5^2, 7^2...
n번째 사각형의 테두리에 들어갈 수들은
개수 = (2n-1)^2-(2n-3)^2
범위 = (2n-3)^2 + 1 ~ (2n-1)^2
사각형 좌표의 범위 = (-n,-n)~(n,n)
규칙 =(n,n)좌표에는 항상 그 사각형 최대 수가 들어감
-> 거꾸로 돌아가면서 그리기 가능?
*/

/*구현 :
1. 우선 판에다 10^4x10^4 다 그림
2. 문제에서 주어진 범위 찾아서 출력
*/

#include <iostream>

#define ZERO 5000 //중심이 되는 점을 매크로로 지정

using namespace std;

int r1, c1, r2, c2;

int board[10001][10001];

void input()
{
	cin >> r1 >> c1 >> r2 >> c2;
}

void print_vortex()
{
	for (int i = ZERO+r1; i < ZERO+r2; ++i) {
		for (int j = ZERO+c1; j < ZERO+c2; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}
void fill_board()
{
	board[ZERO][ZERO] = 1;
	for (int k = 1; k < 5000; ++k) {
		int maxNum = (2 * k - 1) * (2 * k - 1);
		int maxCoord = ZERO + k;
		board[maxCoord][maxCoord] = maxNum;
		for (int n = 0; n < 4; ++n) { //4개의 변 그리기
			for (int l = 1; l <= 2 * k; ++l) {
				switch (n) {
				case 0:
					board[maxCoord][maxCoord - l] = maxNum - l; break; //break? continue?
				case 1:
					board[maxCoord - l][maxCoord - 2 * k] = maxNum - 2 * k - l; break;
				case 2:
					board[maxCoord - 2 * k][maxCoord - 2 * k + l] = maxNum - 2 * k - 2 * k - l;  break;
				case 3:
					board[maxCoord - 2 * k + l][maxCoord] = maxNum - 2 * k - 2 * k - 2 * k - l;	break;
				}
			}
		}
	}
}
int main()
{
	input();
	fill_board();
	print_vortex();
}