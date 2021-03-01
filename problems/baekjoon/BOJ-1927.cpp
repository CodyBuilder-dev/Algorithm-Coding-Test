//���� :�ּ� ��
//���� : �ڿ��� �Է��� �޾Ƽ�, �迭���� �ּ� ������� ���� ����ϴ� �ּ� ���� �����Ѵ�.
/*
���̵�� :
1. �迭�̳� ��ũ�� ����Ʈ �����, �ּ� ���� ���� �����Ѵ�.
2. stl�� priority que�� �̿��ϵ�, ������ �Ųٷ� �ٲ۴�
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	priority_queue<int,vector<int>,greater<int>> pri_que;
	int temp;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &temp);
		if (temp == 0) {
			if (!pri_que.empty()) {
				printf("%d\n", pri_que.top());
				pri_que.pop();
			}
			else printf("%d\n", 0);
		}
		else pri_que.push(temp);
	}
}