#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
	deque<int> small;
	deque<int> large;
}Node;

Node student[501];
int graph[501][501];
bool known[501];

int T;
int N, M;

int cnt;

void input()
{
	cin >> N >> M;

	//초기화
	memset(graph, 0, 251001);
	memset(known, 0, 501);
	cnt = 0;

	int little, big;
	for (int i = 0; i < M; ++i) {
		cin >> little >> big;
		student[little].large.push_back(big);
		student[big].small.push_back(little);

		graph[little][big] = -1; //보다 작으면 -1로 저장
		graph[big][little] = 1; //보다 크면 1로 저장
		//관계 모르면 0
	}
}

bool check(int startnode)
{
	bool isKnow = true; //일단 처음에는 안다고 가정

	for (int j = 1; j <= N; ++j) {
		if (j == startnode) continue; //같으면 뛰어넘기
		if (graph[startnode][j] == 0) continue; // 아무관계 없으면 뛰어넘기
		
		else if (graph[startnode][j] == 1) { //나보다 작은놈이면
			if (student[j].large.size() >= 2) { //그놈의 큰놈이 둘이면
				for (int k = 0; k < student[j].large.size(); ++k) {
					if (student[j].large[k] == startnode) continue;
					else if (!graph[startnode][student[j].large[k]]) continue; //나랑 알면
					else isKnow = false; //나랑 모르면
				}
			}
			else { //그놈의 큰놈이 나 하나면
				continue;
			}
		}
		
		else { //나보다 큰놈이면
			if (student[j].small.size() >= 2) {//그놈의 작은놈이 둘이면
				for (int k = 0; k < student[j].small.size(); ++k) {
					if (student[j].small[k] == startnode) continue;
					else if (!graph[startnode][student[j].small[k]]) continue; //나랑 알면
					else isKnow = false; //나랑 모르면
				}
			}
			else {//그놈의 작은놈이 나 하나면
				continue;
			}
		}
	}
	return isKnow;
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		for (int j = 1; j <= N; ++j) {
			known[j] = check(j);
		}

		for (int j = 1; j <= N; ++j)
			if (known[j]) cnt++;

		cout << '#' << i << ' ' << cnt << '\n';
		return 0;
	}
}