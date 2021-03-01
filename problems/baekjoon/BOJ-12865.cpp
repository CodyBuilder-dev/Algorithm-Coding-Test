//제목 : 평범한 배낭
//목적 : 물건들에 각각 무게와 가치가 정해져 있을 때, 가치를 최대화하도록 배낭에 넣는 법
/*조건 : 무게는 최대 10만, 물건의 무게도 최대 10만, 가치는 최대 1천
->즉, 가치의 최대합은 1억
*/

/*아이디어 :
1.이거 그리디로는 아마 절대 안 풀리게 해놨을거임
2.완탐도 O(2^N)이라 안될거임
->DP로 풀 밖에

물건들의 무게를 weight[]에 저장한다 치면 무게를 k만큼 넣었을때
최대 가치 V(k) = max(V(k-weight[0]),V(k-weight[1]),V(k-weight[2]),...)
*/


//느낀점 : pair의 배열 만들어서 써보기

#include <iostream>
#include <utility>

using namespace std;

int N, K;
pair<int,int> goods[101];
int value[100001];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;
		goods[i] = make_pair(w, v);
	}

}
