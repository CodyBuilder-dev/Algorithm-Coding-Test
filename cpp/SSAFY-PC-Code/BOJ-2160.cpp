//���� : �׸� ��
//���� : 5x7ũ���� �׸��� ���� ���Ͽ� ���� ���� �ٸ� �׸� ã��

/*���̵�� : 3�����迭�� �����ϰ�,�迭���� for�������� ��
���ϸ鼭 ���̰��� min�� �����ϱ�
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