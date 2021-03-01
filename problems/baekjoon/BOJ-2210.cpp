//제목 : 숫자판 점프
//목적 : 숫자판에서 임의로 이동하면서, 만들 수 있는 모든 숫자 만들기
//조건 : 숫자판의 크기는 5x5

/*아이디어 : DFS로 풀면 간단. 백 트래킹은 어떻게 넣지?
*/

/*구현 : 
1. DFS를 하되, 다음 호출에 들고가고 싶은 정보(예를들면 현재 문자열, 현재 길이)
DFS 함수의 인자로 넣어줘서 들고갈 수 있음
2. 숫자의 배열은, (과거숫자*10)+현재숫자 로 만들 수 있음
2. SET을 이용하여 중복되는 것이 없도록 함
*/

//느낀점 : str
#include <iostream>
#include <string>
#include <set>

using namespace std;

char board[5][5];

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

set<int> numSet;
set<string> strSet;

void dfs(int y, int x, string str, int length)
{
	/*
	1. (굳이 도착해서 문자열을 늘릴 필요 없이. dfs에 늘린 채로 전달해도 됨)
	2. length가 5이면 set에 넣고 리턴
	3. length가 5 미만이면 for문 돌려서 한번 더 들어가기
	4. str로 한다면 : 
	-일단 문자열의 원소만 같으면 같은 것으로 판정은 해줌.
	-그러나 int로 할때에 비해 훨씬 느림
	*/

	if (length == 5) {
		strSet.insert(str);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i]; int ny = y + dy[i];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
			string newStr = str;
			newStr.push_back(board[ny][nx]);
			dfs(ny, nx, newStr, length + 1);
		}
	}

}

int main()
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> board[i][j];

	/*
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cout << board[i][j];
	*/
	
	for(int i = 0; i<5; ++i)
		for (int j = 0; j < 5; ++j) {
			string str;
			str.push_back(board[i][j]);
			dfs(i, j, str, 0);
		}

	cout << strSet.size();
			
}
