//제목 : 방학 숙제
//목적 : 하루에 숙제하는 양이 정해져 있을 경우, 놀수 있는 날의 수
//(연산에서 나머지가 생기는 경우 잘 처리할 수 있는가?)

/*아이디어 : 국어는 A/C일 필요. 수학은 B/D일 필요
수학은 다했는데 국어가 남는 경우 등이 있으므로, 최대일자 계산
숙제가 1페이지라도 남아있으면 그 다음날부터 고고
*/

#include <iostream>

using namespace std;

int main()
{
	int L;
	int A, B, C, D;

	cin >> L >> A >> B >> C >> D;

	int koreanDay;
	if (A%C == 0) koreanDay = A / C;
	else koreanDay = A / C + 1;

	int mathDay;
	if (B%D == 0) mathDay = B / D;
	else mathDay = B/ D + 1;

	int totalDay = (koreanDay > mathDay) ? L - koreanDay : L - mathDay;

	cout << totalDay;
}