//���� : 2007��
//���� : 2007���� Ư������ ������ �˾Ƴ��� ���α׷��� �ۼ�
//���� : Switch case���� ����� �� �ƴ°�

/* ���̵�� :
in �޾Ƽ� switch�� day ���
day �޾Ƽ� 7�γ����� ���� �ֱ� ����
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

