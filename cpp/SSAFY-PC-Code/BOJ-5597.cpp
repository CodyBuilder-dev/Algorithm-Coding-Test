//���� : ���� �� ���� ��..?
//���� : 30�� �� ������ �� �� 2���� ��ȣ�� ã�Ƴ���

/*���̵�� : �׳� �ϸ� �ʹ� ����� �� ���ְ� �����ϱ�?
1. �����佺�׳׽��� ü ����ϰ� �ϱ�
*/

/*������ : 
1.�迭�� �� ���� ���� �߰��ϴ°� �����ϸ� ����
2.���� B�� ���θ� �����Ѵٸ�, ������ ���̺귯���� Ǯ���� �̷� ������ ���̺귯�� �� ���� Ǫ�°ͺ��� �ٽ� �ؾ��� ��
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int numArray[30] = { 0 };
	std::vector<int> notSubmit;
	
	int temp;
	for (int i = 0; i < 28; ++i) {
		std::cin >> temp;
		numArray[temp - 1] = 1;
	}
	
	//�迭 �� ���� �߰��ϱ�
	for (int i = 0; i < 30; ++i)
		if (numArray[i] == 0)
			notSubmit.push_back(i + 1);

	std::sort(notSubmit.begin(), notSubmit.end());
	std::cout << notSubmit[0] <<' '<< notSubmit[1];	
}