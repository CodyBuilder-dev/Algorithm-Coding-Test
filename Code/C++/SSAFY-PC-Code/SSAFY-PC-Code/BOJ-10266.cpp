//���� : �ð� ������
//���� : �ð�ٴ��� ������ �־��� ��, �� �ð谡 ������ �� �ִ��� ���� �Ǵ�
//���� : ������ �ִ� 360,000, �ٴ��� �ִ� 200,000

/*���̵��1 : (X)
1. �ð�ٴ� ����� �޴´�
2. �����Ѵ�. (�ִ� 10^6)
3. �ð� �ϳ��� ��Ƽ� 1���� 360,000���� �� ������
4. ���Ѵ�(10^5)
*/

/*���̵��2 :
(�ð������ ���)
1. �ð�ٴ��� �����Ѵ�
2. �ð�ٴð��� ���� '����'�� ����Ѵ�
3. ������ ��� ������ ������
(�ݽð������ ���)
1. ���� ���������� �ݺ�
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> clock1, clock2;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		clock1.push_back(temp);
	}

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		clock2.push_back(temp);
	}
	
	sort(clock1.begin(), clock1.end());
	sort(clock2.begin(), clock2.end());
	
	clock1.push_back(clock1[0] + 360000);
	clock2.push_back(clock2[0] + 360000);
	
	//���⼭���� ������ �ڵ� ����
	for (int i = 0; i < n - 1; ++i)
	{
		int temp;
		temp = clock1[i + 1] - clock1[i];

	}

}