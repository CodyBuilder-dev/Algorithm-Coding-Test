//���� : �� ��� - 2
//���� : ���ǿ� �°� ȭ�鿡 ���� ����ϴ� ����
//���� : ���� �ִ� 100��

#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) //���� ��Ȯ�� �ؾ� ��
			if (j > N-i) cout << '*'; //������ ' ', �����ʺ��� iĭ�� *�̹Ƿ�
			else cout << ' ';
		cout << '\n';
	}
}