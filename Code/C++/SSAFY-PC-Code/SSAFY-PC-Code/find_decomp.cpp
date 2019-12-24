//분해합 찾는 함수
#include <iostream>
#include <cmath>
using namespace std;
int find_decomp(int construct)
{
	if (construct < 1) return 0;
	return construct % 10 + find_decomp(construct / 10);

}
int main()
{
	int N = 123;
	cout << find_decomp(123);
	return 0;

}