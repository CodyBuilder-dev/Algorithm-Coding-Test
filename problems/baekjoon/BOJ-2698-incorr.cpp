//���� : ������ ��Ʈ�� ����
//���� : 0�� 1�� �̷���� ��������, 1�� 2�� �پ��ִ� ������ ��Ʈ�� ������ ���϶�
//���� : ���� 1000��, ���� n�� 100����, ���� ���� k�� signed int���� ��

/*���̵�� : ������ ������ ������ ������ ������, ������ �����Ƿ� ���� ��!
(�̷��� ��� �� ���µ�..�׳� ���ŷκ��� ��Ծ����)
1. �׳� ������ ������ ���� �����Ƿ� ���� ��
2.for�� ������ �ΰ��� ���ϸ� ��
*/


//������ : next_permu�� �׳� Ǯ�� ������ �ð��ʰ���

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N, K;
int cnt;

int main()
{
	cin >> T;
	
	for (int i = 1; i <= T; ++i)
	{
		cnt = 0;
		cin >> N >> K;
		
		for (int j = K + 1; j < N; ++j)  //������ k���� �Ƿ��� �ּ� 1�� k+1��
		{
			vector<int> num;
			for (int k = 0; k < N-j; ++k) //�տ����� 0 �ֱ�
				num.push_back(0);
			for (int k = N-j; k < N; ++k) //�״��� 1�ֱ�
				num.push_back(1);
			do {
				int serial = 0;
				for (int k = 0; k < N-1; ++k)
				{
					if (num[k]*num[k+1] == 1) serial++;
				}
				if (serial == K) cnt++;
			} while (next_permutation(num.begin(),num.end()));
			
		}

		cout << cnt;

	}
}