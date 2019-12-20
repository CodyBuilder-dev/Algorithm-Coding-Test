#include <iostream>
#include <string>

using namespace std;

int T;
char x, y;
string str;
string outstr;


void recur(int i)
{
	if (i == str.size()) return;

	if (str[i] > y) {
		outstr.push_back(y);
		recur(i + 1);
	}
	else if (str[i] <= y && str[i] > x) {
		if (i < str.size()) {
			if (str[i + 1] > x) outstr.push_back(y);
			else outstr.push_back(x);
			recur(i + 1);
		}

		else {
			outstr.push_back(y);
			recur(i + 1);
		}

	}
	else if (str[i] == x){ //x¶û °°À¸¸é
		if (i < str.size()) {
			if (str[i + 1] >= x) outstr.push_back(x);
			recur(i + 1);
		}
		else {
			outstr.push_back('0');
			recur(i + 1);
		}
	}
	else {
		outstr.push_back('0');
		recur(i + 1);
	}

}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> str >> x >> y;
		outstr.clear();
		recur(0);
		
		cout << '#' << i << ' ' << outstr <<'\n';
	}
}