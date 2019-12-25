/*���� : �ϳ��� ž �̵� ����
���� : �ϳ����� ž �ּ� �̵��� ������ ����Ѵ�
���� : ������ �ִ� 20��
*/

/*���̵�� : �ϳ����� ž �Ϲݷ�
1. �ϳ����� ž�� '�ڿ������� �Ųٷ�' �����ϸ� �ȴ�
2. �� �ٴ��� ��ǥ�� �̵��Ϸ���, �� �ٴ��� ������ �������� ��ǥ ���� �־�� �Ѵ�.
3. ������ ��� ĭ�� ���� ��������, N-1��°�� ��ĭ���� ���ߵǹǷ�
*/

/*����
0. ������ ���� stack���� �����Ѵ�.
stack�� equility�� ���ϱ� ����Ƿ�, �ִ� 3*20 �迭�� �ص� �ȴ�.
�迭�� index ó�� �� empty�� ����Ƿ�, deque�� �����Ѵ�

1. N��°�� ������ ����
2. N��°�� ������ �� ������, N-1��°�� ������ �ű�� �۾��� �����Ѵ�.
3. N��°�� ������ �� ������ �����δ�.
*/

/*������ :
1. stack, queue���� ���ϼ��� ���ϴ� ����� ���� �����غ���
2.
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N;
deque<deque<int>> pillar(3);

void input_block()
{
	cin >> N;

	for (int i = 1; i <=N; ++i) {
		pillar[0].push_back(i);
	}
}

int find_pillar(int size)
{
	int pillarnum;
	for (int i = 0; i < 3; ++i) {
		if (find(pillar[i].begin(), pillar[i].end(), size) != pillar[i].end()) //ã�Ƴ���
			pillarnum = i;
	}
	return pillarnum;
}
void move_block(int maxsize, int size, int end)
{
	int start = find_pillar(size);
	bool selected[3] = { 0, };
	selected[start] = true;
	selected[end] = true;
	int middle;
	for (int i = 0; i < 3; ++i) {
		if (selected[i] == false) middle = i;
	}
	
	if (size == 1) { //����� 1�� ���
		pillar[start].pop_front();
		pillar[end].push_front(size);
		cout << start + 1 << ' ' << end +1 << '\n';
		
	}
	
	move_block(size - 1, middle);


}
int main()
{
	input_block();
	move_block(N,2);

}

