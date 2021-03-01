//제목 : 숫자의 합
//목적 : 숫자의 메모리 저장 형태를 이해하고 있는가
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string str;
	int sum=0;

	cin >> N;
	cin >> str;
	
	for (int i = 0; i < N; i++)
		sum += str[i]-'0';
	cout << sum;
	return 0;
}