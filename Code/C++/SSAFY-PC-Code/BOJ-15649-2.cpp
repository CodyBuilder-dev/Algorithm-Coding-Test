//제목 : N과 M
//목적 : nPm 순열 출력하기
//조건 : N과 M이 매우 작으므로 그냥 막 구해도 됨
//8! = 4만
/*
아이디어 : 순열을 출력하는 것이므로 생각 잘 해야 됨
순열이란 일종의 트리. ㅛ
*/

#include <iostream>

using namespace std;

void print_permutation(int n, int m)
{
	if (m == 1) {
		printf("%d ", n); return;
	}
	print_permutation(n, m - 1);
	print_permutation(n - 1, m - 1);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	print_permutation(N, M);

}