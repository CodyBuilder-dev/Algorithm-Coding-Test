/*���� : �ѱ����� ���� ����
���� : ������ �־����� ���, ������ �������� ��ġ�� ����϶�
���� : ����, ��ũ�� 300,000 �������� �ִ� 10^9
*/

/*���̵�� :
���Ʈ ���� = 300,000^2 = ������ ����
�̺� Ž�� = ����
*/

/*���̵�� 2 : �Ųٷ� �����ϱ� -> ���� ũ�� k¥���� ������, ������ �� �� ������? �� �̸� ����

�߰����� ��ġ�� ����, ó������ �߰����� �� Ž���ؼ� ���� ���� ���� ã��
-> ���ۺ��� ū���� �� ��, ���ۺ��� �������� �� ��,���� �߰�, 

ó���� ���� �߰������� ū��, �߰������� ��������� �ɷ���


*/

/*���̵�� 3 : ����, ���� pair�� dequeue�� �ְ� ������
1. �ڱ⺸�� 1�ܰ� ��������  depth�� ã�´�
2. �� depth �տ� �ִ� �� �� ���� ������ ã�´�
3. 
*/

/*���̵�� 4 : ������ �ôٰ� �����ϰ�, �迭�� �� �ھ��������
1. 68312 �̵����̸�, 66311 �̷�������
*/
#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int T;
int N, Q;
int r[300000];
int q[300000];
int blocked[300000];

//deque<pair<int, int>> width_first;
//deque<pair<int, int>> depth_first;


void input(int N, int Q) {
	for (int i = 0; i < N; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < Q; ++i) {
		cin >> q[i];
	}
}

//�������� ����
void desc() {
	int min = r[0];
	for (int i = 0; i < N; ++i) {
		if (r[i] > min) r[i] = min;
		else min = r[i];
	}
}

//����Ž�� ����
int binarySearch(int q) {
	int left, right, mid;
	left = 0; right = sizeof(r); mid = (left + right) / 2;

	while (left < right) {
		if (q > mid) right = mid;
		else left = mid;

	}
	return mid;
}

void solution() {
	//binary search�� ��� ������ ������, ���������� ������ ��ġ�� ã��
	//0 �̸��� ���  0, �ƴϸ� ������ ��ũ ��ġ ���
}
int main() {
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N >> Q;
		input(N, Q);

		//����Ž�� start
		for (int j = 0; j < Q; ++j) {
			q[j] 
		}
	}
	return 0;
}