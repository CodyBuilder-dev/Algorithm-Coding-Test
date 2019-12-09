//제목 : 계단 오르기
//목적 : 계단을 올라서 얻을 수 잇는 점수의 최댓값
/*조건 : 
1. 계단은 최대 300개 -> 즉 트리로 따지면 깊이가 100이 넘어감 -> DP
2. 0은 바닥으로, 계단으로 취급하지 않는다. 즉 첫번째와 두번째는 연달아서 밟을 수 있다.
3. 마지막 계단은 반드시 밟아야 한다. 즉 N-1에서 2칸 올라가는 것은 허용하지 ㅇ낳는다.
*/

/*아이디어 : 
k번째 계단으로 오르는 최대값 : k-1에서 1칸 올라오는 최대값 , k-2에서 2칸 올라오는 최대값
중 더 큰 것 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int score[301];
int dp[301][3]; //각 칸을 행으로, 전의 칸으로부터 1칸 올라오는건 1열에, 두칸 전으로부터 2칸 올라오는건 2열에

int find_max(int dest, int series)
{
	if (series == 2) return 0; //3번 연속인 경우 ㅂㄱㄴ
	if (dest <= 0) return 0;
	
	int nowScore = score[dest];
	int finalScore;
	if (series == 1) { //이미 한칸 뛴 경우
		//그 전에는 2칸 뛰어야 함
		if (dp[dest - 2][0] != 0 && dp[dest - 2][1] != 0) finalScore = dp[dest - 2][0] + dp[dest - 2][1]+nowScore;
		else finalScore = find_max(dest - 2, series - 1)+nowScore;
	}
	else { //2칸 뛰어서 올라온 경우
		//그 전은 2칸 뛰든 1칸 뛰든 상관없음
		finalScore = max(find_max(dest - 1, series+1)+nowScore, find_max(dest - 2, series)+nowScore);
	}

	dp[dest][series] = finalScore;
	return  finalScore;
}

int main()
{
	//입력 받기
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> score[i];
	
	//dp초기화
	dp[1][1] = score[1]; //0번째 계단
	dp[1][2] = score[1];
	dp[2][1] = dp[1][1] + score[2];
	dp[2][2] = score[2];


}