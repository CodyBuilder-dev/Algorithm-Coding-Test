//���� : ������ ����
//���� : ���ڿ����� ������ ������ ���
//���� : ���ڿ� ���� �ִ� 100

/*���̵�� : ���������ڿ� ����ǥ���� �־ Ǯ���

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char temp;
	int cnt = 0;
	char moum[] = { 'a','e','i','o','u' };

	while(cin >> temp)
		if (find(moum, moum + 5, temp) != moum + 5) {
			cnt++;
		}

	cout << cnt;


}