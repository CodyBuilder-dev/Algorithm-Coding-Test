//���� : �ܾ� ����
//���� : ���� checklist ��� �� �ϴ��� ���ϴ��� Ȯ���Ҷ��
//���� : �ܾ��� ���̴� �ִ� 100��


/*���̵�� : ���� ���ĺ� checklist ����� �ٽ�
1. �Է��� �޾Ƽ�
2. �Ѵܾ ���� ���鼭 üũ����Ʈ ���� ��
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int alphabet[26];

int main()
{
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 65 && str[i] <= 90) //�빮���� ���
			alphabet[str[i] - 65]++;
		else if (str[i] >= 97 && str[i] <= 122) //�ҹ����� ���
			alphabet[str[i] - 97]++;

	}

	int max = -987654321;
	char maxidx;
	for (int i = 0; i < 26; ++i)
	{
		if (alphabet[i] > max) {
			maxidx = i; max = alphabet[i];
		}
	}

	bool isDuplicated = false;
	for (int i = 0; i < 26; ++i)
	{
		if (i == maxidx) continue;
		if (alphabet[i] == max) isDuplicated = true;
	}
	//�����غ��� �׳� for�� 2�� ���� �� �����������̵�

	if (isDuplicated) cout << '?';
	else printf("%c",maxidx+65);
}