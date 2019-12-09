#include <stdio.h>
#include 
#include <string.h>
using namespace std;
int a[26] =
{ 2, 2, 2, 3, 3, 3,
4, 4, 4, 5, 5, 5,
6, 6, 6, 7, 7, 7, 7,
8, 8, 8, 9, 9, 9, 9
};
int required[26] =
{ 1, 2, 3, 1, 2, 3,
1, 2, 3, 1, 2, 3,
1, 2, 3, 1, 2, 3, 4,
1, 2, 3, 1, 2, 3, 4
};
char input[1002];
int main()
{
	int p, w;
	cin >> p >> w;
	getchar();
	fgets(input, 1002, stdin);


출처: https://gaelim.xyz/246 [못해요, 코딩]