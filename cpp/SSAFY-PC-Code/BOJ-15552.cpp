#include <iostream>
//테케가 최대 100만개까지 들어갈 수 있음
//for 문 그냥 돌리면 시간초과 무조건 뜨게 되어있음
//endl 쓰는것만으로는 부족함

using namespace std;

int main() {
	int T;
	int A, B;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		//cin.tie(NULL);
		cout << A + B << "\n";
		ios::sync_with_stdio(false);
	}
}