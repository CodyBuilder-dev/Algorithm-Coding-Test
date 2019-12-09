//���� : �Ǻ���ġ ��
//���� : ���� Ǯ������� ��Ȯ���� ����
//n�� ������ 45���� ����. �ð������� 1��

//���̵�� : �׳� ��ͷ� Ǭ��
/*������ 
n�� �Ұ� 45�ۿ� ���� ��������, ������ ���� �ð��� �ɸ�
�ð����⵵�� Ʈ���� ���󰡹�,�� 2^n��
fibonacci(45)�� ������� 1,134,903,170
���� �����ϸ� �ݵ�� �ð��ʰ�
*/

/*�ذ�
��͸� �ҰŸ� �ߺ� call�� �����̹Ƿ�, �޸������̼� ���� �ذ�
�������� ����Ʈ�� �Ǻ���ġ ���� �־����, ȣ���Ҷ� ����
*/
#include <iostream>

using namespace std;

//���� �Ǻ���ġ array
int fiboarray[45] = { 0 };

int fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		if (fiboarray[n] != 0) return fiboarray[n];
		else
		{
			fiboarray[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return fiboarray[n];
		}
	}
}
int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n);
}