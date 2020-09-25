//���� : RGB�Ÿ�
//���� : ���� 3���� �� �� �ϳ��� ĥ�� ��, ��� ���� ĥ�ϴ� ����� �ּҰ�
//���� : ������ ���� ���� ������ ĥ�� �� ����. ���� �ִ� 1000���̴�

/*���̵�� : (DP�ΰ� ��ä�� �����Ѵ� ġ��)
1. �� ������ ����� ���� 2�̹Ƿ�, ������ 2�̰� ���̰� �� ������ Ʈ���� ����
�̷��� �ٵ� O(2^1000)�� �ǹǷ�, �׳� ��Ž�� �� ���� ����
-> �ڿ������� ��Ʈ��ŷ, DP�� �Ѿ�� ��
2. ��Ʈ��ŷ : ���ذ��� ���� ���� �˷��� �ּҰ����� ũ�� Ż��
3. DP? : ��ȭ�� vs �޸������̼�
->��ȭ���� �𸣰���. �Ƹ� �� �� ��
->�޸������̼�? i��° ���� ĥ�ϴ� ����� 1~i-1ĥ�ϴ� �ּҰ��� i��° �� ���ϱ�
4. ���ÿ� ���� �������� �پ��� ���� �޶����� DP ������
->
*/

/*����  : ���Ҿ����� ¥�Ⱑ �ָ���. ž�ٿ����� ¥����
*/
#include <iostream>

using namespace std;

int N;
int minCost[1000][3]; //i��° ���� j������ ĥ�� ���� �ּҰ�
int colorCost[1000][3]; //i��° ���� j������ ĥ�� �� ����

int calc_mincost(int num,int nowColor) //i��° ���� j������ ĥ�� ���� �ּҰ�
{
	//���� ���� ���
	if (minCost[num][nowColor] != 0) return minCost[num][nowColor];

	//���� ���� ���, �� �İ�� ���
	else {
		int minima = 987654321;
		for (int i = 0; i < 3; ++i) {
			if (nowColor == i)  continue; //���� ���̸� �پ����
			int temp = calc_mincost(num - 1, i)+colorCost[num][nowColor];
			if (temp < minima) minima = temp;
		}
		minCost[num][nowColor] = minima;

		return minima;
	}
		
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> colorCost[i][j];
	
	minCost[0][0] = colorCost[0][0];
	minCost[0][1] = colorCost[0][1];
	minCost[0][2] = colorCost[0][2];

	int minima = 987654321; //�ּҰ�
	for (int i = 0; i < 3; ++i) {//������ ���� ���ؼ� ã�ƺ���
		int temp = calc_mincost(N - 1, i);
		if (minima > temp) minima = temp;
	}

	
	//dp�迭 �� ����������� Ȯ��
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < 3; ++j)
	//		cout << minCost[i][j] << ' ';
	//	cout << '\n';
	//}
	cout << minima;
}