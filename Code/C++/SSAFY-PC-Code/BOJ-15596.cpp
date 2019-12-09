#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a) {
	long long ans = 0;
	for (int i = 0; i < a.size(); i++)
		ans += a[i];
	return ans;
}

int main() {
	vector<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = i;
	}
	cout << sum(a);
}