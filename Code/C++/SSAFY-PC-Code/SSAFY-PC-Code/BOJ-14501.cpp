//���� : ���
//���� : ���ǥ�� ����, �����Ⱓ �� ������ �ִ�� �ǵ��� ��� ���
//���� : N<15�̹Ƿ�, �� �������� 2^15 = 32000����. O(NlogN)���� �Ҹ� ��

/*
���̵��1(���) : 
1. ���ں��� ���� �������� day���� ��Ʈ�� ������ day��Ʈ�� �����δ� 2^bit-1����
2. ��� ����� ���� ���� valid���� �� ������.(���Ʈ ����)
3. ���ǿ� �� ������ �Ÿ�.
4. ������ ��� �����ϸ� �׶� ���� ����
����� ������  �׳� ���� ������ �Ǵ� max�� �Ѵ�.
max���� ������ ������ max���� ũ�� ����ġ���.
*/

/*
������ : �迭���� Ư����ġ�� ���ҵ��� ���ÿ� �����ϴ°� �����
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> selected_day;
vector<int> selected_pay;
/*
char* int2bit(int day)
{
	char* daystring;
	daystring = new char[day];
	for (int i = 0; i < day; ++i)
	{
		daystring[i] = 1;
	}
	return daystring;
}
*/
void brute_force(int start,int end)
{
	//��Ʈ���� �̿��� ��¥ ����
	int idx;
	for(idx = 0; idx<(int)pow(2,end);++idx)
		for (int j = 0 ; j< end;++j)
			
		//end�� ��Ʈ ������ ��� 11111...�� ����ִ� �Լ� �ʿ���
		//�����غ��� �׳� �ϸ� ��
	printf("\n");
}
int main()
{
	int N;
	
	
	cin >> N;
	vector<int> day_table(N);
	vector<int> pay_table(N);
	int d, p;
	for (int i = 0; i < N; ++i)
	{
		cin >> d >> p;
		day_table[i] = d;
		pay_table[i] = p;
	}
	
	brute_force(d,p);
}