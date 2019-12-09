//���� : ��� ����
//���� : �л� 5���� ��������� ���϶�. �� C++���� ����� ���� �� �ƴ°�

/*���̵�� : �׳� �迭+for������ ���ϸ� ��̾�����, �Լ��� ã�ƺ���
accumulate�� ������, �̰Ͱ� vector size�� �̿��ؼ� ����
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> score;
	int temp;
	for (int i = 0; i < 5; ++i)
	{
		cin >> temp;
		if (temp < 40) temp = 40;
		score.push_back(temp);
	}

	
	int mean = accumulate(score.begin(), score.end(),0) / score.size();

	cout << mean;
}
