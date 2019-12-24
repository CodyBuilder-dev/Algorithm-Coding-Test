#include <iostream>

using namespace std;

//1. M~N까지의 소수를 다 알아야 함
//2. 즉, M에서부터 시작해서 2~M까지의 모두를 나눠봐야 함
//3. 그래도 살아있는 놈을 소수로 임명한다.

//자료구조 : 최적화시키려면 내가보기에 맵을 잘 써야 한다.

int main()
{
	int* p_array;

	int M, N;


	cin >> M >> N;
	//M<N이 맞춰서 올거라고 가정	

	p_array = new int[10001]();

	
	for (int i = M; i <= N; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				p_array[i] = 1; //
				break;
			}

		}
	}
	p_array[1] = 1;


	int sum = 0;
	int cnt = 0;
	int first;
	for (int i = M; i <= N; i++)
	{
		
		if (p_array[i] == 0)
		{
			if (cnt == 0) first = i;
			sum += i;
			cnt++; //약간 어거지로 첫번째 소수 찾기
		}
		

	}
	if (cnt != 0) cout << sum <<'\n'<<first;
	else cout << -1 << '\n';
}