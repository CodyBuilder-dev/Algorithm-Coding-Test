//제목 : 영수증
//목적 : 뺄셈을 할줄 아는가ㅋㅋㅋㅋ

/*구현 : 그냥 하면 너무 쉬우니, 제한조건을 걸어보자
1. cin.tie(NULL) 쓰기
2. std 안 쓰기
3.선택과제)메모리 직접 접근
*/
#include <iostream>

int main()
{
	std::cin.tie(NULL);
	
	int total;
	std::cin >> total;
	int temp;
	for (int i = 0; i < 9; ++i) {
		std::cin >> temp;
		total -= temp;
	}
	std::cout << total;
}