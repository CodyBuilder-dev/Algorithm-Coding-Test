//���� : �� �����ϱ�
//���� : n^2. ��ǥ���ΰ� �����Ʈ,�μ�Ʈ��Ʈ�� �� �� �ƴ°�
//���̵�� : �μ�Ʈ��Ʈ ����

/*���� :�μ�Ʈ��Ʈ��, �ڷḦ �迭�� �ְ�, �迭 �ȿ��� ũ�� �� �� �迭���ֱ�
 1 3 7 �迭�� 6�� ���� ���, 7�� ���� �۰�, 3�� ���� ũ�Ƿ� 3�� 7���̿� ����
���� : �ſ� ����. �迭�� ũ�Ⱑ ���� ��쿡�� ����Ʈ���� ����
���� : �ڷᱸ���� ������ ��ƴ�.
*/
/*
���� : �� �տ��� ����
�� �� ���̶� ���ؼ� �ڱ⺸�� ũ�� swap
�ڱ⺸�� ������ ���������� �ݺ�
*/

//���� : ���������� �ε��� ��ġ�� ������ ��
#include <iostream>

using namespace std;

void insert_sort(int* numarray, int len)
{
	for (int i = 0; i < len-1; ++i) {
		for (int j = i + 1; j > 0; --j) {
			if (numarray[j] < numarray[j - 1]) swap(numarray[j], numarray[j - 1]);
		}
	}
}
int main()
{
	int N;
	cin >> N;
	
	int *numarray;
	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	insert_sort(numarray, N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';

	return 0;
}
using namespace std;