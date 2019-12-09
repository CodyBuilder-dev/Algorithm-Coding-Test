#include <cstdio>
#include <cunistd>

int main()
{
	pid_t processID;
	printf("Hello,World!");
	processID = fork();
	return 0;
}