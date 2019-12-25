#include <iostream>
#include <utility>

using namespace std;

int main()
{
	pair<int, int> pair1, pair2;

	pair1.first = 1;
	pair1.second = 2;

	pair2.first = 1;
	pair2.second = 2;

	cout << pair1 + pair2;
}