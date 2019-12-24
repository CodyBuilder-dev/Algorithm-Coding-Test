//제목 : 색종이
/*목적 : 흰색 도화지 위에, 검은색 색종이를 붙인 후 영역 구하기
(즉, 2차원 배열을 좌표로 보고, for문으로 완전탐색 할 수 있는가?)
*/

//조건 : y좌표의 방향이 반대이므로 주의해야 함

#include <iostream>

using namespace std;

int main()
{
	int white[100][100] = { 0 }; //이런식으로 정적할당하면 메모리 어떻게?
	int N;
	cin >> N;
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		// 0 1 2 3
		for (int j = 90-y; j < 100 - y; ++j)
			for (int k = x; k < 10 + x; ++k)
				white[j][k] = 1;
	}
	
	int sum = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (white[i][j] == 1) sum++;
	cout << sum;
	
}