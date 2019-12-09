//제목 : 거북이
//목적 : 거북이의 걸음을 통해 만들 수 있는 가장 큰 정사각형
//조건 : 정수 4개는 각각 100미만의 자연수
//유형 : 수학+정렬
/*
아이디어 : 정수 4개를 순서대로 쓰면서 사각형 만들기
1. 브루트 포스를 이용해 시뮬 만들고, 2차원배열, DFS를 이용해 계산한다
2. 사각형 최대넓이의 조건을 이해해 만든다.
*/

/*
사각형의 성립 조건
1. 솔직히 공식은 모르겠다
2. 근데 느낌상 길 짧 길 짧이다
3. 그럼 오름차순 정렬하고 front back front back 하면 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> walk;
	
	for (int i = 1; i <= 4; ++i)
	{
		int temp;
		cin >> temp;
		walk.push_back(temp);
	}

	sort(walk.begin(), walk.end());

	cout << walk[0] * walk[2];

}