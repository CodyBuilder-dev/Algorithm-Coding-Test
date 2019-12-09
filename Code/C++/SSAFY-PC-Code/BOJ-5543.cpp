//제목 : 상근날드
//목적 : 버거 + 음료 세트 중 가장 저렴한 것을 골라라
//조건 : 각 가격은 100~2000원
/*아이디어:
1. 가격을 모두 받아 저장한 후 브루트 포스
or 아니면 그냥 받을때마다 min함수를 이용해 min값 계산
2. 여기선 min함수를 이용해보자
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int burger;
	int drink;
	int burgerMin=2000, drinkMin=2000;

	for (int i = 0; i < 3; ++i)
	{
		cin >> burger;
		burgerMin = min(burger, burgerMin);
	}

	for (int i = 0; i < 2; ++i)
	{
		cin >> drink;
		drinkMin = min(drink,drinkMin);
	}
	
	cout << burgerMin + drinkMin - 50;
}