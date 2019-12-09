//제목 : 그림 비교
//목적 : 5x7크기의 그림의 색을 비교하여 가장 적게 다른 그림 찾기

/*아이디어 : 3차원배열에 저장하고,배열끼리 for문돌려서 비교
비교하면서 차이값을 min에 저장하기
*/

#include <iostream>
#include <utility>
using namespace std;

int N;
char picture[50][5][7];
int diff;
int minima=35;
pair<int, int> minidx;
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 7; ++k)
				cin >> picture[i][j][k];
	
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
		{
			diff = 0;
			for (int k = 0; k < 5; ++k)
				for (int l = 0; l < 7; ++l){
					if (picture[i][k][l] != picture[j][k][l]) diff++;
				}
			if (minima > diff) {
				minidx = make_pair(i+1, j+1);
				minima = diff;
			}
			
		}
	
	cout << minidx.first<<' ' << minidx.second;
	

}