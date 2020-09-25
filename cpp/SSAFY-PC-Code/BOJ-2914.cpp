//제목 : FAKTOR
//목적 : 평균식을 구현한다
//조건 : 

/*아이디어 :
1.I = round_up((sum)/A)를 구현한다.
2.여기서 sum을 구한다.
round up이므로
*/

#include <iostream>

using namespace std;

int main()
{
	int A, I;
	scanf("%d%d", &A, &I);
	
	printf("%d", (I - 1) * A + 1);

	return 0;

}