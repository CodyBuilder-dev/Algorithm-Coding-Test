//제목 : 돌맹이 제거
//목적 : 운동장에 있는 돌맹이를 최소한의 움직임으로 제거하기
//조건 : 운동장은 최대 500x500, 돌맹이는 최대 10000개

/*아이디어 :
최소로 움직이려면, 가장 많이 놓인 행/열을 민다
(=그리디 알고리즘)
1. 운동장의 행과 열에 놓인 돌을 check하는 배열 생성
2. 가장 많은 행/열의 제거
3. 운동장 형태 갱신
4. 반복
*/

//구현 : 행/열의 최대 인덱스는 y-1,x-1임에 주의

/*문제점 :
1. 그리디로 해결 자체가 안되는 문제임 ㅋㅋ
2. 그럼 그리디로 풀리는지 안풀리는지 검증은 어떻게?
3. 그리디 말고, 다른 접근법은 뭘까요?
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
		
	//여기서부터 본격적인 코딩 시작

	int cnt = 0;
	
	while (true) //모든 돌이 다 없어질때까지 check
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