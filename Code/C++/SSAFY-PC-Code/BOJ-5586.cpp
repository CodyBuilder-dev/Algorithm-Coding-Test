//���� : JOI�� IOI
//���� : Ư�� ���ڿ�(JOI,IOI)�� �������� ���°� ã��
//���� : ���ڿ� ���̴� �ִ� 10000

/*���̵�� : �� ���� �� ���� Ž��
1. ���ڿ� ������ �ޱ�
2. J�� I�� ������, �� �ڷ� �����ؼ� 2�� �� ���캽
3. ���캼���� �÷��� �Ѱ� ���� vs �ٷ� ���Ǳ�
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int joi = 0, ioi = 0;

	for (int i = 0; i < str.length() - 2; ++i)
	{
		if (str.substr(i, 3).compare("JOI")==0) joi++;
		if (str.substr(i, 3).compare("IOI")==0) ioi++;
	}
	cout << joi << '\n' << ioi;
}