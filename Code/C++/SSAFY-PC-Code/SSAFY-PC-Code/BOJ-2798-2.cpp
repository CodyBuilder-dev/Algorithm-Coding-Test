//���� : ����
//���� : �Է��� ������������ �����Ƿ� �ڿ������� Ž��?!
//���� : ī��� �ִ� 100��, ī���� ���� �ִ� 30��, 

/*���̵�� : �׳� ���� ���� �� ����������*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int* cards;
bool* choice;

int main()
{
	cin >> N >> M;
	
	cards = new int[N];
	choice = new bool[N]();

	for (int i = 0; i < N; ++i)
		cin >> cards[i];
	
	for (int i = 0; i < 3; ++i)
		choice[i] = true;

	sort(choice, choice + N);

	//for (int i = 0; i < N; ++i)
	//	cout << choice[i];

	int max = -987654321;
	do {
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (choice[i] == true) sum += cards[i];
		if (sum > max && sum <=M) max = sum;
	} while (next_permutation(choice, choice + N));

	cout << max;

}