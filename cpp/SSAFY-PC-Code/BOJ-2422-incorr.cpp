//���� : �������� ��Ż���ƿ� ���� ���̽�ũ���� ��Դµ�
//���� : N���� �� 3���� ���̽�ũ���� ����, Ư�� ������ ������ ����� ��
//���� : ���̽�ũ���� �ִ� 200����, ���� ������ �ִ� 1����

/*���̵�� : �׳� ������ ���չ���
1. ���۹·� ������ = 200C3 = 160��
2. ���� �������� ���� = ��
->�ð��� �ǳ�? �ʹ� ū��?


*/
/*���̵��2 : ������ ���ϸ� �ǹǷ�,
���������� nC3 - ���������� 2���� ���� ��� - ���������� 3���� ���� ���
->�� �𸣰���
�������� 0�� ���� ��� + �������� 1��
-> �Ǵ� ���� : 
*/

/*���̵��3 : ��! 3�� for���� ������ķ� �����غ���*/

/*������
1. deque���� ����� queue�ᵵ �������
*/
#include <iostream>
#include <set>
#include <queue>
//#include <deque>
#include <algorithm>
using namespace std;

int N, M;

bool banned[201][201];
deque<int> combi;
set<deque<int>> combiSet;
//priority_queue<int>  combi;

void make_combi(deque<int> dq)
{
	if (dq.size() == 3) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (banned[dq[i]][dq[j]] == true) return;
		
		sort(dq.begin(), dq.end());
		combiSet.insert(dq); return;
	}

	for (int i = 1; i <= N; ++i) {
		if (find(dq.begin(), dq.end(), i) != dq.end()) continue;
		//deque<int> newdq=dq; //���� �Ǵ��� Ȯ���غ�����
		deque<int> newdq(dq);
		newdq.push_back(i);
		make_combi(newdq);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		banned[x][y] = true;
		banned[y][x] = true;
	}

	make_combi(combi);
	cout << combiSet.size();
}