//���� : �� �����ϱ� 3
//���� : ���ڰ� ���� ��� ī���� ���� ���
//����� �� �� ���� stl ���� �����
//�޸� �ʰ� ���� �߻� ����
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	int max;
	int *numarray;
	int *cntarray;
	vector<int> ans;
	cin >> N;

	numarray = new int[N];
	

	for (int i = 0; i < N; ++i)
	{
		cin >> numarray[i];
	}
	max = *max_element(numarray, numarray+N);
	//cout << max;
	
	cntarray = new int[max+1]();
	
	for (int i = 0; i < N; ++i)
	{
		cntarray[numarray[i]]++;
	}

	for (int i = 0; i <= max; ++i)
	{
		while (cntarray[i] != 0) {
			cntarray[i]--;
			ans.push_back(i);
		}
	}

	for (int i = 0; i < N; ++i)
		cout << ans[i] << '\n';

	delete[] numarray;
	delete[] cntarray;
	return 0;
}