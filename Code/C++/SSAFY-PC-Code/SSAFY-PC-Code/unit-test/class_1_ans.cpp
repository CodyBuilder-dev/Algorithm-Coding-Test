#include <stdio.h>

int main() {

	int a, b, c;
	char str[5][11];

	scanf("%d", &a);
	scanf("%d %d", &b,&c);

	for (int i = 0; i < 5; i++) {
		scanf("%s", str[i]);
	}

	printf("%d\n%d %d\n", a, b, c);


}