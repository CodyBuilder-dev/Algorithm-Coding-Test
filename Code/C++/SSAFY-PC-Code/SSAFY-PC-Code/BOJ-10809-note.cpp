//���� : ���ĺ� ã��
//�ǵ� : check list Ȱ���� �ѹ� �غ����� ��� �ǹ� ��
//���̵�� : checklist �����, a=0, b=1, ....z = 25�� �������Ѿ� ��
//�̸� ���ؼ��� map�� ���� ���� �ְ�, �ƴϸ� ascii code�� ������ų ���� ����
//�ƽ�Ű �ڵ� �����δ� a = 97 z = 122
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int a[26];
	memset(a, -1, sizeof(a)); //�迭 0,-1�� �ʱ�ȭ�Ҷ� �� �� ����
	//�迭�� char Ÿ���̸� �ƹ� �����γ� �ʱ�ȭ�� �� ����

	string str;

	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (a[str[i] - 97] == -1) a[str[i] - 97] = i;
	}
	for (int i = 0; i < 26; ++i) cout << a[i] << ' ';
}