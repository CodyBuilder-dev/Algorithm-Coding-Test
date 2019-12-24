//���� : ���ã��
//���� : �׷����� ��������� �־����� ��, �̸� �ؼ��Ͽ� ���ϴ� ��ΰ� �ִ��� ã�� ����

//���� : ���������� 100��, �� ��������� 100x100. ��µ� ������� �������� ����ؾ� �Կ� ����

/*���̵��-DFS2
1. �׳� DFS �ܼ��ϰ� ����
2. �������� visited�� �˻���
3. �˻��ؼ� üũ�� ����� �ٳ�Դٴ� ���̹Ƿ� 1�� ���ָ� ��;
*/

/*������
1.Ž���� ���Ի��� ���ÿ� �ؾߵǴ� ���, �� �̋����� ��� ��θ� �� Ȯ���ؾ� �Ǵ� ����
���ú��� ���Ͱ� ����.
2. DFS�� ���� ��, visited�� �˻��ϸ� ����׷����� ����׷������� ���� ������� �ʰ�
���������� ����� ���赵 �ľ��� �� �ִ�.(�׷��������� DFS �Ϸ�!)
->�̸� �ٸ������� ���밡���ҵ�
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
int **graph;
int **resultGraph;
bool *routecheck;

void search_route(int start, int end) //start���� end������ ��� �ľ�
{
	/*Ż������ ���� ���� �ְ� �����ϰ� © �ʿ䰡 ����
	�׳� ���� DFSó�� ���� ��
	*/
	for (int i = 0; i < N; ++i) {
		if (routecheck[i] == false && graph[start][i] == 1) {
				routecheck[i] = true;
				search_route(i, end);
		}
	}
}
bool check_path(int end)
{
	if (routecheck[end] == false) return false; //DFS��� end�� ���������� true, ���� �������� false
	else true;//return �� ��� ����;;;
}

int main()
{
	cin >> N;

	graph = new int*[N];
	resultGraph = new int*[N];
	routecheck = new bool[N](); //���� ���� �������� �ִ°� üũ
	for (int i = 0; i < N; ++i) {
		graph[i] = new int[N]();
		resultGraph[i] = new int[N](); 
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> graph[i][j];

	//������� �������� �ڵ� �ۼ� ����
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			
			search_route(i, j);
			
			if(check_path(j) == true) 
				resultGraph[i][j] = 1;
			//if(routecheck[j] == true) <-����
				//resultGraph[i][j] = 1;
			else resultGraph[i][j] = 0; <����
			for (int k = 0; k < N; ++k)
				routecheck[k] = false;
			
		}

	//cout << '\n';

	//��� ��� ���
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << resultGraph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}


