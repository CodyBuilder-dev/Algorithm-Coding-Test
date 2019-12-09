//제목 : 분수찾기
//목적 : 2차원 배열 활용 + 인덱스 자유자재 활용?
//아이디어 : 분수 생성 자체는 2차원배열로 하면 쉬움
//n번째 층의 수들은 분자+분모합이 n+1이다.
//n층까지의 개수 총합은 n(n+1)/2
//그.. 지그재그 순서 정하기는 n층이 홀수냐 짝수냐 하면 될듯


//x가 n번째 층에 속하는지를 알아내야 될 거 같은데
//그럼 그 이후로는 n번째 층의 몇번쨰인지 파악하면 쉬움
//그럼 사실상 2차원배열을 만들 필요도 없네
//배열을 4473개만 만들면 됨
//4472개 만들면 에러? 몰겠네
#include <iostream>

using namespace std;

int main()
{
	int X;
	int X_order,X_num, X_denom;
	//int nth_layer_total[4473]; 배열로 안 해도 될 듯
	cin >> X;
	int i;
	for (i = 1; i <= 4472; ++i)
		if (X <= i * (i + 1) / 2) break;
	//i = 4473인 경우 조사 필요

	X_order = X - i * (i - 1) / 2;
	//즉 x는 i층의 X_order번
	if (!(i % 2))
	{
	X_num = X_order;
	X_denom = i +1 - X_order;
	}
	else
	{
		X_denom = X_order;
		X_num = i + 1 - X_order;
	}

	cout << X_num << '/' << X_denom;

}

