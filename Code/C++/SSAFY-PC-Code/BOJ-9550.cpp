//���� : Kids Love Candies
//���� : ������ų �� �ִ� �ִ��� ���� ���ڸ� ����ϴ� ��
//���� : T �ִ� 100, 

/*���̵�� : �� ĵ�� ���� ���� ���ؼ� ���Ѵ�.
*/

#include <iostream>

using namespace std;

int T;
int N, K;
int kids;
int sum;

int main()
{
	scanf("%d", &T);
	
	for (int i = 1; i <= T; ++i)
	{
		int sum = 0;
		scanf("%d%d", &N, &K);
		int temp;
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &temp);
			sum += temp / K;
		}

		printf("%d\n", sum);
	}
	return 0;
}




