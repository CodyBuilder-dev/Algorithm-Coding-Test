//���� : �ܾ� ����
//���� : ���� checklist ��� �� �ϴ��� ���ϴ��� Ȯ���Ҷ��
//���� : �ܾ��� ���̴� �ִ� 100��

//�ƽ�Ű �ڵ� �����δ� a = 97 z = 122
//������ : üũ����Ʈ �������� sizeof�� 4��. ����?

#include <iostream>
#include <string>

using namespace std;

void print_max(int* checklist)
{
	int max = -1;
	int maxidx = -1;
	int maxcnt = 0;
	int i = 0;
	while(checklist[i] != NAN)
	{
		if (max < checklist[i])
		{
			max = checklist[i];
			maxidx = i;
			maxcnt = 0;
		}
		else if (max == checklist[i]) maxcnt++;
		
		++i;
	}
	if (maxcnt == 0) cout << (char)(maxidx+65);
	else cout << '?' ;
}
int main()
{
	string str;
	int checklist[26] = { 0 };
	
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i]>=65 && str[i]<=90) checklist[str[i] - 65]++;
		else checklist[str[i] - 97]++;
	}
	
	print_max(checklist);
	return 0;
}