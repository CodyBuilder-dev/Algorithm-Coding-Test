//���� : Inversion Counting
//���� : i<j �϶� Ai>Aj�� Inversion�� ������ ���Ͽ���
/*���� : ���� ���̴� �ִ� 10^5*/

/*���̵�� : ���Ʈ ����
1. ù��°���� ������ �� Ž���ϸ� O(N^2)�̹Ƿ� ��
*/

//��� : �ƴϳ� �ٸ��� �ð��ʰ�~

#include <iostream>

using namespace std;

int T;
int N;
int list[200000];
int inversion;

void input()
{
	//fill_n ���� �� �ϱ���~
	fill_n(list, 200000, 0);
	inversion = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> list[i];
}

void find_inversion_brute()
{
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N; ++j) {
			if (list[i] > list[j]) inversion++;
		}
	}
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		
		find_inversion_brute();

		cout << '#' << i << ' ' << inversion << '\n';
		

	}
}
