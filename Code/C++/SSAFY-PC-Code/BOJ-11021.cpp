#include <iostream>

using namespace std;
int main() {
	int T;
	int A, B;

	cin >> T;
	for (int i = 1; i < T + 1; i++) {
		cin >> A >> B;
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		cout << "Case #" << i << ": " << A + B << "\n";

	}
}