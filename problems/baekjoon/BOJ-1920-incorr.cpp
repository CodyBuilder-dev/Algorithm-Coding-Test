//���� : �� ã��
//���� : N���� ������ �� �ȿ��� X�� �����ϴ��� ã��
/*���� : ���� �翬�� ���� �ȵ� ä�� ���´�.
������ �ִ� 10^5��, N^2�� ��� 10^10���� 10�ʰ� ���� ���� �ִ�.
*/
/*
���̵�� : ���� ���ϰ� Ǯ�� �̳� �����ɸ��ٵ� ����
������ Ž�� ���
*/
//������: �� �ð��ʰ�~

/*���̵�� 2: ������ ������, �� �ڱ� ã�� �� ã���� Ž�� �ߴ�
�Ϸ��� ������, �׷� find array���� �����ؾ� �ϹǷ� ���� �޶���
*/
//������ : �׷��� �ð��ʰ�~
#include <iostream>

using namespace std;

int N, M;
int *target_array;
int *find_array;
int *answer_array;

int main()
{
	scanf("%d", &N);

	target_array = new int[N];

	for (int i = 0; i < N; ++i)
		scanf("%d", &target_array[i]);
	
	scanf("%d", &M);

	find_array = new int[M];
	answer_array = new int[M]();

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (target_array[j] == find_array[i])
				answer_array[i] = 1;
	
	for (int i = 0; i < M; ++i)
		printf("%d\n", answer_array[i]);
}