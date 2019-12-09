///���� : ���� �� �����ϴ� �κ� ����
//���� : ������ �־��� ���, �����ϴ� ������ ���� �� ���� �� ���� ���Ͽ���
//���� : ������ ���̴� �ִ� 1000

/*���̵�� :
1.�׳� ���� N���� 1���� �� ã�ƺ��� = O(N^2) �ذᰡ��
*/

/*���� : 3�� for������ �ذᰡ��*/

/*
������ : �κм����̶�, ���� �ָ� ������ �־ �κ� �����̶�� �� �� ����
->�ܼ� for�����θ� Ǯ ��� ������ ���� ã�Ⱑ �ſ� �������
*/

#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> numArray;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		numArray.push_back(temp);
	}
	
	int maxLength = 0;
	bool isDeclined = false;

	for (int i = N; i >0; --i) //���� N¥�� �������� �˻�
	{
		for (int j = 0; j < N - i + 1; ++j) //0�������� N-i�������� 
		{
			for (int k = j; k < j+i-1; ++k) {
				if (numArray[k] < numArray[k + 1]) break;
				if (k == j+i-2) isDeclined = true;
			}
			if (isDeclined) break;
		}

		if (isDeclined) {
			maxLength = i;
			break;
		}
	}

	cout << maxLength;
}