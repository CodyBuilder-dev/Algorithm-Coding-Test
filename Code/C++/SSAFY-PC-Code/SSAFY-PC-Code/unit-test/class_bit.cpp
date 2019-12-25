#include <iostream>

using namespace std;

void Bbit_print(char i)
{
	int j;
	for (j = 31; j >= 0; j--) {
		
		putchar((i & (1 << j)) ? '1' : '0');
		if (j % 8 == 0) putchar(' ');
	}
	putchar(' ');

}

int main(void)
{
	char i;
	
	for (i = -5; i < 6; i++) {
		printf("%3d =", i);
		Bbit_print(i);
		putchar('\n');
	}
}