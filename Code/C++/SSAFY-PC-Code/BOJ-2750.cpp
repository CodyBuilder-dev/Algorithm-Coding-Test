//���� : �� �����ϱ�
//���� : n^2. ��ǥ���ΰ� �����Ʈ,�μ�Ʈ��Ʈ�� �� �� �ƴ°�
//���̵�� : �����Ʈ ����. �ڷᱸ���� �׳� �迭
//������ : �����Ʈ�� �ε��� ��ġ ��Ȯ�� �ľ�.
//�����͸� �Լ��� �ְ� �����͸� �����Ѵٸ� �׶� ��� �Ǵ��� Ȯ��

#include <iostream>

using namespace std;
//�����Լ��� ������ �ؾߵǳ�

//�����Ʈ ����. �Լ��� �ϸ� ����ϰŵ�
//�����͸� �����ϱ� ����, �׳� void�� �ϴ°� ����

void bubble_sort(int *numarray,int len)
{
	int temp = numarray[0];
	//for 2������ ������ ��
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len -1-i; ++j) {
			if (numarray[j] > numarray[j + 1])
			{
				temp = numarray[j];
				numarray[j] = numarray[j + 1];
				numarray[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int N;
	int *numarray;
	cin >> N;

	numarray = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> numarray[i];

	bubble_sort(numarray,N);

	for (int i = 0; i < N; ++i)
		cout << numarray[i] << '\n';
	
}