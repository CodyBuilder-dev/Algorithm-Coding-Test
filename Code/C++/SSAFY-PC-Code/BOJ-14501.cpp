//제목 : 퇴사
//목적 : 상담표를 보고, 남은기간 중 수익이 최대로 되도록 상담 잡기
//조건 : N<15이므로, 다 따져봐도 2^15 = 32000정도. O(NlogN)으로 할만 함

/*
아이디어1(폐기) : 
1. 일자별로 할지 안할지를 day개의 비트에 저장함 day비트는 정수로는 2^bit-1까지
2. 모든 경우의 수에 대해 valid한지 다 따져봄.(브루트 포스)
3. 조건에 안 맞으면 거름.
4. 조건을 모두 만족하면 그때 수익 저장
결과값 저장은  그냥 값만 얻으면 되니 max로 한다.
max보다 작으면 버리고 max보다 크면 갈아치운다.
*/

/*
느낀점 : 배열에서 특정위치의 원소들을 동시에 선택하는건 어려움
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
	//비트연산 이용한 날짜 선택
	int idx;
	for(idx = 0; idx<(int)pow(2,end);++idx)
		for (int j = 0 ; j< end;++j)
			
		//end의 비트 개수를 얻어 11111...을 얻어주는 함수 필요함
		//생각해보니 그냥 하면 됨
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