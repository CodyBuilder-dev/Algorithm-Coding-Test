//���� : ��
//���� : �ŵ��� �̸����� ������ ��, ���������� ���� �� ���� ��ġ�� ���϶�
//���� : ���� ��ġ�� �����Ǿ� �����Ƿ�, �׳� �Ÿ� �ٲٸ� ��

/*���̵�� : �ŵ��� ������ 1�Ĺ迭�̰� ���� ��ġ�� 1���̹Ƿ�,
�迭 ���ҵ� swap���� �ڸ��ٲٱ⸸ �ϸ� ��
*/

/*����
1. �迭�� �� ��ȣ �ֱ�
2. �Է� �޾Ƽ� �� ��ȣ�� �ִ� �迭 idxã��
3. �ش� idx��ġ���� swap
*/

#include <iostream>

using namespace std;

int main()
{
	int cups[50];
	int M;
	cin >> M;

	for (int i = 1; i <= 50; ++i)
		cups[i - 1] = i;
	int a, b;
	for (int i = 0; i < M; ++i){
		cin >> a >> b;
		int idxA,idxB;
		for (int j = 0; j < 50; ++j){
			if (cups[j] == a)
				idxA = j;
			if (cups[j] == b)
				idxB = j;
		}
		swap(cups[idxA], cups[idxB]);
	}
	cout << cups[0];

}