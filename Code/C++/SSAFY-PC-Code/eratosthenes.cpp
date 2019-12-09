#include <iostream>
using namespace std;
char prime[100];
int main() {
	int n;
	cin >> n;
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i*i <= n; ++i) {
		if (prime[i] == 1) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (prime[i] == 1)
			cout << i << '\n';
	}
	return 0;
}