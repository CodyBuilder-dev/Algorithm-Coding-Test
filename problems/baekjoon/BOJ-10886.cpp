//���� : 0=not cute/1 = cute
//���� : for���� ���� �Է��� ���� �� �ִ°�
//���� : �������� �� N�� �ִ� 101

//������ : �̷� ���� ������ ���� ������ ��ȸ���� ���� �չ�ȣ�� �����°� �����ε�
//�Ƹ� �ð��� �ܷ�� ��ȸ Ư����, �̷� ������ �°� Ʋ���� ������ �ƴ϶� �󸶳� ���� Ǫ���İ� �����ε�
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin.tie(NULL);
	cin >> N;
	int sum = 0;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		sum+=temp;
	}
	if (sum > N / 2) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
}