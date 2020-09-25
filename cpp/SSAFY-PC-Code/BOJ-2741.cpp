#include <iostream>

using namespace std;
//for문이 10만번 = 10^5 = 시간초과인듯
//이게 프로그램을 짤 때, in이 많이 나오면 in을 최적화해주고,
//out이 많이 나오면 out을 최적화 해야 함. 즉 선택을 해야 함
int main() {
	int N;

	cin >> N;
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);
	for (int i = N; i > 0; --i)
		cout << i << '\n';

}