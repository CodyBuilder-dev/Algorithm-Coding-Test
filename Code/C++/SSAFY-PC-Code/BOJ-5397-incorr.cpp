//���� : Ű�ΰ�
//���� : Ű���� �Է°����κ��� ��й�ȣ�� �˾Ƴ���
//���� : �Է� ���ڿ��� ũ��� �ִ� 10^6

/*���̵��
1.�׽�Ʈ���̽� ���ڿ� �������� �˻�
2.�ش� �κ��� ���� ���� ��й�ȣ ���ڿ� �����
*/

//���� : string�� �߰��� ���� �ִ� ������� �����غ���

//������ : ���� Ŀ���� ��ġ�� ���ڿ� ���� �����ε�, �����ʹ� ���� ��ü�� ����Ŵ�� �����ؾ� ��
//������ : ���ڿ��� ĳ���ͷ�, ĳ���͸� ���ڿ��� �ٲٴ� �� Ȯ���� �� ��
//������ : 50%���� �ð� �ʰ� -> ���ڿ��� ����/���� ������ �����ϸ� �ð��ʰ� ��

#include <iostream>
#include <string>

using namespace std;

int T;

string inStr;
string passStr;
int pointer;

void delete_char(string str, int pointer)
{
	 //���� ���� �ʿ�

}

void check_char(char chr)
{
	switch (chr) {
	case '<': //�����̵��� ���, �������� ��ġ�� 0 �ʰ��� ����
		if (pointer > 0) pointer--;
		//cout << pointer << '\n';
		break;

	case '>': //�����̵��� ���
		if (pointer < passStr.size()) pointer++; 
		//cout << pointer << '\n';
		break; //�������� ��ġ�� passStr ������ �̸��̸� ����
	case '-': //BS�� ���
		if (pointer > 0) {
			passStr.erase(pointer - 1, 1);
			pointer--;
		}
		//cout << pointer << '\n';
		break;
	default: //���ĺ��� ���
		passStr.insert(pointer,1,chr);
		pointer++;
		//cout << pointer << '\n';
	}
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> inStr; //�Է� ���ڿ� �ޱ�
		passStr.clear(); //�н����� ���ڿ� �ʱ�ȭ
		pointer = 0;

		for (int j = 0; j < inStr.size(); ++j) { // �Է� ���ڿ� ó������ ������ Ž��
			check_char(inStr[j]); //���ھ� üũ
		}
	
		cout << passStr<< '\n';
	}
}