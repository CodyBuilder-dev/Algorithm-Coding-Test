//���� : ������ ����
//���� : ������ �ִ� ž�¿� ��
//�з� : �ùķ��̼�(������ ����Ǽ��� �� �־������Ƿ�)

/* ���� : 
1. ���� ���� ��� ���� array�� �ִ´�.
2. ���� �������� �ִ��ο��� �ʰ��ϸ� �ִ��ο����� �ٲ��ش�.
3. ���� �ִ밪�� ���ؼ� ��ü���ش�
4. �� ��ȣ�� 1���� �����ϹǷ� -1����


*/

/*�ٸ������ ����
1. �ִ밪�� �׳� �� ���ؼ� ������ �� ���� ã�Ƶ� �Ǳ� ��
2. sum = max(sum,sum+in-out)
*/
#include <iostream>
#define MAX_NUM 10000

using namespace std;

int people_num[4] = {0};

int main()
{
	int out, in;
	int max=0;
	for (int i = 0; i < 4; ++i) {
		cin >> out >> in;
		if (i == 0) people_num[i] = in;
		people_num[i] = people_num[i - 1] + in - out;
		if (people_num[i] > MAX_NUM) people_num[i] = MAX_NUM;
		if (max < people_num[i]) max = people_num[i];
	}

	cout << max;
	return 0;
}