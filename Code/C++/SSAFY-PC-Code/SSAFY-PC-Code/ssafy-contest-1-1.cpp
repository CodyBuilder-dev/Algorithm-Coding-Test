#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int N, M;
bool graph[11][11];
deque<int> order;

int max_length;

void input()
{
	cin >> N >> M;

	memset(graph, 0, 121);
	
	//그래프 입력
	int start, end;
	for (int i = 0; i < M; ++i) {
		cin >> start >> end;
		graph[start][end] = true;
		graph[end][start] = true;
	}

	//입력 확인용
	//for (int i = 1; i <= N; ++i) {
	//	for (int j = 1; j <= N; ++j)
	//		cout << graph[i][j];
	//	cout << '\n';
	//}
}

void make_order()
{
	order.clear();
	//1번~N번까지 deque에 삽입
	for (int i = 1; i <= N; ++i) {
		order.push_back(i);
	}

	
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		make_order();
		
		do {
			for (int i = 0; i < order.size(); ++i)
				cout << order[i];
			cout << '\n';

			int length = 1;
			for (int j = 0; j < order.size(); ++j) {
				if (j < order.size() - 1) {
					if (graph[order[j]][order[j + 1]])
						length++;
					else
						break;
				}
			}
			max_length = (length > max_length) ? length : max_length;
		} while (next_permutation(order.begin(), order.end()));
		
		cout << '#' << i << ' ' << max_length << '\n';
	}
	return 0;
}