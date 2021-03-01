//제목 : 트럭 주차
//목적 : 트럭 대수, 주차 시간, 시간당 주차비가 주어질 때 주차비 계산
//조건 :각 트럭이 머무는 시간이 따로 주어짐

/*아이디어 : 시간별로 겹치는 여부를 파악해야 함
1. 시간은 1~100분이므로, for문 돌려서 분별 주차대수를 파악한다.
2. 주차대수가 파악되면, 분*대수*대당 가격 최후에 계산한다.
*/

//느낀점 : 주차시간이라 함은 시작시간 후 1시간부터 계산됨에 주의
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	int in[3], out[3];

	scanf("%d %d %d", &A, &B, &C);
	for (int i = 0; i < 3; ++i)
		scanf("%d %d", &in[i], &out[i]);
	
	/*for (int i = 0; i < 3; ++i)
		printf("%d %d\n", in[i], out[i]);
	*/
	int maxtime;
	maxtime = max(out[0], out[1]);
	maxtime = max(maxtime, out[2]);

	int time[4] = { 0 };

	for (int i = 0; i <= maxtime; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 3; ++j)
			if (in[j] < i && i <= out[j]) cnt++;
			
		time[cnt]++;
	}
	cout << A * time[1] + B * time[2]*2 + C * time[3]*3;
}