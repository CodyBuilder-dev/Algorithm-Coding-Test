//제목 : 지능형 기차
//목적 : 기차의 최대 탑승원 수
//분류 : 시뮬레이션(문제의 경우의수가 다 주어졌으므로)

/* 구현 : 
1. 역별 최종 사람 수를 array에 넣는다.
2. 만약 최종수가 최대인원을 초과하면 최대인원으로 바꿔준다.
3. 현재 최대값과 비교해서 교체해준다
4. 역 번호가 1부터 시작하므로 -1주의


*/

/*다른사람들 구현
1. 최대값은 그냥 다 구해서 정렬한 후 끝값 찾아도 되긴 함
2. sum = max(sum,sum+in-out)
*/
#include <iostream>
#define MAX_NUM 10000

using namespace std;

int people_num[4] = {0};

int main()
{
	int out, in;
	int max=0;
	for (int i = 0; i < 4; ++i) {
		cin >> out >> in;
		if (i == 0) people_num[i] = in;
		people_num[i] = people_num[i - 1] + in - out;
		if (people_num[i] > MAX_NUM) people_num[i] = MAX_NUM;
		if (max < people_num[i]) max = people_num[i];
	}

	cout << max;
	return 0;
}