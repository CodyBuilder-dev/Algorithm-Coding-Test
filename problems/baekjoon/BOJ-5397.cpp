//���� : Ű�ΰ�
//���� : Ű���� �Է°����κ��� ��й�ȣ�� �˾Ƴ���
//���� : �Է� ���ڿ��� ũ��� �ִ� 10^6

/*���̵��
1.�׽�Ʈ���̽� ���ڿ� �������� �˻�
2.�ش� �κ��� ���� ���� ��й�ȣ ���ڿ� �����
*/

/*���� : STL�� list�� �̿��� ����
1. list�� ���� �ε����� �Ұ����� �ڷᱸ������ ��� ��ĭ�� �Ѿ�°�
-> �ݺ��ڸ� ��� ��
2. �ݺ����� index�� distance��, ���� *�� ���
*/


#include <iostream>
#include <string>
#include <list>

using namespace std;

int T;

string inStr;
list<char> passStr(1);
list<char>::iterator itr;

void check_char(char chr)
{
	switch (chr) {
	case '<': //�����̵��� ���, �������� ��ġ�� 0 �ʰ��� ����
		if (itr != passStr.begin()) itr--;
		break;

	case '>': //�����̵��� ���
		if (itr != passStr.end()) itr++;
		break; //�������� ��ġ�� passStr ������ �̸��̸� ����
	case '-': //BS�� ���
		if (itr != passStr.begin()) {
			itr--;
			itr = passStr.erase(itr);
		}
		//cout << pointer << '\n';
		break;
	default: //���ĺ��� ���
		passStr.insert(itr,chr);
		//itr++;
		//cout << pointer << '\n';
	}
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> inStr; //�Է� ���ڿ� �ޱ�
		passStr.clear(); //�н����� ���ڿ� �ʱ�ȭ
		itr = passStr.begin();

		for (int j = 0; j < inStr.size(); ++j) { // �Է� ���ڿ� ó������ ������ Ž��
			check_char(inStr[j]); //���ھ� üũ
		}

		for(itr = passStr.begin();itr!=passStr.end();++itr)
			cout << *itr;
		cout << '\n';
	}
}