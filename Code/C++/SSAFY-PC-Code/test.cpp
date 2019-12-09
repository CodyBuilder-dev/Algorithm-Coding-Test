#include <string>
#include <iostream>
#include <list>

using namespace std;

int main()
{
	string str = "abcdefg";
	list<int> lt;
	list<int>::iterator itr;

	itr = lt.begin();
	if (itr == lt.end()) cout << "same";
	else cout << "no";
}