//제목 : 피보나치 수
//목적 : 뭘로 풀라는지는 명확하지 않음
//n의 범위가 45보다 작음. 시간제한은 1초

//아이디어 : 그냥 재귀로 푼다
/*문제점 
n이 불과 45밖에 되지 않음에도, 굉장히 많은 시간이 걸림
시간복잡도가 트리를 따라가므,로 2^n임
fibonacci(45)의 결과값은 1,134,903,170
따라서 제출하면 반드시 시간초과
*/

/*해결
재귀를 할거면 중복 call이 문제이므로, 메모이제이션 통해 해결
전역변수 리스트에 피보나치 값을 넣어놓고, 호출할때 참조
*/
#include <iostream>

using namespace std;

//전역 피보나치 array
int fiboarray[45] = { 0 };

int fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		if (fiboarray[n] != 0) return fiboarray[n];
		else
		{
			fiboarray[n] = fibonacci(n - 1) + fibonacci(n - 2);
			return fiboarray[n];
		}
	}
}
int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n);
}