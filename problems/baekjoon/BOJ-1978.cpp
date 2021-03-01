#include <iostream>

using namespace std;

//소수 범위는 1000이하, 테케는 100개 이하
// 즉 소수 1000이하 배열을 미리 만들어 놓으면 됨


int main()
{
	int* n_array;
	int* p_array;

	int N;

	int cnt = 0;
	int index;

	cin >> N;
	n_array = new int[N];
	for (int i = 0; i < N; i++) cin >> n_array[i];

	p_array = new int[1001]();

	for (int i = 1000; i >= 2; i--)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				p_array[i] = 1;
				break;
			}

		}
	}
	p_array[1] = 1;
	for (int i = 0; i < N; i++)
	{
		//index = n_array[i];
		//if (p_array[index] == 0) cnt++;
		if (p_array[n_array[i]] == 0) cnt++;
	}
	cout << cnt;
}