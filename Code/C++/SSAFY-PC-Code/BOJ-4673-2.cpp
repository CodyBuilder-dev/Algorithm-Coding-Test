//�׳��� ������ ���̷��� �����ϳ� ������
//�Ҽ� ã�Ⱑ �װ��ݾ� �� �������� �������� X �� �������� O
//�����ڵ� ����ѵ�. ������ ã�� ������ ������ ����
// �ٵ� �׷��ٰ� 10000���� n^3���� ������ ������ �ð��ʰ�
// for �ȿ� for�� ���� ����, for + for + for

#include <iostream>

using namespace std;
int generator(int num)
{
	if (num < 1) return 0;
	return num % 10 + generator(num / 10);
}
int main()
{
	int num = 10000;
	int array[10001] = { 0, };



	for (int i = 1; i <= num; i++)
	{
		int j = i;

		while (j <= num)
		{
			j = j + generator(j);
			if (j <= num) array[j] = 1; //�̰� �� �־��ָ� array ���� �ʰ��ؼ� error
		}
	}

	for (int i = 1; i <= num; i++)
	{
		if (array[i] == 0) cout << i << ' ';
	}





}