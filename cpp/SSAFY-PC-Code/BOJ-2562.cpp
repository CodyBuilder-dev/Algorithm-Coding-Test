#include <iostream>

using namespace std;
/*
쭉 받고 나서 돌리기 vs 받으면서 돌리기
*/
//배열ㅇ
int* find_max(int* arr) {
	int max_arr[2] = { 0,0 };
	for (int i =0; i<9;i++)
		if (arr[i] > max_arr[0]) {
			max_arr[0] = arr[i];
			max_arr[1] = i+1;
		}
	return max_arr;
}
int main()
{
	int input[9];
	int* answer;
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
	}

	answer = find_max(input);
	cout << answer[0] << '\n' << answer[1];
}