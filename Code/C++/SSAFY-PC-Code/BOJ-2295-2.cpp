//���� : �� ���� ��
//���� : � ���տ���, �� ���� ���ؼ� ������ �� �� ���� �ȿ� �ֵ��� �ϱ�
//���� : ������ ���Ҵ� �ִ� 1000��

/*���̵�� : �� ������ �󸶳� ȿ�������� ���� ã���Ŀ� ���� ����
1. 2�ﰳ ���� �迭�� �����? �޸� �ʰ� ����
2. ���� �迭�� �����Ҵ��ϰ�, ������ �Ἥ ���� ���� ��, find�Ѵ�.
*/

//������ : �̹� ������Ͽ� ���Ե� Ű���带 ���������� ���� �ȵȴ�!
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int *numArray;
bool *choice;

int main()
{
	cin >> N;

	numArray = new int[N];
	choice = new bool[N]();

	for (int i = 0; i < N; ++i)
		cin >> numArray[i];


	for (int i = N - 1; i > N - 4; --i)
		choice[i] = true;

	//for (int i = 0; i < N; ++i)
	//	cout << select[i];


	int max = -987654321;
	do {
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (choice[i] == true) sum += numArray[i];
		
		if (sum > max && find(numArray,numArray+N,sum)!=numArray+N) max = sum;
	} while (next_permutation(choice, choice + N));
	cout << max;
}