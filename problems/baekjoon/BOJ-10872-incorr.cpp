//���丮���� ���� ����
//12�����̹Ƿ� 12! = 4���̹Ƿ� ������Ÿ�� �ٲ� �ʿ䵵 ����

#include <iostream>

using namespace std;

int pactorial(int num)
{
	if (num == 1) return 1;
	return num * pactorial(num - 1);
}
int main()
{
	int N;
	
	cin >> N;
	cout << pactorial(N);
}