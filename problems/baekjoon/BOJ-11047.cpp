//���� : ���� 0
//���� : �׸���� Ǯ���� ����. ���� ��ġ�� ��
//���� : ������ ��ġ�� ����̰� ���ƺ��� 10��
//�׸���� Ǯ���� ���� : 1��¥���� ������. ������ ���� ����.
//���� ��� ����� ��׵����� ���׵����� �����ϹǷ�, ��׺��� ������ ������
#include <iostream>

using namespace std;

int main()
{
	int  N, K;
	cin >> N >> K;
	int *coin;
	int cnt = 0;

	coin = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		while (K - coin[i] >= 0) {
		
			cnt++;
			K -= coin[i];
		}
	}
	if(K == 0) cout << cnt;
	else cout << -1;
}