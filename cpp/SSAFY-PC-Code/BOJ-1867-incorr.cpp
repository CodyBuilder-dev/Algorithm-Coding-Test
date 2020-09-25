//���� : ������ ����
//���� : ��忡 �ִ� �����̸� �ּ����� ���������� �����ϱ�
//���� : ����� �ִ� 500x500, �����̴� �ִ� 10000��

/*���̵�� :
�ּҷ� �����̷���, ���� ���� ���� ��/���� �δ�
(=�׸��� �˰���)
1. ����� ��� ���� ���� ���� check�ϴ� �迭 ����
2. ���� ���� ��/���� ����
3. ��� ���� ����
4. �ݺ�
*/

//���� : ��/���� �ִ� �ε����� y-1,x-1�ӿ� ����

/*������ :
1. �׸���� �ذ� ��ü�� �ȵǴ� ������ ����
2. �׷� �׸���� Ǯ������ ��Ǯ������ ������ ���?
3. �׸��� ����, �ٸ� ���ٹ��� �����?
*/
#include <iostream>
#include <utility>

using namespace std;

int N, K;
int* rowCheck, * colCheck;
pair<int, int> maxRow, maxCol;
bool** board;

int find_maxidx(int* array)
{
	int max = -123123123;
	int maxidx;
	for (int i = 0; i < N; ++i)
	{
		if (array[i] >= max) {
			max = array[i];
			maxidx = i;
		}
	}
	return maxidx;
}

int find_max(int* array)
{
	int max = -123123123;
	int maxidx;
	for (int i = 0; i < N; ++i)
	{
		if (array[i] >= max) {
			max = array[i];
			maxidx = i;
		}
	}
	return max;
}

int main() {

	cin >> N >> K;

	board = new bool*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new bool[N]();

	rowCheck = new int[N]();
	colCheck = new int[N]();

	for (int i = 0; i < K; ++i)
	{
		int y, x;
		cin >> y >> x;
		rowCheck[y - 1]++; colCheck[x - 1]++;
		board[y - 1][x - 1] = true;
	}


	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) 
			printf("%d ", board[i][j]);
		cout << '\n';
		}
		
	//���⼭���� �������� �ڵ� ����

	int cnt = 0;
	
	while (true) //��� ���� �� ������������ check
	{
		/*
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j)
				printf("%d ", board[i][j]);
			cout << '\n';
		}
		*/

		maxRow.first = find_maxidx(rowCheck);
		maxRow.second = find_max(rowCheck);
		maxCol.first = find_maxidx(colCheck);
		maxCol.second = find_max(colCheck);
		
		if (maxRow.second == 0 || maxCol.second == 0)
			break;

		if (maxRow.second >= maxCol.second){
			for (int i = 0; i < N; ++i)
			{
				if (board[maxRow.first][i] == true)
				{
					rowCheck[maxRow.first]--;
					colCheck[i]--;
					board[maxRow.first][i] = false;
				}
			}
		}
		
		else {
			for (int i = 0; i < N; ++i)
			{
				if (board[i][maxCol.first] == true)
				{
					colCheck[maxCol.first]--;
					rowCheck[i]--;
					board[i][maxCol.first] = false;
				}
			}
		}
		cnt++;
	}
	
	cout << cnt;
	return 0;
}