#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	char key;
	int value;
} BLOCK;

BLOCK *board;

int main()
{
	board = new BLOCK[2];

	for (int i = 0; i < 2; ++i)
	{
		board[i].key = 97+i;
		board[i].value = i + 1;
	}

	for (int i = 0; i < 2; ++i)
	{
		cout << board[i].key << ' ' << board[i].value << '\n';
	}

	swap(board[0], board[1]);
	for (int i = 0; i < 2; ++i)
	{
		cout << board[i].key << ' ' << board[i].value << '\n';
	}

}
