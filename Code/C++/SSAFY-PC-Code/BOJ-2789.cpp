//���� : ���� ����
//���� : ���ڿ� ������ Ư�� ���ĺ��� �����
//���� : ���ڿ��� ���̴� �ִ� 100

/*���̵�� : 'str'������ 'char'ã��
1. CAMBRIDGE ���ڿ��� ���ĺ��� �迭�� ����
2. ���ڿ��� ������, �迭�� ����� �Ͱ� �ѱ��ھ� ��
3. ���ؼ� ������ ����
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string cambridge = "CAMBRIDGE";
	string inStr, outStr;

	cin >> inStr;

	for (int i = 0; i < inStr.length(); ++i)
	{
		if (find(cambridge.begin(), cambridge.end(), inStr[i]) != cambridge.end())
			continue;
		outStr.push_back(inStr[i]);
	}
	
	cout << outStr;

	return 0;

}