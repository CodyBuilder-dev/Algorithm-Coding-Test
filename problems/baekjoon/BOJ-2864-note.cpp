//���� : 5�� 6�� ����
//���� : ���ڸ� ���ڿ��� �ν��ؼ� �����ϱ�
//���� : �� ���� ���� 1,000,000 ����

/*���̵�� :
1. ���ڸ� �Ѱ��� �޾Ƽ� �迭�� ���� ����
2. ���� �� �ǽð����� 5�� 6����, 6�̸� 5�� ���� ���� ����
3. �ּ�, �ִ븦 ã��
*/

/*����
1. scanf �̿� 1���ھ� �ޱ�
2. �ѹ��� ���ڷ� ���� ��, sprintf()�� ó���ϱ�
(string�̶� sprintf ȣȯ�Ǵ��� Ȯ��->ȣȯ �ȵ�!)
*/

/*������ : 
1.����<->str<->char*���� �ɼ��� ��ȯ�� �߿���
2.�ǽð�/�ް��� or C/C++ style�� ���� �پ��� Ǯ�� ����
*/


#include <iostream>
#include <string>

using namespace std;

int A, B;

int main()
{
	int a,b;
	string aStr, bStr;
	

	scanf("%d %d", &a, &b);
	aStr = to_string(a);
	bStr = to_string(b);

	string minStr, maxStr;
	int minSum=0, maxSum=0;
	for (int i = 0; i < aStr.length(); ++i)
	{
		if (aStr[i] == '5') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else if (aStr[i] == '6') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else {
			minStr.push_back(aStr[i]);
			maxStr.push_back(aStr[i]);
		}
	}

	minSum += atoi(minStr.c_str());
	maxSum += atoi(maxStr.c_str());

	minStr.clear();
	maxStr.clear();

	for (int i = 0; i < bStr.length(); ++i)
	{
		if (bStr[i] == '5') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else if (bStr[i] == '6') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else {
			minStr.push_back(bStr[i]);
			maxStr.push_back(bStr[i]);
		}
	}
	minSum += atoi(minStr.c_str());
	maxSum += atoi(maxStr.c_str());

	cout << minSum << ' ' << maxSum;

}
