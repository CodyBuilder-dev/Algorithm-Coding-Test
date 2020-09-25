//제목 : 시계 사진들
//목적 : 시계바늘의 각도가 주어질 때, 두 시계가 같아질 수 있는지 여부 판단
//조건 : 각도는 최대 360,000, 바늘은 최대 200,000

/*아이디어1 : (X)
1. 시계바늘 목록을 받는다
2. 정렬한다. (최대 10^6)
3. 시계 하나를 잡아서 1부터 360,000까지 다 빼본다
4. 비교한다(10^5)
*/

/*아이디어2 :
(시계방향의 경우)
1. 시계바늘을 정렬한다
2. 시계바늘간의 각도 '차이'를 계산한다
3. 각도가 모두 같으면 오케이
(반시계방향의 경우)
1. 위와 마찬가지로 반복
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> clock1, clock2;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		clock1.push_back(temp);
	}

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		clock2.push_back(temp);
	}
	
	sort(clock1.begin(), clock1.end());
	sort(clock2.begin(), clock2.end());
	
	clock1.push_back(clock1[0] + 360000);
	clock2.push_back(clock2[0] + 360000);
	
	//여기서부터 본격적 코딩 시작
	for (int i = 0; i < n - 1; ++i)
	{
		int temp;
		temp = clock1[i + 1] - clock1[i];

	}

}