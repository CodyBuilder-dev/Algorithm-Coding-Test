//제목 : 정수 삼각형
//목적 : 특정 규칙으로 짠 '정수 삼각형'에서, 맨 위층부터 아래층으로 내려오면서 합이 최대가 되도록 하는 경로를 찾기
/*조건 : 삼각형의 크기는 500이하, 삼각형 안의 수는 1만 이하
->삼각형의 깊이가 500이므로, 완탐할 경우 O(2^500)이 나오게 되어 절대 탐색 불가. 강제 DP
->1만을 최대 500개만큼 선택하므로, 정수 범위 밖으로 벗어날 일은 없음
*/

/*아이디어 : DP/백트래킹 구현?
백트래킹 : 근데 현재까지 내려온 값이 최대값인지 아닌지 모르지 않나...일단은 오케이
DP : 점화식...이라기보단 메모이제이션 접근 고고
1. N층의 최대 경로 = N-1층의 각 경로에서 N층의 값을 더한 것 중 최대인 놈
N-1층의 각 경로= ...무한반복
트리로 그려보면 어떤 규칙으로 어디를 최적화해야 하는지 나온다. 
*/

/*구현 : 
1. 입력 받을때는, 2중 for문을 이용해서 배열에 받기
2. DP 자체는 탑다운 방식
*/

/*느낀점 : 
1. 1차원배열, 2차원배열의 특정값 초기화 방법 fill_n 잘 배워둘 것
2. 메모이제이션용으로 쓰는 배열은 0초기화/-1초기화 다르게 해야될 때가 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N; //삼각형의 크기
int triangle[500][500];
int maxPath[500][500];

void input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			cin >> triangle[i][j];
}

void print_tri()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j)
			cout << triangle[i][j] <<' ';
		cout << '\n';
	}	
}

void print_dp()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j)
			cout << maxPath[i][j] << ' ';
		cout << '\n';
	}

}


//y층 x번째까지의 최대경로 값을 찾아주는 dp함수
int find_max_dp(int y,int x)
{
	//있을시 탈출 
	if (maxPath[y][x] != -1) return maxPath[y][x];
	//없을시 저장
	else {
		int temp;
		if (x == 0) { //왼쪽 끝인 경우 신경써야됨
			temp = find_max_dp(y - 1, x) + triangle[y][x];
		}
		else if (x == y) { //오른쪽 끝인 경우 신경써야됨
			temp = find_max_dp(y - 1, x - 1) + triangle[y][x];
		}
		else {
			temp = max(find_max_dp(y - 1,x - 1) + triangle[y][x], find_max_dp(y - 1, x) + triangle[y][x]);
		}
		//저장
		maxPath[y][x] = temp;

		//반환
		return temp;
	}
}
int main()
{
	input();
	//잘 받아졌나 확인
	//print_tri();
	
	//dp배열 초기화
	fill_n(maxPath[0], 500*500, -1);
	maxPath[0][0] = triangle[0][0];
	//print_dp();
	int maxima = -987654321;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		temp = find_max_dp(N - 1, i);
		if (maxima < temp) maxima = temp;
	}

	//print_dp();
	cout << maxima;
	
}