//���� : ����Ʈ�� ����
/*����  :
1.�Ҽ��� ���� �����ϰ� �ִ°�
2.�Ҽ� ���� �������� ��ǻ�͸� �̿��� ������ �� �ִ���
*/
/*���̵�� : �ᱹ ��ǻ�ͷ� �Ҽ� ���ϴ� ���� ������ �����佺�׳׽� ü
�ð����⵵�� O(N*log(logN))�̶�� ��
1. �׳� 2n���� �����佺�׳׽� ü�� �� ����.
2. n���� 2n���� ���鼭 �˻��ϸ鼭 ++�Ѵ�.
*/

/*���� : �����佺�׳׽��� ü ����
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	while(1)
	{
		cin >> N;
		if (N == 0) break;

		char numArray[246912]; //2n�̹Ƿ� 123456*2�� ����
		memset(numArray, 1, sizeof(numArray));

		for (int i =2; i*i<=2*N;++i)
			if (numArray[i] == 1) {
				for (int j = i * i; j <= 2*N; j += i)
					numArray[j] = 0;
			}
		int sum = 0;
		for (int i = N + 1; i <= 2 * N; ++i)
			if (numArray[i] == 1) sum++;
		cout << sum << '\n';
	}
}