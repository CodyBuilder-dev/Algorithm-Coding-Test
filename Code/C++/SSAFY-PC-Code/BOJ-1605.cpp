//���� : �ݺ� �κй��ڿ�
//���� : 2���̻� �ݺ��Ǵ� �κй��ڿ� ���ϱ�
//���� : ���ڿ��� ���̴� �ִ� 200,000

/*���̵��3 :
1.���ī�� �˰��� ���
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int rabin(string str)
{

}
int main()
{
	int L;
	cin >> L;
	string text;
	cin >> text;
	vector<string> usedString;
	int maxLength = 0;
	for (int i = 1; i < L; ++i) //���� i�� �κй��ڿ�
		for (int j = 0; j < L; ++j) //0�������� ����
		{
			bool isExist = false;
			string tempText = text.substr(j, i);
			//�����ϴ� ���
			if (find(usedString.begin(), usedString.end(), tempText) != usedString.end())
				continue;
			//�������� �ʴ� ���
			usedString.push_back(tempText);

			//��������� ���� �������� Ž��
			for (int k = j + 1; k <= L - i; ++k)
				//���� ��� true�ϰ� Ż��
				if (tempText.compare(text.substr(k, i)) == 0)
				{
					isExist = true;
					break;
				}
			if (isExist == true) maxLength = i;
		}
	cout << maxLength;
	return 0;
}