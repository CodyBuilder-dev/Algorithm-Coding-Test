#include <iostream>

using namespace std;

//배열의 최대값 찾아서 해당 인자 반환
int find_maxidx(int* array, int startindex) {
	int max = array[startindex];
	int i = startindex;
	int maxidx = 0;
	while (array[i] != 0) {
		if (max < array[i]) {
			max = array[i];
			maxidx = i;
		}
		i++;
	}

	return maxidx;
}

int find_max(int* array, int startindex) {
	int max = array[startindex];
	int i = startindex;
	while (array[i] != 0) {
		if (max < array[i]) max = array[i];
		i++;
	}
	return max;
}
//이거 stack이 1mb라 재귀를 못 쓰게 해놓은듯
long long find_sum(int* array, int start) {
	int max;
	int endindex;
	max = find_max(array, start);
	endindex = find_maxidx(array, start);

	if (array[start] == 0) return 0;
	return (max - array[start]) + find_sum(array, start + 1);
}
int main() {
	int T;
	int N;

	int maxidx;
	int max;
	long long sum;


	cin >> T;
	for (int i = 1; i < T + 1; i++)
	{

		cin >> N;

		int *array = new int[N + 1];

		sum = 0;
		for (int j = 0; j < N; j++) cin >> array[j];
		array[N] = 0;

		sum = find_sum(array, 0);

		cout << "#" << i << " " << sum << '\n';




	}
}