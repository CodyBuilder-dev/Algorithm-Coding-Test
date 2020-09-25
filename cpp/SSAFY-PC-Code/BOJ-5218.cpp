//제목 :알파벳 거리
//목적 :문자열간의 알파벳 거리를 구하는 것
//조건 : 테스트케이스는 최대 100개, 문자열 최대 20

/*아이디어 : 문자열의 알파벳에 숫자를 대응하고, 그 크기를 비교할 수 있는가
*/
#include <iostream>
#include <string>

using namespace std;

int T;
string x, y;
int main()
{
	cin >> T;
	for(int j = 0; j<T;++j){
		cin >> x >> y;

		cout << "Distances: ";
		for (int i = 0; i < x.length(); ++i)
		{
			if (x[i] <= y[i]) cout << (int)(y[i] - x[i]) << ' ';
			else cout << (int)(y[i] + 26 - x[i]) << ' ';
		}
		cout << '\n';
	}
}