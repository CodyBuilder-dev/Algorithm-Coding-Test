//���� : �ý� ������
//���� : ���ο� ������ ������ �̿��� ���� ����� �� �ִ°�
//���� : ������ R�� 10^4 ���� ������ 10^-4���� ���

//��Ŭ���� ������ ������ = piR^2
//�ý� �������� ���� �������̴�. 

/*���� : 
1. ���е��� ���� �ƴ°�
2. pi����� ���� �ƴ°�.
3. root(2) ���� ���� �� �ƴ°�.
*/

//������ : �� Ʋ������?

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int R;

	setprecision(10);
	cin >> R;
	
	cout << M_PI * R * R << '\n';
	cout << 2 * R * R<<'\n';
	
}