//���� : ����Ʈ�� ����
//���̵�� : �Ҽ��� ������ ���ؾ� �ϹǷ� cnt�� �ؾ��ҵ�
//�Ҽ��� ��� ���ϴ���? �׳� �տ��� ��� �˰��� ���� �ȵ�?
//n<=123456�̹Ƿ� for�� 10�����̸� �Ҹ����� �ʳ�?
//������ �������� �ð��ʰ� ����. �ٸ� ����� ã�ƾ� ��
#include <iostream>

using namespace std;

int main()
{
	int* p_array;
	int N;
	int cnt;

	while (1) {
		cin >> N;
		
		if (N == 0) break;
		
		cnt = 0;
		p_array = new int[123457]();
		
		for (int i = N + 1; i <= 2 * N; i++)
		{
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					p_array[i] = 1; //�Ҽ��� �ƴϸ� 1�� ǥ��
					break;
				}

			}
		}
		p_array[1] = 1;

	
		for (int i = N + 1; i <= 2 * N; i++)
		{

			if (p_array[i] == 0) cnt++; //�Ҽ� ���� ã��

		}
		cout << cnt << '\n';
	}
}