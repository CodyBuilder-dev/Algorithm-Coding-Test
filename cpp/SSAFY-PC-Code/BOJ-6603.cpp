//���� : �ζ�
//���� : 1~49 �� �߿��� k���� �� ��, �ش� �� �߿��� 6�� ����
//���� : ���ڰ� 49���̹Ƿ� 2^49 = 560��... ����?!

/*���̵��: 1 2 3 4 5 6 7 �̶� 1 2 3 4 5 6 7 8�̶� �ߺ� ��û��
1. �ߺ��� �����Ϸ��� �޸������̼��� ����
2. �׳��� �����ΰ� ���� �Է¿� �� k�� S�� �־���.
3. ���� �׳� �Է´�� ���� �ϸ� ��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	int k;


	while(1)
	{
		cin >> k;
		if (k == 0) break;
		int temp;
		vector<int> S;
		vector<int> idx;
		for (int i = 0; i < k; ++i) {
			cin >> temp;
			S.push_back(temp);
		}
		for (int i = 0; i < 6; ++i)
			idx.push_back(1);
		for (int i = 6; i < k; ++i)
			idx.push_back(0);

		//���� �ؾߵǳ�? �۽�
		//���⼭���� �������� �ڵ� ����
		do
		{
			for (int i = 0; i < k; ++i)
				if (idx[i] == 1) printf("%d ", S[i]);
			printf("\n");
		} while (prev_permutation(idx.begin(), idx.end()));
		printf("\n");
	}
}