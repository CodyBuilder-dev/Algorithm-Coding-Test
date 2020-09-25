//제목 : 경사로
//목적 : 직선으로 이루어진 모든 길의 개수를 찾되, 경사로를 이용할 수 잇음
//조건 : (문제 본문 참조). 크기 최대 100x100, 경사로 길이 L은 최대 100
//유형 : 시뮬레이션, 완전 탐색

/*아이디어 : 
1. 브루트포스로, 각 2차원배열의 원소를 다 검사하면서 진행
2. 경사로 행렬을 따로 만들어서 경사로가 이미 놓여있는지 체크
3. 방향이 일방향이므로 DFS까진 필요없음
*/

/*구현 : 조건이 많으므로, 꼼꼼히 따져야 함
1. 높이가 같을 경우 진행
2. 높이가 달라질 경우. 올라가는지 내려가는지 검사
3. 올라갈 경우- 차이가 1인지 2인지 검사
3. 차이가 1인 경우, 그때부터 1이 몇개 지속되는지 검사
4. 몇개 지속되는 경우, 경사로를 놓고
5. 
*/

/*구현2 : 오르는 경사로, 내리는 경사로 함수 구현
1. 오르는 경사로는, 현재위치의 뒷부분 경사로 유무 검사
1. 되는 경우
1.1 L만큼 높이가 동일
1.2 설치되지 않았어야 함
2. 안되는 경우
2.1 높이가 같지 않을 경우
2.2 이미 설치가 된 경우
2.3 판 밖으로 벗어나는 경우

2. 내리는 경사로는, 현재위치 앞부분 경사로 유무 검사
*/


//느낀점 :2중 if문으로 else if 아래에 if를 쓴다면, else if{} 반드시 중괄호를 넣어줘야 함
//->진짜 논리적으로는 문제 하나도 없는데 치명적으로 오작동하므로 매우 주의


#include <iostream>

using namespace std;

int N, L;

int **board;
bool **installed;

int first;
bool horizen;


//나머지 다 검사했음. 이제 upper lower만 검사하면 됨
//안되는 모든 경우 다 체크 해야함

bool upper_dir(int y, int x) //오르막 경사로 설치가능 체크 함수
{
	//안되는 모든 경우에 대해 return false, 되면 true
	//return을 중간에 해버리지 말고 마지막에 하기
	int check = 0;
	if (horizen == true){ //가로 길 체크하는 경우
		if (x - L < 0) return false;
		for (int i = x - L; i < x; ++i){
			if (board[y][i] != first) check = 0;
			else if (installed[y][i] == true) check = 0;
			else check++;
		}

		if (check == L) {  //안되는 모든 경우를 통과하면
			for (int i = x - L; i < x; ++i)
				installed[y][i] = true;
			first = first+1;
			return true;
		}
		else return false;
	}
	else { //세로 길 체크하는 경우
		if (y - L < 0) return false;
		for (int i = y - L; i < y; ++i) {
			if (board[i][x] != first) check = 0;
			else if (installed[i][x] == true) check = 0;
			else check++;
		}
		if (check == L) {
			for (int i = y - L; i < y; ++i)
				installed[i][x] = true;
			first = first+1;
			return true;
		}
		else return false;
	}
}
//lower일때 제대로 검사 안됨, 안 내려감
bool lower_dir(int y,int x) //내리막 경사로 설치가능 체크 함수
{
	//안되는 모든 경우를 체크한 후 없으면 return true
	int check = 0;
	if (horizen == true) { //가로 길 체크하는 경우
		if (x + L > N) return false;
		for (int i = x; i < x+L; ++i) {
			if (board[y][i] != first-1) check = 0;
			else if (installed[y][i] == true) check = 0;
			else check++;
		}
		
		if (check == L) {
			for (int i = x; i < x+L; ++i)
				installed[y][i] = true;
			first = first-1;
			return true;
		}
		else return false;
	}
	else { //세로 길 체크하는 경우
		if (y + L > N) return false;
		for (int i = y; i < y+L; ++i) {
			if (board[i][x] != first-1) check = 0;
			else if (installed[i][x] == true) check = 0;
			else check++;
		}
		if (check == L) {
			for (int i = y; i < y+L; ++i)
				installed[i][x] = true;
			first = first -1;
			return true;
		}
		else return false;
	}
}

int main()
{
	cin >> N >> L;

	board = new int*[N];
	installed = new bool*[N];
	for (int i = 0; i < N; ++i)
	{
		board[i] = new int[N]();
		installed[i] = new bool[N]();
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	//여기서부터 본격적인 코딩 시작
	bool okay;
	int total = 0;
	for (int i = 0; i < N; ++i) {//가로 길 검사
		horizen = true;
		okay = true;
		first = board[i][0];
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] > first + 1 || board[i][j] < first - 1)
			{
				
				okay = false;
				break;
			}
			else if (board[i][j] == first + 1){
				if (!upper_dir(i, j)) { //오르막길 검사후 만약 거짓이면
				
					okay = false;
					break;
				}
			}
			else if (board[i][j] == first - 1){ //<- 중괄호 때매 거짓
				if(!lower_dir(i,j)){ //내리막길 검사후 거짓이면
					
					okay = false;
					break;
				}
			}
			
		}
		if (okay == true)
			total++;
	
	}

	//installed 초기화 한번 해주기
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			installed[i][j] = false;

	for (int j = 0; j < N; ++j) {//세로 길 검사
		horizen = false;
		okay = true;
		first = board[0][j];
		for (int i = 0; i < N; ++i)
		{
			if (board[i][j] > first + 1 || board[i][j] < first - 1)
			{
				
				okay = false;
				break;
			}
		else if (board[i][j] == first + 1) {
			if (!upper_dir(i, j)) {
				
				okay = false;
				break;
			}
		}
		else if (board[i][j] == first - 1) {
			if (!lower_dir(i, j)) {
				
				okay = false;
				break;
			}
		}
		}

		if (okay == true) total++;
		
	}

	cout << total;
}

