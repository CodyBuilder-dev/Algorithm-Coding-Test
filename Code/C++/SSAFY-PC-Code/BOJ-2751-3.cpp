//���� : �� �����ϱ� 2
//���� : n. ��ǥ�����δ� ���� ����, �� ������ ���� �ƴ°�
//���̵�� : quick sort�� �����ϱ�� �ʹ� ������, 
//sort �Ἥ ������ ������ �ѹ� ����
//������ : ���� § heap sort���� ��������

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int *numarray;
	cin >> N;

	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	sort(numarray,numarray+N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';
}