#include <iostream>

using namespace std;

int main()
{
	int a, b;

	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		//케이스 분류
		//두 수가 주어지면, 약수-배수 관계는 3가지가 전부임
		//if-else로 3가지를 모두 처리하도록 짜면 됨

		if (a%b == 0) cout << "multiple" << '\n';
		else if (b%a == 0) cout << "factor" << '\n';
		else cout << "neither" << '\n';

	}
}