//���� : �׷��� ������ ������ �Ǿ��...
//���� : �޸𸮿� �����͸� ������ ��, ������ ����� wear level�� �ּҰ� �ǰ� �϶�
/*���� : 
0. ���̺귯�� ��� ���� Ǯ���
����� ���� ������� �ؾߵ�!
*/

/*���̵�� : ���� ���Ʈ ����
��� 1 ��ġ
�� �������� ��� 2 ��ġ
�� �������� ��� 3 ��ġ
...
��� N ��ġ

��� ���
��� ����
�ݺ�
��� ��
*/

/*��� ��ġ ���� : ���Ʈ ����
0������ �׳� ��ġ ���
�ѵΰ��� N�� for������ �ϴµ�, �ȵǴϱ� ��ͷ�

*/
/*���̵�� : �׸����ϰ� �ּҰ� ��ó����?
1. �Է� �ޱ�

2.1 ��� ���� �ִ밪 Ȯ��
2.2 �ּ� wear level Ȯ��
2.3 �ּ� wear level ��ó���� Ž������
2.4 �ּ� wear level ��ó���� window moving���� Ž��
2.5
*/


#include <iostream>

using namespace std;

int T;
int N, K;
int memory[200000];
int block[200000];
int minWear = -987654321;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> memory[i];

	for (int i = 0; i < K; ++i)
		cin >> block[i];
}

void put_memory_recur(int startIdx, int order, int nowMin) { //������ġ�� ���̸� ������ ��� ������
	//��� �� ���� ���ư�
	if (order >= K || startIdx + block[order] >= N) {
		if (minWear <= nowMin) minWear = nowMin;
		return;
	}

	for (int i = startIdx; i < startIdx + block[order]; ++i)
		if (memory[i] > nowMin) nowMin = memory[i];

	for (int i = startIdx + block[order]; i < N; ++i)
		put_memory_recur(i, order + 1, nowMin);

}

int main() {
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		minWear = -987654321;
		input();
		for (int j = 0; j < N; ++j)
			put_memory_recur(j, 0, minWear);
		cout << '#'<< i << ' ' << minWear << '\n';
	}
}
