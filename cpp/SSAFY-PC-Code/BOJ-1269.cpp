//���� : ��Ī ������
//���� : ��Ī �������� ������ ������ ���
//���� : ����?
//���� : ���� ���� <= 200,000 ���Ұ� 100,000,000

/*���̵�� : 
�������δٰ� �׳� ��ü �����տ��� ������ ���� ���ڳ�
*/

/*����
1. �⺻ data�� ������ �����Ѵ�
2. �׳� stl set ����.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	
	vector<int> vecA, vecB;
	//�ߺ��Ǵ� ���Ҵ� �Է´ܿ������� ���ٰ� �����ϰ� vector ���
	for (int i = 1; i <= N; ++i){
		int temp;
		cin >> temp;
		vecA.push_back(temp);
	}
	sort(vecA.begin(), vecA.end());
	for (int i = 1; i <= M; ++i)
	{
		int temp;
		cin >> temp;
		vecB.push_back(temp);
	}
	sort(vecB.begin(), vecB.end());
	//��Ī�������� algorithm �Լ� ���
	//���ĵ� vector�� ��� ��.�׷��� ������ ��Ÿ�� ����
	//set_symmetric_difference(
	vector<int> result;
	result.resize(vecA.size() + vecB.size());//����Ȯ��
	vector<int>::iterator itr = set_symmetric_difference(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), result.begin());//������
	result.erase(itr, result.end());//�������� ����
	
	cout << result.size();
}