#include <iostream>

using namespace std;
//�����Ҵ��� �����Ҵ纸�� �׻� ���� ���� �ƴ϶�� ����
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
