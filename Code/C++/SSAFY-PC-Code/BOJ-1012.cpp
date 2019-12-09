//���� : ����� ����
//���� : ���� �� ������ ���빮��

/*����
1. �������� ���ɸ� ����ؾ� �Ѵ�
2. ���߰� �迭�� �־����� �ʰ� ������ Ʃ�÷� �־�����.
*/

/*
���̵�� : DFS�� ���� �ſ� ���ϴ�.
*/

/*
����� : 
1.�������� �Ǵµ� ��Ÿ���̶��? �޸� Ȯ�� ����
2.���迡���� ���α׷� ��ü ������ ��ġ�� ���� ����, �����Ǵ� �κи� ��¦ �ļ��� �ٲ㵵 ������
3.2���� �迭�� ���� ���μ��� Ȯ�� �ȹٷ� �� ��. ���α���=/=���α��� �� ��� for�̳� if �ȹٷ� ������ ��
4. ó���� ���� ���ǹ��� Ȯ���� �ڵ�� �ּ����� ����ϰ� �ڵ��� ��
*/

#include <iostream>
#include <algorithm>

using namespace std;

int T;
int M, N, K;

int **farm;
int **visited;

int warm_cnt = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs_check;

void DFS(int y, int x)
{
	/*��������
	1. �� ������ ������ ������ ����
	2. farm == 1�ε� �̹� �湮�� ��
	3. farm == 0�ΰ�
	*/
	
	if ((x >= M) || (y >= N) || (x < 0) || (y < 0)) return;
	if (farm[y][x] != 1) return;
	if (visited[y][x] != 0) return;

	visited[y][x] = 1;

	for (int ii = 0; ii < 4; ++ii) {
		DFS(y + dy[ii],x + dx[ii]);
	}
	dfs_check = 1;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)//���� ��ŸƮ
	{
		cin >> M >> N >> K;


		farm = new int*[N]; //�� �迭 ����
		for (int j = 0; j < N; ++j)
			farm[j] = new int[M]();

		visited = new int*[N]; //�湮üũ �迭 ����
		for (int j = 0; j < N; ++j)
			visited[j] = new int[M]();

		int tempx, tempy; //���� �迭�� ���� �ɱ�
		for (int j = 1; j <= K; ++j) {
			cin >> tempx >> tempy;
				farm[tempy][tempx] = 1;
		}

		/*
		for (int j = 0; j < N; ++j) { //���� �迭 Ȯ��
			for (int k = 0; k < M; ++k)
				cout << farm[j][k];
			cout << '\n';
		}
		*/
		
			
				
		
		//������� ���� �ڵ� ����

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if(farm[j][k] == 1 && visited[j][k]==0){ //���� ���Թ��� ���� �̻���. ���Ǵ�� �� ��
						DFS(j, k);
						//if(dfs_check == 1)
						warm_cnt += 1;
						dfs_check = 0;
					
				}
			}
		}

		/*
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k)
				cout << visited[j][k];
			cout << '\n';
		}
		
		*/

		//���� �װ� �����Ƿ� �޸� �ʱ�ȭ ����� ��
		
		for (int j = 0; j < N; ++j)
			delete[] farm[j];
		delete[] farm;

		for (int j = 0; j < N; ++j)
			delete[] visited[j];
		delete[] visited;

		//���������� ���� ������ �ʱ�ȭ����� ��
		printf("%d\n", warm_cnt);
		warm_cnt = 0;
	}

	return 0;
}

