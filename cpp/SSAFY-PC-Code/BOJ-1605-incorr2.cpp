//���� : �ݺ� �κй��ڿ�
//���� : 2���̻� �ݺ��Ǵ� �κй��ڿ� ���ϱ�
//���� : ���ڿ��� ���̴� �ִ� 200,000

/*���̵��2 :
�տ��� N^3�� ��Ʈ��ŷ �غ��� ���� ����. �ƿ� �ٸ� ���ٹ��
1. ��Ʈ��ŷ�� ����
2. KMP�Ἥ ����ȭ
3. 
*/

//������ : ���-ī���� KMP�� ������ �ٸ�
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findPi(string str)
{
	int len = str.size();
	int maxPi = 0;
	for (int prelen = 1; prelen < len; ++prelen) {
		string prefix = str.substr(0, prelen);
		string suffix = str.substr(len - prelen, prelen);
		if (prefix.compare(suffix) == 0)
			maxPi = prelen;
	}
	return maxPi;
}

bool KMP(string str, string pattern)
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
			//��Ʈ��ŷ - �����ϴ� ���
			if (find(usedString.begin(), usedString.end(), tempText) != usedString.end())
				continue;
			//�������� �ʴ� ���
			usedString.push_back(tempText);

			//��������� ���� �������� Ž��. KMP ����
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