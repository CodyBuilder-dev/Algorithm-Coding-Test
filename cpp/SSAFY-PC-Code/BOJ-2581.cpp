#include <iostream>

using namespace std;

//1. M~N������ �Ҽ��� �� �˾ƾ� ��
//2. ��, M�������� �����ؼ� 2~M������ ��θ� �������� ��
//3. �׷��� ����ִ� ���� �Ҽ��� �Ӹ��Ѵ�.

//�ڷᱸ�� : ����ȭ��Ű���� �������⿡ ���� �� ��� �Ѵ�.

int main()
{
	int* p_array;

	int M, N;


	cin >> M >> N;
	//M<N�� ���缭 �ðŶ�� ����	

	p_array = new int[10001]();

	
	for (int i = M; i <= N; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				p_array[i] = 1; //
				break;
			}

		}
	}
	p_array[1] = 1;


	int sum = 0;
	int cnt = 0;
	int first;
	for (int i = M; i <= N; i++)
	{
		
		if (p_array[i] == 0)
		{
			if (cnt == 0) first = i;
			sum += i;
			cnt++; //�ణ ������� ù��° �Ҽ� ã��
		}
		

	}
	if (cnt != 0) cout << sum <<'\n'<<first;
	else cout << -1 << '\n';
}