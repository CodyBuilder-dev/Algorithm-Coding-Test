#include <iostream>
#include <math.h>
using namespace std;

//파싱 하라 이거네

int main() {
	unsigned char c[71] = "0000000111100000011000000111100110000110000111100111100111111001100111";
	int sum = 0;
	int j;

	for (int i = 0; i < 71; i++) {
		j = i % 7;

		if (j == 0) sum = 0;
		
		if (c[i] == '1') sum += pow(2, 6 - j)*1;
		else sum += pow(2, 6 - j)*0;
		
		if (j == 6) cout << sum << " ";
	}

}