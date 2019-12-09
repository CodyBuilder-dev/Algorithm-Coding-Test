//���� : ġŲ ���
//���� : ġŲ���� 1���� �ִ� M�������� ���� ��, ������ ġŲ�Ÿ��� �ּҰ��� ���ض�
//���� : ���ô� �ִ� 50x50. ġŲ���� �ִ� 13

//����ѹ��� : ������3

/*���̵�� : 
1.ġŲ�� ��ǥ ���Ϳ� �ֱ�
2.M���� �����ؼ� 1���� ���̸鼭 ����Ǽ� ����
3.����Ǽ��� ���õǸ�, ���� ��ü�� ���鼭 �� ������ ��� ġŲ�� �Ÿ� üũ
4.��� ġŲ�Ÿ��� ���� �ּҰ� ���
5. (�ʿ��ϴٸ�)��Ʈ��ŷ���� �ּҽð� �Ѿ�� Ż��ǵ���
*/

#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
int totalChicken;

int board[50][50];
deque<pair<int, int>> chickenXY;
deque<int> chickenSelect;
deque<int> distSet;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				chickenXY.push_back(make_pair(i, j));
				totalChicken++;
			}
			
		}

	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << board[i][j];
		cout << '\n';
	}*/
}



int calc_distance(pair<int,int> start, pair<int, int> end)
{
	int dist = abs(start.first - end.first) + abs(start.second - end.second);
	return dist;
}

void find_minimum_distance()
{
	int distSum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == 1) {
				int dist = 987654;
				for (int k = 0; k < chickenXY.size(); ++k){
					if (chickenSelect[k] == 1) {
						int temp = calc_distance(make_pair(i, j), chickenXY[k]);
						dist = (temp < dist) ? temp : dist;
					}
				}
				distSum += dist;
			}
		}
	}
	distSet.push_back(distSum);
}

//��� ����� ���� ����� �Լ�
void make_case()
{
	for (int chicken = 1; chicken <= M; ++chicken) {
		//cout << chicken << "��°" << '\n';

		for (int i = 0; i < totalChicken - chicken; ++i)
			chickenSelect.push_back(0);
		for (int i = totalChicken - chicken; i < totalChicken; ++i)
			chickenSelect.push_back(1);

		do {
			find_minimum_distance();

		} while (next_permutation(chickenSelect.begin(), chickenSelect.end()));
		chickenSelect.clear();
	}

}

int main()
{
	input();
	make_case();
	int min = 987654;
	for (int i = 0; i < distSet.size(); ++i)
		if (distSet[i] < min) min = distSet[i];

	cout << min;
}