//���� : �ź���
//���� : �ź����� ������ ���� ���� �� �ִ� ���� ū ���簢��
//���� : ���� 4���� ���� 100�̸��� �ڿ���
//���� : ����+����
/*
���̵�� : ���� 4���� ������� ���鼭 �簢�� �����
1. ���Ʈ ������ �̿��� �ù� �����, 2�����迭, DFS�� �̿��� ����Ѵ�
2. �簢�� �ִ������ ������ ������ �����.
*/

/*
�簢���� ���� ����
1. ������ ������ �𸣰ڴ�
2. �ٵ� ������ �� ª �� ª�̴�
3. �׷� �������� �����ϰ� front back front back �ϸ� �ȴ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> walk;
	
	for (int i = 1; i <= 4; ++i)
	{
		int temp;
		cin >> temp;
		walk.push_back(temp);
	}

	sort(walk.begin(), walk.end());

	cout << walk[0] * walk[2];

}