//제목 : 윷놀이
//목적 : 윷짝의 결과를 보고 배/등의 갯수를 판단해 도개걸윷모 결정

/*아이디어 : 너무 쉽다. 그냥 더하면 되잖아. 빽도도 없고
*/

#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	int yoot[4];
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d %d %d", &yoot[0], &yoot[1], &yoot[2], &yoot[3]);
		switch (accumulate(yoot, yoot + 4, 0))
		{
		case 0: cout << 'D' <<'\n'; break;
		case 1: cout << 'C' << '\n'; break;
		case 2: cout << 'B' << '\n'; break;
		case 3: cout << 'A' << '\n'; break;
		case 4: cout << 'E' << '\n'; break;
		}
	}
		
}