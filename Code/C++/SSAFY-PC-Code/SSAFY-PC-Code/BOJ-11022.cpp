//���� : A+B - 8
//���� : �� ���� A+B�� ���� ���ǿ� �°� ����ϴ� ��
//���� : Ư�� �������� ����ؾ� ��

//������ : Ȯ���� scanf�� cin���� ����

#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a,b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
}