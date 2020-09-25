//���� : ��ŸƮ�� ��ũ
//���� : N���� ������� ��ŸƮ�� ��ũ�� ���� ��, ���� �ɷ�ġ�� �յ��ϰ� ������
/*����
1. � ����� �ٸ� ����� ���� ���� ���� �ó����� �����
2. �̴� ǥ�� ��Ÿ�� �� �ִ�.
3. ���� �ɷ�ġ�� ��� �ó����� ���̴�.
*/

/*���̵�� :
1. �켱 N/2�� ������ �ε����� �غ��Ѵ�.
2. ǥ�� Ž���ϸ� �ε��� ���� �ó����� ��� ���Ѵ�
3. ������ �������� ���� ���� ���� ���Ѵ�.
4. ���� �ּҰ� ���
*/
/*���� :
1. N/2 �� ������ �����  N/2���� 1�� N/2���� 2�� �غ��� �� ���� ���� �ִ� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int **synergy;

int main()
{
	cin >> N;

	synergy = new int*[N];
	vector<int> teamSelect;

	for (int i = 0; i < N; ++i)
		synergy[i] = new int[N];

	int temp;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			cin >> temp;
			synergy[i][j] = temp;
		}
	
	for (int i = 0; i < N / 2; ++i){
		teamSelect.push_back(1);//��ŸƮ���� 1
		teamSelect.push_back(2);//��ũ���� 2
	}

	sort(teamSelect.begin(), teamSelect.end());

	int start, link;
	int minDifference=987654321;

	do {
		start = 0; link = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j){
				if (teamSelect[i] == 1 && teamSelect[j] == 1) //��ŸƮ�� �����̸�
					start += synergy[i][j];
				if (teamSelect[i] == 2 && teamSelect[j] == 2) //��ũ�� �����̸�
					link += synergy[i][j];
			}
		if (minDifference > abs(start - link)) minDifference = abs(start - link);
	} while (next_permutation(teamSelect.begin(), teamSelect.end()));
	cout << minDifference;
}
