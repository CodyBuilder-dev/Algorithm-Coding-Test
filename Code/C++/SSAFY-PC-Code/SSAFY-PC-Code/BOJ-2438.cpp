//제목 : 별 찍기 - 1
//목적 : 별을 규칙에 맞춰서 출력한다
//조건 : 행은 최대 100행

#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j)
			cout << '*';
		cout << '\n';
	}
}