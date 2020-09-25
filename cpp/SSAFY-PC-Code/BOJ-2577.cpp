//제목 : 숫자의 개수
//목적 : 
//조건 : A는 최대 10^3, 즉ABC는 최대 10^9이므로... int 써도됨

/*아이디어 : 아이디어자체는 쉬운데, 좀 다르게 풀어보고 싶음
1. 배열을 정적할당 했을 때, 어디까지 읽을 것인가 결정하는 법
2. -1로 초기화해놓고, -1에 도달하면 그만두는 방법?!
*/
#include <iostream>

using namespace std;

int numArray[10];
int decimalArray[10];

void devide_decimal(int num)
{
	int first;
	int decimal = 0;
	while (num != 0) {
		first = num % 10;
		num = num / 10;
		numArray[decimal] = first;
		decimal++;
	}
}

void check_decimal()
{
	int i = 0;
	while (numArray[i] != -1)
	{
		decimalArray[numArray[i]]++;
		++i;
	}
}
int main()
{
	int A, B, C;

	cin >> A >> B >> C;
	
	//-1로 초기화
	for (int i = 0; i < 10; ++i)
		numArray[i] = -1;

	int result = A * B * C;
	devide_decimal(result);
	check_decimal();
	for (int i = 0; i < 10; ++i)
		cout << decimalArray[i] << '\n';
}