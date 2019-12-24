//제목 : RGB거리
//목적 : 집을 3가지 색 중 하나로 칠할 때, 모든 집을 칠하는 비용의 최소값
//조건 : 인접한 집은 같은 색으로 칠할 수 없다. 집은 최대 1000개이다

/*아이디어 : (DP인걸 모른채로 접근한다 치면)
1. 각 집별로 경우의 수가 2이므로, 차수가 2이고 깊이가 집 개수인 트리로 생각
이러면 근데 O(2^1000)이 되므로, 그냥 완탐을 할 수는 없음
-> 자연스럽게 백트래킹, DP로 넘어가게 됨
2. 백트래킹 : 더해가는 값이 현재 알려진 최소값보다 크면 탈출
3. DP? : 점화식 vs 메모이제이션
->점화식은 모르겠음. 아마 안 될 듯
->메모이제이션? i번째 집을 칠하는 방법은 1~i-1칠하는 최소값에 i번째 값 더하기
4. 선택에 따라 최종값이 다양한 경우로 달라지는 DP 문제임
->
*/

/*구현  : 바텀업으로 짜기가 애매함. 탑다운으로 짜야함
*/
#include <iostream>

using namespace std;

int N;
int minCost[1000][3]; //i번째 집을 j색으로 칠할 때의 최소값
int colorCost[1000][3]; //i번째 집을 j색으로 칠할 때 가격

int calc_mincost(int num,int nowColor) //i번째 집을 j색으로 칠할 때의 최소값
{
	//값이 있을 경우
	if (minCost[num][nowColor] != 0) return minCost[num][nowColor];

	//값이 없을 경우, 더 파고들어서 계산
	else {
		int minima = 987654321;
		for (int i = 0; i < 3; ++i) {
			if (nowColor == i)  continue; //같은 색이면 뛰어넘음
			int temp = calc_mincost(num - 1, i)+colorCost[num][nowColor];
			if (temp < minima) minima = temp;
		}
		minCost[num][nowColor] = minima;

		return minima;
	}
		
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> colorCost[i][j];
	
	minCost[0][0] = colorCost[0][0];
	minCost[0][1] = colorCost[0][1];
	minCost[0][2] = colorCost[0][2];

	int minima = 987654321; //최소값
	for (int i = 0; i < 3; ++i) {//세가지 색에 대해서 찾아보기
		int temp = calc_mincost(N - 1, i);
		if (minima > temp) minima = temp;
	}

	
	//dp배열 잘 만들어졌나나 확인
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < 3; ++j)
	//		cout << minCost[i][j] << ' ';
	//	cout << '\n';
	//}
	cout << minima;
}