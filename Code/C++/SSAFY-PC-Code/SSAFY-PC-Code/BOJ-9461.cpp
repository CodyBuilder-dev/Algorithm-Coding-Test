//제목 : 파도반 수열
//목적 : 나선형으로 삼각형을 추가할 때, 규칙 찾기
//조건 : 최대 삼각형을 100개까지 붙이기 가능

/*아이디어 : 수열이므로, 점화식 찾기
1. 앞에꺼는 모르겠는데, 5항부터는 규칙 있음?
->수학적 사고방식이면 5항 전의 것들을 찾으려 노력하겠지만
->컴퓨터적 사고방식은 그냥 5항 이후부터만 찾기 ㅋㅋㅋ
*/

#include <iostream>

using namespace std;

int N;
long long triangle[101];

int main()
{
	cin >> N;

	triangle[1] = 1;
	triangle[2] = 1;
	triangle[3] = 1;
	triangle[4] = 2;
	triangle[5] = 2;
	triangle[6] = 3;
	triangle[7] = 4;
	triangle[8] = 5;
	triangle[9] = 7;
	triangle[10] = 9;
	for (int i = 11; i <= 100; ++i)
		triangle[i] = triangle[i - 1] + triangle[i - 5];

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		cout << triangle[temp] << '\n';
	}
}