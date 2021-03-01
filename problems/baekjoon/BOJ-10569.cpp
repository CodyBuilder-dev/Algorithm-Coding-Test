//제목 : Polyhedra
//목적 : 간단한 다항식을 구현할 수 있는가
//조건 : 테케 최대 100개, V,E 최대 100개

//아이디어 : V - E + S = 2의 간단한 1차방정식 구현

#include <iostream>

using namespace std;

int main()
{
	int T;
	int V, E;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i)
	{
		scanf("%d", &V);
		scanf("%d", &E);

		int S = 2 - V + E;

		printf("%d\n", S);

	}
	return 0;
}