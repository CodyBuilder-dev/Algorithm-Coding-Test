//제목 : 세 수의 합
//목적 : 어떤 집합에서, 세 수를 구해서 더했을 때 그 집합 안에 있도록 하기
//조건 : 집합의 원소는 최대 1000개

/*아이디어 : 이 문제는 얼마나 효율적으로 쉽게 찾느냐에 따라 갈림
1. 2억개 원소 배열을 만든다? 메모리 초과 ㅋㅋ
2. 숫자 배열을 동적할당하고, 조합을 써서 합을 만든 후, find한다.
*/

//느낀점 : 이미 헤더파일에 포함된 키워드를 변수명으로 쓰면 안된다!
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int *numArray;
bool *choice;

int main()
{
	cin >> N;

	numArray = new int[N];
	choice = new bool[N]();

	for (int i = 0; i < N; ++i)
		cin >> numArray[i];


	for (int i = N - 1; i > N - 4; --i)
		choice[i] = true;

	//for (int i = 0; i < N; ++i)
	//	cout << select[i];


	int max = -987654321;
	do {
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (choice[i] == true) sum += numArray[i];
		
		if (sum > max && find(numArray,numArray+N,sum)!=numArray+N) max = sum;
	} while (next_permutation(choice, choice + N));
	cout << max;
}