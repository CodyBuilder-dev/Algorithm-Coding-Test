//���� : �Ǻ���ġ �Լ�
//���� : �Ǻ���ġ�� ��ͷ� �� �� ȣ��Ƚ���� ���Ѵ�.
//���̵�� : ��ͷ� �׳� �����ϰ�, ȣ��ɶ����� cnt++�� ���ִ� ������ �߰��Ѵ�.
//������ : �׳� ��ͷ� �����ϸ� �ð� �ʰ��ǰ� �Ǿ���������������������
//���̵��2 : �����Ҵ� �����ϰ�, 0,1 Ƚ���� �����Ҵ� �ϴ°��� ����
//0,1�� Ƚ���� �����ϴ� �ڷᱸ���� pair
#include <iostream>
#include <utility>
using namespace std;

//n��° �Ǻ���ġ ���� 0,1 ȣ�� ������ �����ϴ� �迭
pair<int, int> cnt[40];


pair<int,int> fibonacci(int n) {
	if (n == 0) {
		cnt[0].first = 1;
		cnt[0].second = 0;
		return cnt[0];
	}
	else if (n == 1) {
		cnt[1].first = 0;
		cnt[1].second = 1;
		return cnt[1];
	}
	else {
		if (cnt[n].first != 0 && cnt[n].second != 0) {
			return cnt[n];
		}
		else
		{
			cnt[n] = fibonacci[n - 1] + fibonacci[n - 2];
			return cnt[n];
		}
		
	}
}

int main()
{
	int T;
	int N;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> N;
		fibonacci(N);
		cout << cnt[N].first << ' ' << cnt[N].second << '\n';
	}

	return 0;
}