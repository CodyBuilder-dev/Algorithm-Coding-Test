//���丮���� ���� ����
//12�����̹Ƿ� 12! = 4���̹Ƿ� ������Ÿ�� �ٲ� �ʿ䵵 ����
//�ٵ� �̹����� �ð��ʰ��� �� ������. cin cout ���غ��� �ȵ�
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

	scanf("%d", &N);

	printf("%d", pactorial(N));

}