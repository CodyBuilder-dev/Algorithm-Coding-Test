//���� : ���ڿ� �ݺ�
//���� : ���ڿ��� *������ �ɱ� �ȵɱ�? �ȵǸ� ��� �ݺ� ����ұ��?
//��� : *���� ���ڷ� �νĵʤ�����
//���̵�� : 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	int R;
	string str;
	
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		cin >> R >> str;

		for (int j = 0; j < str.size(); ++j)
			for(int k = 1; k <= R; ++k)	cout << str[j];

		cout << '\n';
	}
}