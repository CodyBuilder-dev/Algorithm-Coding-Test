//제목 : 세 수
//목적 : 세 수 중 2번째로 큰 수 찾기
//조건 : 숫자는 최대 100

/*아이디어 : STL안쓰기
1. 1번위치랑 2번위치랑 비교해서 큰놈 뒤로
2. 2번위치랑이랑 3번위치 비교해서 큰놈 뒤로 
*/

/*느낀점 : 
1. 이문제 처음 접했을때가 STL 쓸줄도 모르던 때인데 정말 많이 배웠다.
2. STL 안쓰고 풀려면 swap 생각보다 어려움(정리 필요)
*/

#include <iostream>

using namespace std;

int numArray[3];

void swap_num(int* a, int* b)
{
	//큰놈을 뒤로 보내주는 함수
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	cin >> numArray[0] >> numArray[1] >> numArray[2];

	//크기 비교 및 순서 교체
	if (numArray[0] > numArray[1]) swap_num(&numArray[0], &numArray[1]);
	if (numArray[1] > numArray[2]) swap_num(&numArray[1], &numArray[2]);
	if (numArray[0] > numArray[1]) swap_num(&numArray[0], &numArray[1]);

	//cout << numArray[0] << numArray[1] << numArray[2];
	cout << numArray[1];
}

