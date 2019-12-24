#include <iostream>

using namespace std;

int main() {
	int a, b, c ;

	cin >> a;
	cin >> b >> c;
	
	for (int i = 0; i < b; i++) {
		if (i == 1) {
			for (int j = 0; j < a; j++)
				cout << j;
		}
		else {
			for (int j = 0; j < c; j++)
				cout << 0;
			
		}
		cout << endl;
	}
}