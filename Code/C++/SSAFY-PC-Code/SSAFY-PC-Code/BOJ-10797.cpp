//���� : 10����
//���� : �迭���� ã���� �ϴ� ������ ���� ����

/*���̵�� : �ƹ����� Ž��(search) ������ �Թ��� �����ε�
5�����̹Ƿ� �ܼ� O(N)¥�� ����Ž������ ����
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int numArray[5];

	scanf("%d", &N);

	scanf("%d %d %d %d %d",
		&numArray[0], &numArray[1], &numArray[2], &numArray[3], &numArray[4]);
	
	int sum=0;
	for (int i = 0; i < 5; ++i)
		if (numArray[i] == N) sum++;

	printf("%d", sum);
}