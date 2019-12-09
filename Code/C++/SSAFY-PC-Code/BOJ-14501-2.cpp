//���� : ���
//���� : ���ǥ�� ����, �����Ⱓ �� ������ �ִ�� �ǵ��� ��� ���
//���� : N<15�̹Ƿ�, �� �������� 2^15 = 32000����. O(NlogN)���� �Ҹ� ��


/*���̵��2 : ���������� ������ �����Ƿ�, ��� ���������� ������ų�� �����ؾ� ��
1. ���ں��� ���� �������� �ߺ������� ���� ����
2. for���� ���鼭, �� ��¥���� valid���� ���캽
3. ���ǿ� �� ������ �Ÿ�
4. ���ǿ� ������ ���� max�� ���ؼ� ����
(���������� 1,2..N�������� �ε����� 0,1,...N-1����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> days;
vector<int> pays;
vector<int> dayIdx;

int maxPay = 0; 

int day_check(vector<int>dayIdx)
{
	for (int i = 0; i < N; ++i) //0~N-1
	{
		if (dayIdx[i] == 1) //Ư������ ���õǾ�������
		{
			if (i + days[i] > N) //����� �ʰ��� -1
				return -1;
			for (int j = 1; j < days[i]; ++j) //�ش��Ϸκ��� ������� �˻�
				if (dayIdx[i + j] == 1) return -1;//�Ұ��ɽ� -1
			
		}
	}
	return 1;
}

//������ : �̸� set�� �ƹ� ���̵� �־ size�� �Ҵ��ص��� ��� ��
void repeatedPerm(vector<int> set, int setSize, int n, int r) {
	//���� ����
	if (setSize == r) {
		if (day_check(set) == -1) return;
		else {
			int sum = 0;
			for (int j = 0; j < set.size(); ++j)
				if(set[j] == 1) sum += pays[j];
			maxPay = max(sum, maxPay);
		}
		return;
	}
	//�б� ����
	for (int i = 0; i < n; ++i) {
		set[setSize] = i;
		repeatedPerm(set, setSize + 1, n, r);
	}
}

int main()
{

	cin >> N;
	//����, ���� �޾ƿ���




	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		days.push_back(a);
		pays.push_back(b);
		dayIdx.push_back(0);
	}
	
	
	//���⼭���� �������� �ڵ� ����
	repeatedPerm(dayIdx, 0, 2, N);
	cout << maxPay;
	return 0;
}