//���� : N�� M(2)
//���� : nPm ���� ����ϱ�
/*���� : N�� M�� �ſ� �����Ƿ� �׳� �� ���ص� ��
8! = 4��, �ð������� 1���̹Ƿ�
*/

/*
���̵�� : ����������������
next_permutation/prev_permutation�� �� Ȱ���ϸ�
nCr���� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combination(int n, int r) 
{

	//���� ���� ����
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
				printf("%d ", vec[i]); //r���� ���
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