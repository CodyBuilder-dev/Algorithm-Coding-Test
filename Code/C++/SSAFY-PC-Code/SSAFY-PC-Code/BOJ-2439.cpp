//제목 : 별 찍기 - 2
//목적 : 조건에 맞게 화면에 별을 출력하는 문제
//조건 : 행은 최대 100개

#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) //논리를 명확히 해야 함
			if (j > N-i) cout << '*'; //왼쪽은 ' ', 오른쪽부터 i칸은 *이므로
			else cout << ' ';
		cout << '\n';
	}
}