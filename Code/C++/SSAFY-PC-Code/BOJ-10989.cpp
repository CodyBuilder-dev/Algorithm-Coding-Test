//���� : �� �����ϱ� 3
//���� : ���ڰ� ���� ��� ī���� ���� ���

/*
ī���� ������ ���� : ������ü�� ������
*/

/*
���̵�� : ����� �� �� ���� �ڷᱸ���� STL�� ���� ���.
�׷���, ���̺귯�� ��ĥ�� �޸� �ʰ� ���� �߻� ����
�Ƹ��� ���� ������ �Ǵ� ������, vector�� �����ϴ� ����������
�������� ���� �ٷ� �������
*/

/*
���̵�� 2: �׷��� �ذ� �� �Ǵ°� ����
���� 10,000,000�� ��� �����ϴ� �� ��ü�� ��������
�Է� �޾Ƽ� �ٷ� cntarray�� ����
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int temp;
	int *cntarray;
	int maxidx;

	cin >> N;

	cntarray = new int[10001]();

	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		cntarray[temp]++;
	}

	maxidx = distance(cntarray, max_element(cntarray, cntarray + 10001));
	
	for (int i = 0; i <= maxidx; ++i)
	{
		while (cntarray[i] != 0) {
			cntarray[i]--;
			cout << i << '\n';
		}
	}

	delete[] cntarray;


	return 0;
}