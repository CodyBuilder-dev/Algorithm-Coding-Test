//제목 : 문자열
//목적 : 문자열 A, B가 주어지고 A가 B보다 짧을때, A가 B와 가장 비슷하게 같아지는 방법

/*아이디어 : 발상 실패 (X)
0.넣을 때 다른 걸 넣진 않을 것이다. 
1. 맨 뒤에 넣는 경우에는 현재 차이와 같다.
2. 맨 앞에 넣는 경우에는, 한칸씩 뒤로 밀어서 비교하는것과 차이가 같다
3. 둘 중 작은거 선택한다.
*/

/*아이디어2 : 미리 B를 탐색하여 가장 최소가 되는 지점부터 더해넣기
0. 넣을 때 다른걸 넣진 않을 것이다.
1. B를 탐색한다.
2. 즉 차이가 최소가 되는 부분의 차이가 곧 차이이다.
*/

/*구현 : 문자열 하나씩만 쓰면 되므로, string 헤더를 써도 무방*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	
	int diff=0;
	int result = 987654;
	if (A.size() < B.size()) //사이즈가 다른 경우
	{
		for (int i = 0; i <= B.size()-A.size(); ++i){
			diff = 0;
			for(int j =0; j<A.size(); ++j)
				if (A[j] != B[i+j]) diff++;
			result = (result > diff) ? diff : result;
		}

	}
	else { //사이즈가 같은 경우
		for (int i = 0; i < A.size(); ++i)
			if (A[i] != B[i]) diff++;

		result = diff;
	}
	cout << result;

}