//제목 : 롤러코스터
//목적 : 레일에 조건이 주어졌을 때 속도를 가장 느리게 하는 롤러코스터 만들기
/*조건 : 레일 개수가 2*10^5이고 a,b가 어마무시하게 크다
dp/백트래킹을 쓰거나, 매번 계산 결과를 1000000007로 나눠서 해야 함
*/

/*아이디어 : 브루트
1. K개의 레일이 있을때, K개를 배열하는 경우의 수는 K!
->Fail
*/

/*아이디어2 : 재귀로 짜기 가능
하나 뽑기
그놈b랑 나머지 a랑 다 곱해보기
*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int T;
int N;
vector<pair<int, int>> railset;
int totalSum;
bool visited[200000];

void input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> railset[i].first >> railset[i].second;
	}
}

//재귀, 넘겨줘야 할 것은... 몇개를 뽑아야 하는가에 대한 정보
//합에대한 정보를 넘겨야하나?
void find_term_recur()
{
		
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();

		for(int j =0 ; j < N ; ++j)

		//테케 출력
		cout << '#' << i << ' ';
	}
	return 0;
}
