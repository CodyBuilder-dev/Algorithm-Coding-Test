#include <iostream>
int main() {
	int n = 0x00111111;
	char *c = (char *)&n;

	if (c[0])
		printf("little endian");
	else
		printf("big endian");
}