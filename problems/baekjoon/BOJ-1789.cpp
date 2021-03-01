//제목 : 수들의 합
//목적 : 서로 다른 N개 자연수의 합S를 알때, N의 최대값은?

/*아이디어 : 1부터 더해가는게 N을 제일 최대로 늘릴수 있겠지?
1. 일종의 그리디 알고리즘 접근 ->안 풀릴 경우 대책 찾아야 함
2. 0/1 중복순열을 통한 접근 -> 너무 오래 걸릴것 같은데
3. for문과 재귀를 통한 완전접근 고고
*/

/*구현 :
1. 1부터 올라가면서 더함
2. n을 더했는데 초과할 경우 n을 빼고 cnt--하고 다시 n-1로 돌아감
3. n-1, n을 건너뛰고 n-2로 가서 반복?
1부터 더해가다가. 초과할 경우 그 수를 없애고, 그 전 수를 수정하면 됨
*/

//느낀점 : 그리디를 쓰되, 갯수만 체크하면 되므로 굳이 배열에 저장할 필요 없음

#include <iostream>
#include <vector>

using namespace std;

void find_max(long long n) //n은 찾고자 하는 수
{
	vector<long long> idxStack;

	long long i = 1;
	long long sum = 0;
	while (sum <= n)
	{
		sum += i;
		idxStack.push_back(i);
		i++;
		if (sum > n) {
			idxStack.pop_back();
			cout << idxStack.size();
		}
		
	}
}
int main()
{
	long long N;
	cin >> N;
	find_max(N);
}