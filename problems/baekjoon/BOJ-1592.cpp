//제목 : 영식이와 친구들
//목적 : 원형테이블에 앉아 규칙에 따라 공던지기 게임을 할 때 던진 횟수

/*아이디어 : 이건 그냥 배열쓰는게 맞다
1. 각 인덱스를 사람으로 생각
2. 배열의 값을 공 받은 횟수로 생각
3. 규칙에 따라 배열 값을 올린다
*/

/*구현
1. 홀수라 공을 오른쪽으로 던질 경우 : 인덱스 L만큼 증가
i+L > N-1인 경우 차이만큼 0부터 시작
2. 짝수라 공을 왼쪽으로 던질 경우 : 인덱스 L만큼 감소
i-L < 0인 경우 차이만큼 N-1부터 시작
*/

//느낀점 : 내가 인덱스 계산을 진짜 못하는구나...  빨리 생각할 수 있도록 그려가면서 연습

#include <iostream>

using namespace std;

int N, M, L;
int *people;
int total;

void pass_ball(int ball)
{
	while (1)
	{
		for (int i = 0; i < N; ++i)
			if (people[i] == M) return;

		if (people[ball] % 2 == 0) //짝수, 왼쪽
		{
			if (ball < L) ball = N - (L - ball);
			else ball = ball - L;
			people[ball]++;
			total++;
		}
		else //홀수, 오른쪽
		{
			if (ball > N - L - 1) ball = ball + L - N;
			else ball = ball + L;
			people[ball]++;
			total++;
		}
	}
}
int main()
{
	cin >> N >> M >> L;
	people = new int[N]();
	int ball = 0;
	people[ball] += 1;
	pass_ball(ball);
	cout << total;
}