//�׳��� ������ ���̷��� �����ϳ� ������
//�Ҽ� ã�Ⱑ �װ��ݾ� �� �������� �������� X �� �������� O
//�����ڵ� ����ѵ�. ������ ã�� ������ ������ ����
// �ٵ� �׷��ٰ� 10000���� n^3���� ������ ������ �ð��ʰ�
// for �ȿ� for�� ���� ����, for + for + for

#include <iostream>

using namespace std;

int main()
{
	int num = 10000;
	int array[10001] = { 0, };
	
	

	for (int i = 1; i <= num; i++)
	{
		int j = i;
		
		while (j <= num)
			{
				j = j + (j/1000) + ((j%1000) / 100) + ((j % 100) / 10) + (j % 10);
				if (j <= num) array[j] = 1;
			}
	}

	for (int i = 1; i <= num; i++)
	{
		if (array[i] == 0) cout << i << ' ';
	}


		


}