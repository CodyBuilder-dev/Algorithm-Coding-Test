//���� : �ູ���� ������
//���� : �̸�Ƽ�� :-)�� :-(�� ������ ���� ������ �����ִ� ���α׷��� �ۼ��Ѵ�.
//���� : ���ڸ޽����� �ִ� 255��. �ݵ�� :-)�� ���·� ���Ѿ� ��

/*���̵�� : 
1. ������ ���Ե� ���ڿ��� �ѹ��� ���� �� �ִ°�
2. ���ڿ����� ���� ������ ������ Ž���� �� �ִ°�
*/

/* ���� : 
1. �켱 :-) :-( �����صα�
2. substr�� ���ϱ�
*/

/*������ : 
1.���ڿ��� ������ ���� Ȯ���� �����ϰ� �� �ʿ䰡 ����
2.substr���� ���� ���̰� ª�� ��� ����ó�� �ʿ�
*/
#include <iostream>
#include <string>

using namespace std;

string txt;
string sad = ":-(";
string happy = ":-)";
int mood; //happy�� ���, sad�� ����
bool isExist;

int main()
{
	getline(cin, txt);

	if (txt.length() >= 2) {
		for (int i = 0; i < txt.length() - 2; ++i)
		{
			if (txt[i] == ':') {
				if (txt.substr(i, 3).compare(sad) == 0)
				{
					mood--;
					isExist = true;
				}
				else if (txt.substr(i, 3).compare(happy) == 0)
				{
					mood++;
					isExist = true;
				}
			}
		}
	}
	if (isExist)
		printf("%s", (mood > 0) ? "happy" : (mood == 0) ? "unsure" : "sad");
	else
		cout << "none";
}



