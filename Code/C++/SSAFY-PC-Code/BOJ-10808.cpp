//���� : ���ĺ� ����
//���� : ���ĺ� �ҹ��ڷ� �̷���� �ܾ�� �� ���ĺ� ���� ����
//���� : ���̴� �ִ� 100

/*���̵�� : ���ĺ� üũ �迭�� ���� �ƴ°� ���� ����
1. ���ĺ� üũ �迭 int check[26] ����
2. �ܾ �޾� ���������� üũ
3. �ð����⵵�� O(M)
*/

#include <iostream>
#include <string>

using namespace std;

int check[26];

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
		check[str[i] - 97]++;

	for (int i = 0; i < 26; ++i)
		cout << check[i] << ' ';
}