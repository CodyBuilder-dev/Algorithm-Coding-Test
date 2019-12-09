//제목 : 세수정렬
//목적 : ?
//아이디어 : 그냥 sort

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[0] << ' ' << a[1] << ' ' << a[2];
}