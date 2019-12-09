//제목 : 0=not cute/1 = cute
//목적 : for문을 통해 입력을 받을 수 있는가
//조건 : 설문조사 수 N은 최대 101

//느낀점 : 이런 류의 간단한 구현 문제가 대회에서 제일 앞번호로 나오는게 관례인듯
//아마 시간을 겨루는 대회 특성상, 이런 문제는 맞고 틀리고가 문제가 아니라 얼마나 빨리 푸느냐가 문제인듯
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin.tie(NULL);
	cin >> N;
	int sum = 0;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		sum+=temp;
	}
	if (sum > N / 2) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
}