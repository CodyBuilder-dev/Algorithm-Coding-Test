//제목 : 시험 감독
//목적 : 감독관 수의 최소값
//조건 : 시험장과 응시자와 감독관의 수가 10^6이므로 계산 부하 주의
//주의 : 각각의 수는 int 범위 내일지라도, 각 수의 합은 int 범위를 초과할 수 있다.

/*아이디어 :
감독관의 수는 그냥 공식으로 계산하면 되지 않나
총감독관이 꼭 있어야 된다는 법은 없지?

case 1 : B>C이면 총 포함 1+(A-B)/C
case 2 : B<C이면 총 필요 없음 A/C

이때 정수니까 소수점 처리 주의.

995/100 =9
*/

/*아이디어 2 :
케이스를 보니 총감독관은 반드시 있어야 함

case 1 : A<=B이면 1
case 2 : C>A>B이면 A-B/C 소수
case 3 : A>B>C이면 A-B/C 정수

5-2/10 = 0,3
10-2/3 = 2,2
*/

#include <iostream>

using namespace std;

int main()
{
	int N, B, C;
	int *A;
	
	int cnt;
	long long sum=0;
	
	cin >> N;

	A = new int[N];
	for (int i = 0; i < N; ++i) cin >> A[i];
	
	cin >> B >> C;
	
	for (int i = 0; i < N; ++i)
	{
		if (A[i] <= B) cnt = 1;
		else {
			if ((A[i] - B) % C == 0) cnt = 1 + (A[i] - B) / C;
			else cnt = 2 + (A[i] - B) / C;
		}

		sum += cnt;
	}
	cout << sum;

	return 0;
}

