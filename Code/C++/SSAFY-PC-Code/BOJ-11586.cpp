//���� : ���� ���ִ��� ���� �ſ�
//���� : �ſ��� �ɸ����¿� ���� ���ִ��� ���¸� �ٸ��� ǥ���϶�
//���� : �ɸ����´� 3����, �ſ��� ũ��� �ִ� 100x100

/*���̵�� : 2�������� ������ ���ڿ��� ó���ϴ� �˰��� ¥��
1. Vector of strings
2. char array
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N, K;
	vector<string> board;
	
	cin >> N;

	for (int i = 1 ; i <= N; ++i)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	cin >> K;

	switch (K) {
	case 1: 
		break;
	case 2:
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N / 2; ++j)
				swap(board[i][j], board[i][N - 1 - j]);
		break;
	case 3:
		for (int i = 0; i < N / 2; ++i)
			swap(board[i], board[N - 1 - i]);
		break;
	}

	for (int i = 0; i < N; ++i)
		cout << board[i] << '\n';
}