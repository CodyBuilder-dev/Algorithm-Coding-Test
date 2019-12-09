//제목 : N과 M
//목적 : nPm 순열 출력하기
/*조건 : N과 M이 매우 작으므로 그냥 막 구해도 됨
8! = 4만, 시간제한은 1초이므로 
*/
/*
아이디어 : 순열을 출력하는 것이므로 생각 잘 해야 됨
순열이란 일종의 트리.
*/

/*
아이디어 2: next_permutation을 잘 활용하면 nPr구현 가능
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int permutation(int n, int r) //일종의 꼼수 표현(다 정렬하고 앞에 r자리만 보이게 하기)
{
	vector<int> vec;
	for (int i = 1; i <= n; ++i)
		vec.push_back(i);
	while (1)
	{

		for (int ii = 0; ii < r; ii++)
			printf("%d ", vec[ii]); //r개만 출력
		printf("\n");

		reverse(vec.begin() + r, vec.end()); //r번이랑 끝번이랑 교체

		if (!next_permutation(vec.begin(), vec.end()))
			break;
	}

	return 1;
}



	


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	permutation(N, M);
}