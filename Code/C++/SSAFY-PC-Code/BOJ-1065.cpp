//제목 : 한수
//목적 : N보다 작은 한수의 개수
//조건 : N은 1000이하.

/*문제이해 : 한수란
ABC가 있을 떄, B-A = C-B인 수
아이디어 : 한수의 검증
1. 숫자를 받는게 아니라 생성해야 하므로, 10진수 자리별로 자르는 방법 필요
2. 각 자리수를 배열에 저장한다.
3. 배열의 처음부터 돌면서 각 자리수를 비교한다.
4. 차이가 다르면 바로 탈출, 같으면 계속 가기
5. 한수면 cnt++;
6. 반복
*/

/*구현 : 
1. 10진수를 자리별로 떼는 방법은... 그냥/10,%10 쓰기
*/

//느낀점 : 10진수를 다룰때는 자리수에 주의
#include <iostream>

using namespace std;

int numarray[4] = { 0, };

void divide_decimal(int num)
{
	//귀찮으니 for로 짜자
	int first;
	int decimal = 0;

	while (num != 0 || decimal<4)
	{
		first = num % 10;
		num = num / 10;
		numarray[decimal] = first;
		decimal+=1;

	}
}

int check_num(int decimal)
{
	int temp;
	int sub;
	if (decimal>=1)
	{
		sub = numarray[0] - numarray[1];
	}
	int hansu =1;
	for (int i = 0; i < decimal; ++i)
	{
		temp = numarray[i] - numarray[i + 1];
		if (temp != sub)
		{
			hansu = 0;
			break;
		}
	}
	return	hansu;
}
int main()
{
	int N;
	int cnt=0;
	cin >> N;

	
	for (int i = 1; i <= N; ++i)
	{
		if (i < 10) cnt++;
		else if (i < 100) {
			divide_decimal(i);
			check_num(1);
			if (check_num(1)) cnt++;
		}
		else if (i < 1000) {
			divide_decimal(i);
			check_num(2);
			if (check_num(2)) cnt++;
		}
		else {
			divide_decimal(i);
			check_num(3);
			if (check_num(3)) cnt++;
		}

		
	}
	cout << cnt;


}