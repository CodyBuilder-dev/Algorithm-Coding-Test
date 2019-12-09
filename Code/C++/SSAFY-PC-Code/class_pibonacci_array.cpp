#include <iostream>

using namespace std;

int main()
{
	long long *f;

	int N;
	
	cin >> N;

	f = new long long[N+1];
	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i < N+1; ++i)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[N];
}