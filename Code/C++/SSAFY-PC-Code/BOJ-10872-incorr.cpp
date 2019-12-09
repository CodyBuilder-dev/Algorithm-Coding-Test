//팩토리얼은 쉬움 ㅋㅋ
//12까지이므로 12! = 4억이므로 데이터타입 바꿀 필요도 없음

#include <iostream>

using namespace std;

int pactorial(int num)
{
	if (num == 1) return 1;
	return num * pactorial(num - 1);
}
int main()
{
	int N;
	
	cin >> N;
	cout << pactorial(N);
}