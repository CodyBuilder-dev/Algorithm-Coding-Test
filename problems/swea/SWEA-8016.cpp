#include <iostream>

using namespace std;

int main()
{
	int T;
	long N;
	long left, right;

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		left = 2 * N*N - 4 * N + 3;
		right = 2 * N*N - 1;
		cout << "#" << i << " " << left << " " << right << '\n';
	}
}