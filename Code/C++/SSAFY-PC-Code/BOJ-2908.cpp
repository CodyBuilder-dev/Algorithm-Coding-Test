//���� : ���
//���� : ���ڸ� �Ųٷ� ���� �� �� ũ�⸦ ���Ѵ�
//���� : ���ڴ� ���ڸ� ���̴�.

/*���̵�� : ���������� ���ڸ� ���ڿ��� ������ ��ȯ�ؼ� ó��
1. ���ڿ��� ����
2. ������
3. ��
*/

#include <iostream>
#include <string>

using namespace std;

int a, b;

int main()
{
	cin >> a >> b;
	string aStr = to_string(a);
	string bStr = to_string(b);
	swap(aStr[0], aStr[2]);
	swap(bStr[0], bStr[2]);

	a = atoi(aStr.c_str());
	b = atoi(bStr.c_str());
	
	if (a > b) cout << a; else cout << b;
	return 0;
}