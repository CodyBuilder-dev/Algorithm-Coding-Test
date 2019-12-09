//제목 : 플로이드
//목적 : 한 도시로부터 다른 도시로 최소비용으로 이동하는 법 찾기
//조건 : 도시는 100개, 버스는 10만개, 

/*아이디어 :
1. 가중치가 있는 비용행렬 구하기
2. 비용행렬에 BFS써서 탐색하기
3. 도착하는 도시들의 비용을 결과배열에 넣기
*/

/*구현 :
1.Queue의 Vector를 만들어보자?!(X)
2.플로이드-와셜 알고리즘을 쓰자
*/

/*느낀점 :
1.남의 코드를 베껴올 때는, 내 기존 코드랑 변수명 충돌 나나 주의할것
2.플루이드와셜 알고리즘은 증명이 어려울거같은데?
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int costArray[100][100];

void Floyd_Warshall() {
	for (int m = 0; m < N; m++)
		for (int s = 0; s < N; s++)
			for (int e = 0; e < N; e++)
				costArray[s][e] = costArray[s][e] > costArray[s][m] + costArray[m][e] ? costArray[s][m] + costArray[m][e] : costArray[s][e];
}

int main()
{
	cin >> N >> M;

	//인접행렬 최소로 받기
	for (int i = 0; i < M; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if(costArray[start - 1][end - 1] == 0)
			costArray[start - 1][end - 1] = cost;
		else 
			costArray[start - 1][end - 1] = min(costArray[start - 1][end - 1],cost);
	}

	/*
	//0인 부분 전부 987987987
	for(int i = 0;i<N;++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;
			else if (costArray[i][j] == 0) costArray[i][j] = 987987987;
		}
		*/
	//여기서부터 코딩 시작
	Floyd_Warshall();

	/*
	//987987987인 부분 전부 0
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;
			else if (costArray[i][j] == 987987987) costArray[i][j] = 0;
		}
	*/

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << costArray[i][j] << ' ';
		cout << '\n';
	}

}

