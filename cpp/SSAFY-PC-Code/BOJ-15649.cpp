//���� : N�� M
//���� : nPm ���� ����ϱ�
/*���� : N�� M�� �ſ� �����Ƿ� �׳� �� ���ص� ��
8! = 4��, �ð������� 1���̹Ƿ� 
*/
/*
���̵�� : ������ ����ϴ� ���̹Ƿ� ���� �� �ؾ� ��
�����̶� ������ Ʈ��.
*/

/*
���̵�� 2: next_permutation�� �� Ȱ���ϸ� nPr���� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int permutation(int n, int r) //������ �ļ� ǥ��(�� �����ϰ� �տ� r�ڸ��� ���̰� �ϱ�)
{
	vector<int> vec;
	for (int i = 1; i <= n; ++i)
		vec.push_back(i);
	while (1)
	{

		for (int ii = 0; ii < r; ii++)
			printf("%d ", vec[ii]); //r���� ���
		printf("\n");

		reverse(vec.begin() + r, vec.end()); //r���̶� �����̶� ��ü

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