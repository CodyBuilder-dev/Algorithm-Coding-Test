#include <iostream>

#define MAX_LEN 1000000

using namespace std;

int find_max(int* array, int startindex) {
	int max = array[startindex];
	//int max = array[0]; 이것이 바로 오답 원인
	int i = startindex;
	while (array[i] != -1) {
		if (max < array[i]) max = array[i];
		i++;
	}
	return max;
}

int main()
{
	int T;
	int N;

	int maxidx;
	int max;
	long long sum;
	int idx;
	//int array[1000001];으로 해도 상관없을듯?
	int *array;
	scanf("%d", &T);

	for (int i = 1; i < T + 1; i++)
	{

		scanf("%d", &N);

		idx = 0;
		sum = 0;

		array = new int[1000001];
		//for (int j = 0; j < N; j++) cin >> array[j]; 로도 가능할듯
		for (int j = 0; j < N; j++) scanf("%d", &array[j]);
		array[N] = -1;

		max = find_max(array, 0);

		while (array[idx] != -1)
		{
			if (array[idx] == max)
			{
				if (array[idx + 1] != -1)
				{
					max = find_max(array, idx + 1);
					idx++;
				}
				else break;
			}
			else
			{
				sum += (max - array[idx]);
				idx++;
			}
		}

		printf("#%d %lld\n", i, sum);


	}
}
