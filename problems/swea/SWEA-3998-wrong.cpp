//제목 : Inversion Counting
//목적 : i<j 일때 Ai>Aj인 Inversion의 개수를 구하여라
/*조건 : 순열 길이는 최대 10^5*/

/*아이디어 : 브루트 포스
1. 첫번째부터 끝까지 다 탐색하면 O(N^2)이므로 펑
*/

//결과 : 아니나 다를까 시간초과~

#include <iostream>

using namespace std;

int T;
int N;
int list[200000];
int inversion;

void input()
{
	//fill_n 동작 잘 하구용~
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
