//���� : ī��1
//���� : ī�� ������ �־��� ���Ǵ�� �������� �������� ���� ī�� ã��
//���� : ī���� ����� �ִ� 1000��

/*���̵�� : ȸ���ϴ� ť ������ �����
1. ī�� ������ ������
2. ������ �� ���� ī�带 pop�ؼ� �� ������ push �ϴ°� ��
-> queue�� �̿��ϸ� �ȴ�.
*/

/*���� : 
1. queue ����
2. ���� ����ֱ�
3. 
*/
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
		cout << que.front() << ' ';
		que.pop();
			
		int first = que.front();
		que.pop();
		que.push(first);
	}
	cout << que.front();

}