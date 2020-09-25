//���� : �ִ� ��
//���� : �ִ� ���� �̿��ؼ�, ���� �ڿ����� �Է¹ް�, ���� ū ������ ����ϱ�
//���� : �Է��� 0�ΰ�� ���, �� ���� ������ ��� �迭�� �ִ´�. �ڿ��� ������ 2^31���� �����Ƿ� int�� �����ϴ�.

/*
���̵�� : �������� ����� �ִµ�
1. ���� �迭�� ���� ���� �����, ���ο� ���� ���� ������ ���� �����.
2. priority que�� ���� �ſ� ���� �ȴ�.
*/
//������ : priority queue�� ���� �ð��� �ʰ��ȴ�.
//�ذ� : �켱 cin cout���� �ǵ������. printf�� �ٲٸ� ������

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	
	int N;
	scanf("%d",&N);
	
	priority_queue<int> pri_que;
	int temp;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d",&temp);
		if (temp == 0)
			if (!pri_que.empty()) {
				printf("%d\n",pri_que.top());
				pri_que.pop();
			}
			else printf("%d\n",0);
		else
			pri_que.push(temp);
	}
}