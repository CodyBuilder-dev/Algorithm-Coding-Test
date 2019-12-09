//���� : �� ã��
//���� : N���� ������ �� �ȿ��� X�� �����ϴ��� ã��
/*���� : ���� �翬�� ���� �ȵ� ä�� ���´�.
������ �ִ� 10^5��, N^2�� ��� 10^10���� 10�ʰ� ���� ���� �ִ�.
*/
/*
���̵�� : �׳� ������ �̺�Ž�� ���� ��.
for�� �Ѱ� ������, ������ 2�� ��ͷ� ������ �ǰڳ�
*/

/*���� Ž�� ����
1. �迭 
2. ���� ��, ������ �����κ��� mid���ؼ� ��
3. ũ�ų� ������ ���Ӱ� bs
4. ���������� ��� �ϴ°�....
������ : mid+-1 ������ϰ�, left>right����� �ϴµ�
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int* target_array;
int* find_array;
int* answer_array;

int binary_search(int left,int right,int find)
{
	if (left > right) return 0;
	
	int mid = (left+right)/2;
	if (target_array[mid] > find)
		binary_search(left, mid-1, find);
	else if (target_array[mid] < find)
		binary_search(mid+1, right, find);
	else
		return 1;
	
}

int main()
{
	scanf("%d", &N);

	target_array = new int[N];

	for (int i = 0; i < N; ++i)
		scanf("%d", &target_array[i]);

	sort(target_array, target_array + N);

	scanf("%d", &M);

	find_array = new int[M];
	answer_array = new int[M]();

	for (int i = 0; i < M; ++i)
		scanf("%d", &find_array[i]);

	
	//�Ʒ��κп� �ڵ�
	for (int i = 0; i < M; ++i)
		if(binary_search(0, N-1, find_array[i]))
			answer_array[i] = 1;
	
	for (int i = 0; i < M; ++i)
		printf("%d\n", answer_array[i]);
}