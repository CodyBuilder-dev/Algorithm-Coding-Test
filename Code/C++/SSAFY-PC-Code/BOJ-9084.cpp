//���� : ����
//���� : ������ �׸鰡�� �־�����, �ش� ������� Ư�� ���� ���� �� ����� ��
//���� : ����� ���� int���� ��

/*���̵�� : ������ ������ŭ ������ �ִ� Ʈ����� ������ �� ����
1. DFS�� ����, ��Ʈ��ŷ�̳� DP�� �� ����� ����ؾ� ��
*/



#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int T;
int N, M;
int coinArray[20]; //0���� 

int sumArray[10000];

int selectedCoin; //0������ ������ 10^0�ڸ���, 1������ ������ 10^1�ڸ���
set<int> selectedSet;

void dfs(int sum, int selectedCoin)
{
	if (sum == M) { //�� ��ǥġ�� ������ ����
		selectedSet.insert(selectedCoin);
		return;
	}
	if (sum > M) return; //���� ����� �׳� return
	
	for (int i = 0; i < N; ++i)
	{
		
		sumArray[sum + coinArray[i]]++;
		dfs(sum + coinArray[i], selectedCoin + pow(10, i));
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> coinArray[j];
		cin >> M;

		dfs(0, 0);
		cout << selectedSet.size() << '\n';
	}
}