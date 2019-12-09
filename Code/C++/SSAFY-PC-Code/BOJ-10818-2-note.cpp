#include <iostream>

using namespace std;
//동적할당이 정적할당보다 항상 좋은 것은 아니라는 예시
int arr_max(int* arr, int len) {
	int max;
	max = arr[0];
	for (int i = 0; i < len; i++) {
		if (max < arr[i]) max = arr[i];
	}

	return max;
}

int arr_min(int* arr, int len) {
	int min;
	min = arr[0];
	for (int i = 0; i < len; i++) {
		if (min > arr[i]) min = arr[i];
	}

	return min;
}

int main() {
	int N;
	

	cin >> N;
	int* input = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	cout << arr_min(input, N) << " " << arr_max(input, N);
}
