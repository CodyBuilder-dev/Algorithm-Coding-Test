//���� : ���������� ����
//���� : ����� �ſ��� ������ �ִ� ���������� �������� ��� �������� ��ǥ

//���� : ����! ��� ���� �ݴ�� �����. ������ ¥������ ��Ǯ����

//�� : ����, �� : ���� 

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N, r;
	int x, y;

	bool **board;

	cin >> T;

	for (int i = 1; i<=T;++i){
		cin >> N >> r;

		board = new bool*[N];
		for (int j = 0; j<N;++j)
			board[j] = new bool[N];

		for (int j = 0; j < r; ++j)
		{
			cin >> x >> y
		}
		cin >> x >> y; //������ ��ǥ
	}
}