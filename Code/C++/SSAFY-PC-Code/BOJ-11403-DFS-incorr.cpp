//���� : ���ã��
//���� : �׷����� ��������� �־����� ��, �̸� �ؼ��Ͽ� ���ϴ� ��ΰ� �ִ��� ã�� ����

//���� : ���������� 100��, �� ��������� 100x100. ��µ� ������� �������� ����ؾ� �Կ� ����

/*���̵��-DFS : ó������ �迭�� �ƴ϶� �׷��� Ž��
0. 0->1�� ���� ��θ� ã�µ�, 01230, 0124X�̶� ġ��
1. 0��° ���� �˻��Ѵ�
2. 1��° ���� �˻��Ѵ�. 0�̸� �Ѿ��. 1�̸� �ٷ� �ش翭 ���
3. 2��° �� �˻�. 0�̸� ���� �� �˻�, 1�̸� �ٷ� �ش翭 ���

4. 2��° �൵ 1��° �� �˻�. 1�̸� �Ѿ, 0�̸� �� �ݺ�..

5. ������� �� ���Ҵµ��� 1�� ���� ��ΰ� ����?! 0
6. 0->2, 0->3�� ���� ó������ ���ѹݺ�
(�ٵ� �̷� �ð��ʰ� �ɸ��Ű�����. �ϴ� �����ϰԶ� ���� ���)
*/

/*������
1.Ž���� ���Ի��� ���ÿ� �ؾߵǴ� ���, �� �̋����� ��� ��θ� �� Ȯ���ؾ� �Ǵ� ����
���ú��� ���Ͱ� ����.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
int **graph;
int **resultGraph;
int *routecheck;

vector<int> routestack;

void search_route(int start, int end) //start���� end������ ��� �ľ�
{
	/*Ż�������� ��Ȯ�ϰ� �����ؾ���
	1. ��ΰ� �߰ߵǾ��� ��
	2. ��ΰ� ���ٸ�, �ٸ� ��θ� ã���� ��
	3. �ٸ� ������� ���� ��
	*/
	//Ż������ 1. ��ΰ� �߰ߵ� ��� ���ݱ����� ��� route �� ����
	routecheck[start] = 1;
	routestack.push_back(start);

	if (graph[start][end] == 1 || resultGraph[start][end] == 1) {
		resultGraph[start][end] = 1;
		for (int i = 0; i < routestack.size(); ++i){
			int temp = routestack[i];
			resultGraph[temp][end] = 1;
		}
		routestack.pop_back();
		return;
	}
	//Ż������2. ��ΰ� ���ٸ� �Ȱ��� �ٸ� ��θ� ã�´�.
	else {
		
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (routecheck[i] == 0 && graph[start][i] == 1)
				sum+=1;
		if (sum != 0) {
			for (int i = 0; i < N; ++i) //start�κ��� �ٸ� �� ��� Ž��
			{
				if (routecheck[i] == 0 && graph[start][i] == 1)
					search_route(i, end);
			}
		}
		else { //Ż������3 : �ٸ� ��ΰ� ���� �ƹ��͵� ���� ��
			
			for (int i = 0; i < routestack.size(); ++i) {
				int temp = routestack[i];
				resultGraph[temp][end] = 0;
			}
			routestack.pop_back();
			return;
		}
	}

	
}

int main()
{
	cin >> N;

	graph = new int*[N];
	resultGraph = new int*[N];
	for (int i = 0; i < N; ++i){
		graph[i] = new int[N]();
		resultGraph[i] = new int[N]();
	}
	routecheck = new int[N](); //���� ���� �������� �ִ°� üũ
	

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];

	//������� �������� �ڵ� �ۼ� ����
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			search_route(i, j);
			for (int k = 0; k < N; ++k)
				routecheck[k] = 0;
		}
	
	//cout << '\n';
	
	//��� ��� ���
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			cout << resultGraph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}


