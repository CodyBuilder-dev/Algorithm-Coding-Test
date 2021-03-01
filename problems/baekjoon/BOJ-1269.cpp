//제목 : 대칭 차집합
//목적 : 대칭 차집합의 원소의 개수를 출력
//유형 : 수학?
//조건 : 원소 개수 <= 200,000 원소값 100,000,000

/*아이디어 : 
논리적으로다가 그냥 전체 합집합에서 교집합 빼면 되자너
*/

/*구현
1. 기본 data로 집합을 구현한다
2. 그냥 stl set 쓴다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	
	vector<int> vecA, vecB;
	//중복되는 원소는 입력단에서부터 없다고 가정하고 vector 사용
	for (int i = 1; i <= N; ++i){
		int temp;
		cin >> temp;
		vecA.push_back(temp);
	}
	sort(vecA.begin(), vecA.end());
	for (int i = 1; i <= M; ++i)
	{
		int temp;
		cin >> temp;
		vecB.push_back(temp);
	}
	sort(vecB.begin(), vecB.end());
	//대칭차집합은 algorithm 함수 사용
	//정렬된 vector을 써야 함.그렇지 않으면 런타임 에러
	//set_symmetric_difference(
	vector<int> result;
	result.resize(vecA.size() + vecB.size());//공간확보
	vector<int>::iterator itr = set_symmetric_difference(vecA.begin(), vecA.end(), vecB.begin(), vecB.end(), result.begin());//교집합
	result.erase(itr, result.end());//남은공간 제거
	
	cout << result.size();
}