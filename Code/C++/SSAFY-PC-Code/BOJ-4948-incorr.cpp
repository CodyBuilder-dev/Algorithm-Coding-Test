//제목 : 베르트랑 공준
//아이디어 : 소수의 개수를 구해야 하므로 cnt를 해야할듯
//소수는 어떻게 구하느냐? 그냥 앞에서 썼던 알고리즘 쓰면 안됨?
//n<=123456이므로 for문 10만번이면 할만하지 않나?
//실제로 돌려보면 시간초과 나옴. 다른 방법을 찾아야 함
#include <iostream>

using namespace std;

int main()
{
	int* p_array;
	int N;
	int cnt;

	while (1) {
		cin >> N;
		
		if (N == 0) break;
		
		cnt = 0;
		p_array = new int[123457]();
		
		for (int i = N + 1; i <= 2 * N; i++)
		{
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					p_array[i] = 1; //소수가 아니면 1로 표시
					break;
				}

			}
		}
		p_array[1] = 1;

	
		for (int i = N + 1; i <= 2 * N; i++)
		{

			if (p_array[i] == 0) cnt++; //소수 개수 찾기

		}
		cout << cnt << '\n';
	}
}