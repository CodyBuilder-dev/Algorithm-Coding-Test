//���� : Polyhedra
//���� : ������ ���׽��� ������ �� �ִ°�
//���� : ���� �ִ� 100��, V,E �ִ� 100��

//���̵�� : V - E + S = 2�� ������ 1�������� ����

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