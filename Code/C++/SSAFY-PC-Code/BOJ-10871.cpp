//���� : X���� ���� ��
//���� : �迭�� for���� �� �� �ƴ°�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, X;
	vector<int> numarray;

	cin >> N >> X;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		numarray.push_back(temp);
	}
	//���� �ϸ� �ȵ� ����
	//sort(numarray.begin(), numarray.end());

	
	for (int i = 0; i < N; ++i)
		if (numarray[i] < X) cout << numarray[i] << ' ';
	
}