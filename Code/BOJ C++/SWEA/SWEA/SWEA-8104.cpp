#include <iostream>

using namespace std;

int main() {
	int T;
	int N, K;
	int sum;

	int** students;

	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
	
	

		cin >> N >> K;
		//2���� �迭 �����Ҵ�
		
		students = new int* [N];
		for (int j = 0; j < N; j++)
			students[j] = new int[K];

		for (int j = 0; j < N; j++)
		{
			if (j & 1)
			{
				for (int k = K - 1; k >= 0; k--)
					students[j][k] = j * K + (K - k);
			}

			else
			{ //0, ¦���� ��
				for (int k = 0; k < K; k++)
					students[j][k] = j*K+k+1;
			}

	

		}
		
		cout << "#" << test_case << " ";

		for (int j = 0; j < K; j++)
		{
			sum = 0;
			for (int k = 0; k < N; k++)
				sum += students[k][j];
			cout << sum << " ";
		}
		cout << '\n';
			
		
		//�� N�� K�� 2�����迭
		//��� K�� N���� ��Ƶ� ������
		//�׳� �������� ���� �����ؼ� Ǯ��
		//���簡 ¦������ Ȧ������ ��Ÿ���ִ� int ����
		//N���� for�� ������ �迭 ä��������

		
	
		
	}
}