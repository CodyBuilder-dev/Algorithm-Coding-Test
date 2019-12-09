//제목 : 타일 채우기
//목적 : 3*N크기의 벽을 2*1, 1*2 크기 타일로 채워라
//조건 : 열은 최대 30개, 즉 3*30까지 가능

/*아이디어 : 3*N배열을 이용한 완전 탐색?
1. 3*N배열을 만들고 0으로 채움
2. 블록을 놓는 경우의 수 (가로, 세로)로 채움
3. DFS : 끝까지 다 채워지면 +1 추가
BFS : 반복
4. 반복
*/

/*아이디어2 : DP를 이용한 점화식 or 메모이제이션
점화식 ->
N이 홀수일 때 : 채울 수 없음
N이 짝수일 때 : 2일때의 패턴은 3가지, 4일때의 패턴은 11가지

f(N) = f(N-2)*3가지 + f(N-4)*11가지- (중복되는 부분)
f(N-2) 는 근데 f(N-4)*3이니까,
f(N-2) = f(N-4) +3가지이므로. 여기서부터 파생되는 애들은 없애줘야 함

바텀업 방식 -> 아래에서부터 채워 나감
탑다운 -> 어케해야 하나
*/

#include <iostream>

using namespace std;

int N;
int caseCnt[31];

int main()
{
	cin >> N;

	caseCnt[2] = 3;
	caseCnt[4] = 11;
	caseCnt[6] = 41;
	
	//항상 새로운 블록이 존재함
	for (int i = 8; i <= N; ++i) {
		if (i & 1) //홀수일 때
			continue;
		for (int j = 2; j <= i; j += 2)
			if (j == 2) caseCnt[i] += caseCnt[i - j] * 3;
			else if(j == i) caseCnt[i] += 2;
			else caseCnt[i] += caseCnt[i - j] * 2;
			
			
	}
	
	/*for (int i = 1; i <= N; ++i) {
		cout << caseCnt[i] << ' ';
		if (i % 10 == 0) cout << '\n';
	}*/
	cout << caseCnt[N];
}