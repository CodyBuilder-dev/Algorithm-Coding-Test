//���� : ������
/*���� : ��� ��ȭ�� ����, ������ �����̸� ���� �� ���� ���ϱ�
(��, 2���� �迭�� ��ǥ�� ����, for������ ����Ž�� �� �� �ִ°�?)
*/

//���� : y��ǥ�� ������ �ݴ��̹Ƿ� �����ؾ� ��

#include <iostream>

using namespace std;

int main()
{
	int white[100][100] = { 0 }; //�̷������� �����Ҵ��ϸ� �޸� ���?
	int N;
	cin >> N;
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		// 0 1 2 3
		for (int j = 90-y; j < 100 - y; ++j)
			for (int k = x; k < 10 + x; ++k)
				white[j][k] = 1;
	}
	
	int sum = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			if (white[i][j] == 1) sum++;
	cout << sum;
	
}