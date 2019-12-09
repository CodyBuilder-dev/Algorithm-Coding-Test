//���� : ���ٲ���
//���� : ������ �󿡼� ������ ��ġ�� ���� ���� ã�µ� �ɸ��� �ð�
//���� : ������ ������ 0~100,000

/* ���̵�� : ����������, �̰� �� BFS�� Ǯ��� �ϴ��� �������� �ϴ°� �켱�̴�.
1. ���� �������� �̵������� ����� ���� 3������
2. �� ���� �������� �ڽ��� 3���� Ʈ���� �׸��� �������� �˻��ϴ� ������ ġȯ����
3. �ּҽð��� ã�ƾ� �ϹǷ� BFS�� ��� ��
*/

/*���� :
1.�������̹Ƿ� 1�����迭�� ��������

*/

#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { 0 };

int BFS(int start, int end)
{
	int time = 0;
	if (start == end) return time;//�ٷ� ã�°�� �ʿ����
	visited[start] = true;
	
	queue<int> route;
	queue<int> timeQue;

	route.push(start);
	timeQue.push(time);

	while (!route.empty())
	{
		start = route.front();
		time = timeQue.front();

		route.pop();
		timeQue.pop();

		int ns = start + 1;//+1�ϴ� ���
		if (ns <= 100000 && ns >= 0){
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		ns = start - 1;//-1�ϴ� ���
		if (ns <= 100000 && ns >= 0) {
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		
		ns = start*2;//-1�ϴ� ���
		if (ns <= 100000 && ns >= 0) {
			if (ns == end) return time + 1;
			if (visited[ns] == false)
			{
				visited[ns] = true;
				route.push(ns);
				timeQue.push(time + 1);
			}

		}
		
	}
	
	
}

int main()
{
	int N, K;

	cin >> N >> K;
	
	cout << BFS(N, K);
	//return 0;
}
