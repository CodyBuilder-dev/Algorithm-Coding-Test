#include <iostream>

#define MAX_NUM 1000000

using namespace std;
//���ɰ� 100�����̹Ƿ� 100������ �Ҵ��ؼ� ������ �Ϸ����� �ɸ�

int arr_max(int* arr,int len) {
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
	int input[MAX_NUM];
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	cout << arr_min(input,N) <<" " << arr_max(input,N);
}
