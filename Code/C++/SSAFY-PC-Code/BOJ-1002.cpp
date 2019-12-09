//���� : �ͷ�
//���� : �ͷ�1�� �ͷ�2�κ��� ������ �Ÿ��� �־����� �� ������ ���簡���� ��ġ�� ����
//���� : ��ǥ ������ �ִ� -1��~1��

/*���̵�� : �� ���� ��ġ���踦 �˰����� �̿��� ���̴� ��
1. ������ ��ǥ�迡�� �Ǽ��� ��� ��Ÿ�� ���ΰ�
2. ���Ѱ��� ������ ���Ѱ��� ��ǻ�Ϳ� ��� ���� ���ΰ�
3. ��Ÿ�� �Ŀ�, ��ġ���� �Ǵ��� ��� �� ���ΰ�
...
�ذ�å : �Ųٷ� ����ϱ�!
1. ������ ��ǥ�� ���ϰ�, �ű⼭���� �Ÿ��� ����Ѵ� 
2. �Ÿ��� ���� ���̽� �з��ؼ� ���
������ �Ÿ��� 
*/

/*������ : 
1.float�� double�� ���� Ȯ����
2.�Ǽ�-�Ǽ��� ��, �Ǽ�-���� �� Ȯ����
3.sqrt�� ������ ����ٰ� ��.
->���, �Ǽ��� logical�� ���α׷����� ��¥ �ظ��ϸ� ���� ����
->�ٵ�, realistical�� ���������� �Ǽ��� ��ߵǳ�? ���� ����
*/
#include <iostream>
#include <cmath>

using namespace std;

typedef struct point {
	int y;
	int x;
}POINT;

int T;
POINT t1, t2;
POINT marine;
int R1, R2;
double D;
double mindelta = 10e-7;

float calc_dist(POINT p1, POINT p2)
{
	int yDiff, xDiff;
	yDiff = p1.y - p2.y;
	xDiff = p1.x - p2.x;
	double D;
	D = (yDiff * yDiff + xDiff * xDiff);

	return D;
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> t1.x >> t1.y >> R1 >> t2.x >> t2.y >> R2;
		D = calc_dist(t1, t2);

		//�켱 ������ ���� ���̽����� ó��
		if (t1.x == t2.x && t1.y == t2.y) {
			if (R1 == R2) cout << -1;
			else cout << 0;
		}
		else { //������ �ٸ� ���̽�
			if (D - pow(R1 + R2,2) > mindelta ) cout << 0;
			else if (D - pow(R1+R2,2) < mindelta) cout << 1;
			else if (pow(R1+R2,2) -D > mindelta && D - pow(R1-R2,2) > mindelta) cout << 2;
			else if (D - pow(R1-R2,2) < mindelta) cout << 1;
			else cout << 0;
		}

	}	

	return 0;
}