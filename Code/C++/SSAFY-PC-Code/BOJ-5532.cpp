//���� : ���� ����
//���� : �Ϸ翡 �����ϴ� ���� ������ ���� ���, ��� �ִ� ���� ��
//(���꿡�� �������� ����� ��� �� ó���� �� �ִ°�?)

/*���̵�� : ����� A/C�� �ʿ�. ������ B/D�� �ʿ�
������ ���ߴµ� ��� ���� ��� ���� �����Ƿ�, �ִ����� ���
������ 1�������� ���������� �� ���������� ���
*/

#include <iostream>

using namespace std;

int main()
{
	int L;
	int A, B, C, D;

	cin >> L >> A >> B >> C >> D;

	int koreanDay;
	if (A%C == 0) koreanDay = A / C;
	else koreanDay = A / C + 1;

	int mathDay;
	if (B%D == 0) mathDay = B / D;
	else mathDay = B/ D + 1;

	int totalDay = (koreanDay > mathDay) ? L - koreanDay : L - mathDay;

	cout << totalDay;
}