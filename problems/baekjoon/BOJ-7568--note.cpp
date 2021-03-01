//���� : ��ġ
//���� : �����Կ� Ű�� �־��� ��, �� ������� ��ġ ��ŷ ���
//���� : ����� �ִ� 50��, Ű, �����Դ� �ִ� 200

/*���̵�� �� ����: ��Ʈ�� �� ������� ��ġ�� ū ����� n���̸� �� ����� n+1���̶�� ��
1. n���߿� 2�� ���ؾ� �ϹǷ� O(0.5*N^2)
2. ������� ���� 2���� �����ϹǷ�, pair�� �̿��� ����
3. pair�� vector�� �̿��� �����غ���
*/

/*������ : ��Ʈ�� ������ ���� Ǯ������, ��Ʈ�� �������� �� Ǯ���� ���� ����.
��Ʈ ���̵� n�̸� n+1���� �Ǵ� ������ ��Ȯ�ϰ� ���߿� �����غ���
*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<pair<int, int>> people;
	vector<int> ranking;

	cin >> N;
	int weight, height;
	for (int i = 0; i < N; ++i)
	{
		cin >> weight >> height;
		people.push_back(make_pair(weight, height));
	}
	int upper;
	for (int i = 0; i < N; ++i) {
		upper = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;

			if (people[i].first < people[j].first && people[i].second < people[j].second)
				upper++;
		}
		ranking.push_back(upper);
	}

	for (int i = 0; i < N; ++i)
		cout << ranking[i] + 1 << ' ';
}