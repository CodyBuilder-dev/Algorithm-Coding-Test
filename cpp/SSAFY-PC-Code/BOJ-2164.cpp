//���� : ī��2
//���� : �־��� ��Ģ�� ���� ī�带 �����̰� �������� ���� ī��
//���� : ī�� 1������ ī�尡 1000��������, ī�� 2������ ī�尡 500,000��

/*���̵�� : �׳� ť ���� �˾Ƽ� �����;*/
#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> que;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		que.push(i);

	/*������ Ȯ���� ����
	cout << que.size();*/

	/* �������� �Ұ���
	for (int i = 0; i < 5; ++i)
		cout << que[i];
	*/
	while (que.size() > 1)
	{
		//cout << que.front() << ' ';
		que.pop();

		int first = que.front();
		que.pop();
		que.push(first);
	}
	cout << que.front();

}