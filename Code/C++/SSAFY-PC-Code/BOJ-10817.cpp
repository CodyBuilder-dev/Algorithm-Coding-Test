//���� : �� ��
//���� : �� �� �� 2��°�� ū �� ã��
//���� : ���ڴ� �ִ� 100

/*���̵�� : STL�Ⱦ���
1. 1����ġ�� 2����ġ�� ���ؼ� ū�� �ڷ�
2. 2����ġ���̶� 3����ġ ���ؼ� ū�� �ڷ� 
*/

/*������ : 
1. �̹��� ó�� ���������� STL ���ٵ� �𸣴� ���ε� ���� ���� �����.
2. STL �Ⱦ��� Ǯ���� swap �������� �����(���� �ʿ�)
*/

#include <iostream>

using namespace std;

int numArray[3];

void swap_num(int* a, int* b)
{
	//ū���� �ڷ� �����ִ� �Լ�
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	cin >> numArray[0] >> numArray[1] >> numArray[2];

	//ũ�� �� �� ���� ��ü
	if (numArray[0] > numArray[1]) swap_num(&numArray[0], &numArray[1]);
	if (numArray[1] > numArray[2]) swap_num(&numArray[1], &numArray[2]);
	if (numArray[0] > numArray[1]) swap_num(&numArray[0], &numArray[1]);

	//cout << numArray[0] << numArray[1] << numArray[2];
	cout << numArray[1];
}

