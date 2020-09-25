//문제점 : 시간복잡도가 O(2^200)이므로 완탐하면 터짐?
/*느낀점 : for문에서 가지치기는 크게
*/

#include <iostream>
#include <set>

using namespace std;

int N, M;

bool banned[201][201];


set<set<int>> combiSet;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		banned[x][y] = true;
		banned[y][x] = true;
	}

	for (int i = 1; i <= N; ++i) {
		set<int> combi;
		combi.insert(i);
		for (int j = i+1; j <= N; ++j) {
			if (banned[i][j] == true) continue;
			set<int> newcombi1(combi);
			newcombi1.insert(j);
			for (int k = j+1; k <= N; ++k) {
				if (banned[i][k] == true || banned[j][k] == true) continue;
				if (i == k || j == k) continue;
				set<int> newcombi2(newcombi1);
				newcombi2.insert(k);
				combiSet.insert(newcombi2);
			}
		}
	}
	cout << combiSet.size();
}