//제목 : 양념 반 후라이드 반
//목적 : 양념 X마리, 후라이드 Y마리를 살 때 가장 작은 가격으로 사는 법
//조건 : 가격은 각각 최대 5천원, 마리수는 최대 10만마리까지 가능

/*아이디어 : 완탐으로 안 풀리니까 이건 수학적으로 접근해야 함
1. 만약 양념+후라이드 > 2*반반이면 양념 후라이드 사는게 이득
2. 만약 양념+후라이드 < 2*반반이면 반반 사는게 이득
3. 반반 사고 모자라면 낱개로 사기

4. 만약 양념 >반반, 후라이드>반반이면 낱개보다도 반반 사는게 이득
*/

//느낀 점 : 동전선택 문제는 완탐이 기본이지만, 그 전에 가격을 잘 보고 수학적 접근 생각할 것
//수학에서 세 수의 관계를 모두 명확히 탐색할 것

#include <iostream>

using namespace std;

int A, B, C, X, Y;
int cost;
int main()
{
	cin >> A >> B >> C >> X >> Y;

	int set = (X > Y) ? Y : X;
	int xdiff = (X > Y) ? X - Y : 0;
	int ydiff = (X > Y) ? 0 : Y-X;

	if (A + B >= C*2) { //반반 두개가 더 쌀 경우
		if (A > 2*C && B > 2*C) { // 반반 두개가 양념보다 쌀 경우
			cost = set * 2 * C + xdiff * 2*C + ydiff * 2*C;
		}

		else if (A < 2*C) { // B>C>A
			cost = set * 2 * C + xdiff * A + ydiff * 2*C;
		}
		else if (B < 2*C) { //A>B>C
			cost = set * 2*C + xdiff * 2*C + ydiff * B;
		}
		
	}

	else {
		if (A < 2 * C) { // B>C>A
			cost = set * (A+B) + xdiff * A + ydiff * 2*C;
		}
		else if (B < 2 * C) { //A>B>C
			cost = set * (A+B) + xdiff * 2*C + ydiff * B;
		}
		else if (A < 2 * C && B < 2 * C) {
			cost = set * (A + B) + xdiff * A + ydiff * B;
		}
	}

	cout << cost;
}