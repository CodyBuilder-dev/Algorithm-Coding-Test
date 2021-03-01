//���� : ������ ����
//���� : �����ǿ��� ���Ƿ� �̵��ϸ鼭, ���� �� �ִ� ��� ���� �����
//���� : �������� ũ��� 5x5

/*���̵�� : DFS�� Ǯ�� ����. �� Ʈ��ŷ�� ��� ����?
*/

/*���� : 
1. DFS�� �ϵ�, ���� ȣ�⿡ ����� ���� ����(������� ���� ���ڿ�, ���� ����)
DFS �Լ��� ���ڷ� �־��༭ ��� �� ����
2. ������ �迭��, (���ż���*10)+������� �� ���� �� ����
2. SET�� �̿��Ͽ� �ߺ��Ǵ� ���� ������ ��
*/

//������ : str
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
	1. (���� �����ؼ� ���ڿ��� �ø� �ʿ� ����. dfs�� �ø� ä�� �����ص� ��)
	2. length�� 5�̸� set�� �ְ� ����
	3. length�� 5 �̸��̸� for�� ������ �ѹ� �� ����
	4. str�� �Ѵٸ� : 
	-�ϴ� ���ڿ��� ���Ҹ� ������ ���� ������ ������ ����.
	-�׷��� int�� �Ҷ��� ���� �ξ� ����
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
