//제목 : 블랙잭
//목적 : 입력이 오름차순으로 들어오므로 뒤에서부터 탐색?!
//조건 : 카드는 최대 100장, 카드의 합은 최대 30만, 

/*아이디어 : 그냥 조합 쓰면 됨 ㅋㅋㅋㅋㅋ*/

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