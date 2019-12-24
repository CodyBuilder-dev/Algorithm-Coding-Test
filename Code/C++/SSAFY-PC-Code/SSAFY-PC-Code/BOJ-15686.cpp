//제목 : 치킨 배달
//목적 : 치킨집을 1부터 최대 M개까지만 남길 때, 도시의 치킨거리가 최소값을 구해라
//조건 : 도시는 최대 50x50. 치킨집은 최대 13

//비슷한문제 : 연구소3

/*아이디어 : 
1.치킨집 좌표 벡터에 넣기
2.M부터 시작해서 1까지 줄이면서 경우의수 선택
3.경우의수가 선택되면, 보드 전체를 돌면서 각 집마다 모든 치킨집 거리 체크
4.모든 치킨거리의 합을 최소값 경신
5. (필요하다면)백트래킹으로 최소시간 넘어가면 탈출되도록
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

//모든 경우의 수를 만드는 함수
void make_case()
{
	for (int chicken = 1; chicken <= M; ++chicken) {
		//cout << chicken << "번째" << '\n';

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