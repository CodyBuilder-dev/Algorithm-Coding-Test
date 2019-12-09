#include <iostream>

//颇况 流立 备泅
int my_power_2(int a) {
	int res = 1;
	for (; a > 0; a--) res *= 2;
	return res;
}

//a to i 流立 泅
int my_atoi_7(char *a) {
	int res = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i] == '1') res += my_power_2((7 - i) - 1);
	}
	return res;
}

int main() {
	char tmp[10][7];
	unsigned char arr[71] = 
		"0000000111100000011000000111100110000110000111100111100111111001100111";
	for(int j =0;j<10;j++)

}
