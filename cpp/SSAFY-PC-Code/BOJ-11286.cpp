//���� : ���� ��
//���� : ���� ���ε�, ������ ���� ū ������� ����

/*
���̵��
1. �켱���� ť �״�� ����, �׳� ���� ������ ������ ����� �����Ѵ�.
->������. �������� �״�� ������ �������� ��.
->�׳� pair�� ����?
2. ���밪�� ��Ģ���� ������ ť�� �ǵ帰��.
-> ���밪 �Լ��� ���� ����.
*/


#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;
struct less_absolute {
	bool operator()(int lower,int higher) {
		return abs(lower) > abs(higher);
	}
};

int main()
{
	int N;
	priority_queue<int, vector<int>, less_absolute> pri_que;
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