//제목 : 2007년
//목적 : 2007년의 특정일의 요일을 알아내는 프로그램을 작성
//목적 : Switch case문을 사용할 줄 아는가

/* 아이디어 :
in 받아서 switch로 day 계산
day 받아서 7로나누면 요일 주기 나옴
*/
#include <iostream>

using namespace std;

int days[] = { 31, 28, 31 , 30 , 31 ,30, 31,31 ,30,31,30,31 };

int main()
{
	int X, Y;
	
	cin >> X >> Y;
	int sum=0;
	for (int i = 0; i < X-1; ++i)
	{
		sum += days[i];
	}

	sum += Y;

	int date = sum % 7;
	switch (date)
	{
	case 1: cout << "MON";  break;
	case 2: cout << "TUE";  break;
	case 3: cout << "WED";  break;
	case 4: cout << "THU";  break;
	case 5: cout << "FRI";  break;
	case 6: cout << "SAT";  break;
	case 0: cout << "SUN";  break;
	}
}

