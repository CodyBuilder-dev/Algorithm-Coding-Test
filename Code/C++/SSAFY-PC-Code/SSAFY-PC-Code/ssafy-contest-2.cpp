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

	//�ʱ�ȭ
	memset(graph, 0, 251001);
	memset(known, 0, 501);
	cnt = 0;

	int little, big;
	for (int i = 0; i < M; ++i) {
		cin >> little >> big;
		student[little].large.push_back(big);
		student[big].small.push_back(little);

		graph[little][big] = -1; //���� ������ -1�� ����
		graph[big][little] = 1; //���� ũ�� 1�� ����
		//���� �𸣸� 0
	}
}

bool check(int startnode)
{
	bool isKnow = true; //�ϴ� ó������ �ȴٰ� ����

	for (int j = 1; j <= N; ++j) {
		if (j == startnode) continue; //������ �پ�ѱ�
		if (graph[startnode][j] == 0) continue; // �ƹ����� ������ �پ�ѱ�
		
		else if (graph[startnode][j] == 1) { //������ �������̸�
			if (student[j].large.size() >= 2) { //�׳��� ū���� ���̸�
				for (int k = 0; k < student[j].large.size(); ++k) {
					if (student[j].large[k] == startnode) continue;
					else if (!graph[startnode][student[j].large[k]]) continue; //���� �˸�
					else isKnow = false; //���� �𸣸�
				}
			}
			else { //�׳��� ū���� �� �ϳ���
				continue;
			}
		}
		
		else { //������ ū���̸�
			if (student[j].small.size() >= 2) {//�׳��� �������� ���̸�
				for (int k = 0; k < student[j].small.size(); ++k) {
					if (student[j].small[k] == startnode) continue;
					else if (!graph[startnode][student[j].small[k]]) continue; //���� �˸�
					else isKnow = false; //���� �𸣸�
				}
			}
			else {//�׳��� �������� �� �ϳ���
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