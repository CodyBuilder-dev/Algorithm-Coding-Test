//제목 : 분해합
//목적 : 브루트 포스를 통한 생성자 구하기
//아이디어 : 분해합을 구하는건 쉬워도 생성자를 구하는건 어렵다
//분해합을 수식으로 풀면 머리아픈데 코딩으로는 쉬울 수 있음
//코딩으로도 그냥 모든 경우의 수 다 구하면 머리 터지는데, 범위를 좁힐 수 있음
// abc의 분해합은 abc+a+b+c임. 근데 abc는 한자리수이므로 
// abc+a+b+c < abc+10+10+10 즉 30임
// 즉 어떤 n자리수의 분해합은 아무리 커봐야 <n자리수+10*n임
// 반대로 어떤 수의 생성자는 아무리 작아봐야 분해합-10*n임

//맨 앞자리가 한자리 더 커지는 경우는 생각 잘 해봐야지만, 일단 구현 고고
//로그 취해봐야겠네 ㅋㅋ

#include <iostream>
#include <cmath>
using namespace std;
int find_decomp(int construct)
{
	if (construct < 1) return 0;
	return construct % 10 + find_decomp(construct / 10);

}
int main() {
	int N;
	int order;
	int i;
	cin >> N;
	order = log10(N) + 1;

	for (i = N - 10 * order; i < N; i++)
	{
		if ((i+find_decomp(i)) == N)
		{
			cout << i;
			break;
		}
	}
	if (i == N) cout << 0;
}