#include <iostream>

using namespace std;
//배열로 만들어 볼 것
int main() {
	int T;
	int A, B;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << endl;
	}
}