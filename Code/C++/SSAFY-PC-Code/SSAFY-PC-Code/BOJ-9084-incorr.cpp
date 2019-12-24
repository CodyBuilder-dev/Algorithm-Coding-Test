//���� : ����
//���� : ������ �׸鰡�� �־�����, �ش� ������� Ư�� ���� ���� �� ����� ��
//���� : ����� ���� int���� ��

/*���̵�� : ������ ������ŭ ������ �ִ� Ʈ����� ������ �� ����
1. ���� ���� �׸鰡���� �����ؼ�, DFS�� �İ� �ö󰡱�
2. �İ� �ö󰡸鼭 �� ������ ������ �迭�� ����
3. ���� �ٸ� �迭�� ������ ���ϸ� �װ� �ٷ� ����� ��
*/

//������ : �׳� DFS���� �ð��ʰ� �� ������

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int T;
int N, M;
int coinArray[20]; //0���� 
int selectedCoin; //0������ ������ 10^0�ڸ���, 1������ ������ 10^1�ڸ���
set<int> arraySet;

void dfs(int sum, int selectedCoin)
{
	if (sum == M) { //�� ��ǥġ�� ������ ����
		arraySet.insert(selectedCoin);
		return;
	}
	if (sum > M) return; //���� ����� �׳� return
	for (int i = 0; i < N; ++i)
	{
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
		cout << arraySet.size() << '\n';
	}
}