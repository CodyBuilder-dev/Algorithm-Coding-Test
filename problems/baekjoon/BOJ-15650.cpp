//제목 : N과 M(2)
//목적 : nPm 조합 출력하기
/*조건 : N과 M이 매우 작으므로 그냥 막 구해도 됨
8! = 4만, 시간제한은 1초이므로
*/

/*
아이디어 : 순열과마찬가지로
next_permutation/prev_permutation을 잘 활용하면
nCr구현 가능
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combination(int n, int r) 
{

	//원래 벡터 생성
	vector<int> vec;
	for (int i = 1; i <= n; ++i)
		vec.push_back(i);
	vector<int> idx;
	for (int i = 1; i <= r; ++i)
		idx.push_back(1);

	for (int i = 1; i <= n - r; ++i)
		idx.push_back(0);
	
	
	do
	{

		for (int i = 0; i < n; i++)
			if(idx[i] == 1)
				printf("%d ", vec[i]); //r개만 출력
		printf("\n");

			
	} while (prev_permutation(idx.begin(), idx.end()));

	return 1;
}






int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	combination(N, M);
}