#include <iostream>
#include <vector>
using namespace std;




int main()
{
	vector<int> set;
	for (int i = 0; i < 100; ++i)
		set.push_back(0);
	repeatedPerm(set,0,2,5);
}