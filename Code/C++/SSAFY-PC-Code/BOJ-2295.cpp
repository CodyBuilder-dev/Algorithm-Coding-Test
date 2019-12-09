//���� : ������ ��
//���� : ���� �� ���ҵ��� ���� �� ���տ� ���ԵǴ°� ����(���������� �� �����ٵ�)
//���� : ���� ������ <=1000 ������ ���Ҵ� <=2*10^9

/*
���̵�� : 
1. ���Ʈ������ ���� �� �˾Ҵµ� 1000�����̶� �Ҹ���
2. �ٵ� �����غ��� ���Ʈ���� ����� ���� ����
3. �ӵ��� ����Ű�� ���� ����, �ڿ������� ���ذ��鼭 Ǯ�� �ɵ�
*/

/*���� :
index�� 3�� �����ϸ� �ǹǷ� 3�� for��. �� �̷� 10^9�ε�?
���� 2��*3�����̹Ƿ� 6��, �� long long
���� ���ؼ� ������ �ڿ������� �ִ��� �˻�
�˻��� max�� ���� ��ü
*/
//������ : �ð��ʰ� �� ����
//������ : �ڷ� ���� ũ��� ������ ũ�⸦ �� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<long long> set;
	vector<long long>::iterator itr;
	vector<long long> failed;
	vector<long long>::iterator itr2;

	for (int i = 0; i < N; ++i){
		int temp;
		cin >> temp;
		set.push_back(temp);
	}
	//������ ���ֳ� �ȵ��ֳ� ���ڴµ� �ϴ� �׳� ���
	//������ �ȵż� �ð��ʰ��ϼ��� ����. �����غ���
	sort(set.begin(), set.end());

	//�ƴϸ� �޸������̼� �����ؾ� �� ���� ����
	//�̹� ����غ� ���� ���°���.
	long long Sum;
	long long Max;
	int maxidx;
	for (int i = N - 1; i >= 0; --i)
		for (int j = N - 1; j >= 0; --j)
			for (int k = N - 1; k >= 0; --k){
				Sum = set[i] + set[j] + set[k];
				itr2 = find(failed.begin(), failed.end(), Sum);
				if (itr2 != failed.end()) continue;//failed�ȿ� ���Ե� ���

				maxidx = max(j,k);
				maxidx = max(maxidx, i);
				itr = find(set.begin()+maxidx, set.end(), Sum);//find�� ����, �ּҹ����� ���� �� ����
				if (itr != set.end())//find�� ������ ������ ���ɼ��� ����ξ�� ��
					Max = max(Sum, Max);
				else if (Sum == set[N - 1])
					Max = max(Sum, Max);
				else
					failed.push_back(Sum);
			}

	cout << Max;
}



