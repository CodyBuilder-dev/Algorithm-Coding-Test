//���� : 1�� �����
//���� : 3���� ������ ������ �迭�Ͽ� �־��� ���� 1�� �����
//���� : ������ ũ��� �ִ� 10^6.�̹Ƿ� ����Ǽ� �ſ� ����

/*���̵�� : �����غ��� ������ 3������ Ʈ���� Ž������ ������ �� ����
1. � �������� ���� 1�� ���� ��� �ƴ°�? - ��������. ��Ž �ؾ���
2. 1�� �Ǿ��ٸ�, �� ��� �ּ��� ���� �����ΰ�? - �ּҰ� ���� DP�� ��ߵǳ�

��ȭ�� -> �Ұ�����
�޸������̼� -> ������
���Ҿ�����? -> ���Ҿ��̾߸��� ��ȭ���� �˾ƾ���. fail
ž�ٿ�����? -> �Լ� ������ ȣ���� �� �ּҰ��� �����ϴ� ������
*/


/*������ : 
1.DFS+DP�� ������, dp�Լ��ȿ� ������ ���� ��츦 �� �־���� �Ѵ�
2.�ٵ� ��� �ִ��Ŀ� ����, �̳� �����ų� �̳� �����ų� �Ѵ�.


*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int minCnt[1000001];

int find_min_op(int start)
{
	if (start == 1) return 0;
	if (minCnt[start] != 0) return minCnt[start]; //start =1 ����� 0�� ��� �����Ƿ� ����
	
	priority_queue<int, vector<int>, greater<int>> minima;
	if (start % 6 == 0) { //2,3������������ ���
		minima.push(find_min_op(start / 3)+1);
		minima.push(find_min_op(start / 2)+1);
		minima.push(find_min_op(start - 1)+1);

		minCnt[start] = minima.top();
		return minCnt[start];
	}

	else if (start % 2 == 0) {
		minima.push(find_min_op(start / 2)+1);
		minima.push(find_min_op(start - 1)+1);
		minCnt[start] = minima.top();
		return minCnt[start];
	}
	else if (start % 3 == 0) {
		minima.push(find_min_op(start / 3)+1);
		minima.push(find_min_op(start - 1)+1);
		minCnt[start] = minima.top();
		return minCnt[start];
	}
	else {
		minCnt[start] = find_min_op(start - 1)+1;
		return minCnt[start];
	}
}
int main()
{
	cin >> N;
	find_min_op(N);
	cout << minCnt[N];
	
	
	
	return 0;
}