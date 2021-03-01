//제목 : 터렛
//목적 : 터렛1과 터렛2로부터 마린의 거리가 주어졌을 때 마린이 존재가능한 위치의 개수
//조건 : 좌표 범위는 최대 -1만~1만

/*아이디어 : 두 원의 위치관계를 알고리즘을 이용해 보이는 것
1. 정수의 좌표계에서 실수를 어떻게 나타낼 것인가
2. 무한개의 점들을 유한개의 컴퓨터에 어떻게 넣을 것인가
3. 나타낸 후에, 위치관계 판단은 어떻게 할 것인가
...
해결책 : 거꾸로 계산하기!
1. 마린의 좌표를 정하고, 거기서부터 거리를 계산한다 
2. 거리에 따라 케이스 분류해서 출력
중점간 거리가 
*/

/*느낀점 : 
1.float과 double의 차이 확실히
2.실수-실수간 비교, 실수-정수 비교 확실히
3.sqrt도 오차가 생긴다고 함.
->결론, 실수는 logical한 프로그램에선 진짜 왠만하면 쓰지 말자
->근데, realistical한 센서에서는 실수를 써야되네? ㅁㅊ ㅋㅋ
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef struct point {
	int y;
	int x;
}POINT;

int T;
POINT t1, t2;
POINT marine;
int R1, R2;
double D;
double mindelta = 10e-7;

float calc_dist(POINT p1, POINT p2)
{
	int yDiff, xDiff;
	yDiff = p1.y - p2.y;
	xDiff = p1.x - p2.x;
	double D;
	D = (yDiff * yDiff + xDiff * xDiff);

	return D;
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> t1.x >> t1.y >> R1 >> t2.x >> t2.y >> R2;
		D = calc_dist(t1, t2);

		//우선 중점이 같은 케이스부터 처리
		if (t1.x == t2.x && t1.y == t2.y) {
			if (R1 == R2) cout << -1;
			else cout << 0;
		}
		else { //중점이 다른 케이스
			if (D - pow(R1 + R2,2) > mindelta ) cout << 0;
			else if (D - pow(R1+R2,2) < mindelta) cout << 1;
			else if (pow(R1+R2,2) -D > mindelta && D - pow(R1-R2,2) > mindelta) cout << 2;
			else if (D - pow(R1-R2,2) < mindelta) cout << 1;
			else cout << 0;
		}

	}	

	return 0;
}