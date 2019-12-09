//제목 : 가장 큰 정사각형
//목적 : N*M배열에서 1로 된 가장 큰 정사각형의 크기를 구하기
/*조건 : 최대 1000x1000. 즉 한바퀴 다 도는데 100만
한바퀴를 다 돌면서, 최대 100만을 다 찾아야 함
즉 시간복잡도 = 100만*100만 = 1조
*/
/*아이디어 : 시간복잡도상 DFS로 불가능
-> 2차원배열에서 DP를 사용할 줄 아는가?
1. 오른쪽 아래로 내려가면서 0 언제나오나 체크
2. 0이 나오면, 왼쪽 위부터 정사각형의 최대 크기는 그거를 못 벗어나리라는 것을 알수있음
3. 부분 사각형에 대해 최대사각형 찾기 함수 수행
---------------------
0이 나온 다음 행, 다음 열부터 탐색
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> LU,RD,RU,LD;

int N, M;
bool board[1000][1000];

int find_nemo(pair<int,int>start,pair<int,int>RD)
{
	//왼쪽 위부터 시작
	//0만날떄까지 오른쪽으로. 0만나면 아래로
	//반복
	//최종적으로 결정된 가로,세로 길이에서 짧은놈 선택
	int right=987654, down=987654;
	int i = 0, j = 0;
	while (start.first <= RD.first && start.second <= RD.second)
	{
		if (board[start.first + i][start.second + j] == false) {
			if (j == 0) {//다 끝난 경우
				down = i-1;
				break;
			}
			right = min(right, j);
			j = 0;
			i++;
		}
		j++;
	}
	
	return right * down;
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &board[i][j]);
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << board[i][j];
		cout << '\n';
	}*/

	int y = 0, x = 0;
	while (y != N - 1 || x != M - 1) {

	}
			
}

