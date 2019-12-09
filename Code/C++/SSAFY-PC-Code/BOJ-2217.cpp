//���� : ����
//���� : ���� �������� �־��� �� �̷κ��� ���� �� �ִ� �ִ� �߷�
/*
���� ���� : 2��, 10, 15�� ��� �ִ� �߷��� �� 20?
������ ������ ������ ���ķ� ��� �ϴµ�, �׷��� N/2<=10 �� N=20
*/

/*���̵�� : ���������δٰ� N/k <= �ּҰ� ���� ���� �� ����Ž��
*/

/*���̵�� 2 : Ž���� �ҰŸ� �ϴ� ������� �Ѹ� �̾ƺ���
*/

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}


int main()
{
	int N;
	cin >> N;
	int *rope;
	int max=0;
	int temp;

	rope = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> rope[i];
	}

	//������������ ����
	sort(rope,rope+N,desc);

	//�ִ밪����, ���� �Ѱ��� �����鼭 �ִ밪 ����
	for (int i = 0; i <N; ++i)
	{
		//�ϳ� �߰��Ǹ� �и� +1, N�� ������ �ּҰ� *�и�
		temp = rope[i] * (i + 1);
		if (max < temp) max = temp;
	}
	cout << max;
	delete[] rope;
	return 0;
}