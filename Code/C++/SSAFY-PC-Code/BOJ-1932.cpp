//���� : ���� �ﰢ��
//���� : Ư�� ��Ģ���� § '���� �ﰢ��'����, �� �������� �Ʒ������� �������鼭 ���� �ִ밡 �ǵ��� �ϴ� ��θ� ã��
/*���� : �ﰢ���� ũ��� 500����, �ﰢ�� ���� ���� 1�� ����
->�ﰢ���� ���̰� 500�̹Ƿ�, ��Ž�� ��� O(2^500)�� ������ �Ǿ� ���� Ž�� �Ұ�. ���� DP
->1���� �ִ� 500����ŭ �����ϹǷ�, ���� ���� ������ ��� ���� ����
*/

/*���̵�� : DP/��Ʈ��ŷ ����?
��Ʈ��ŷ : �ٵ� ������� ������ ���� �ִ밪���� �ƴ��� ���� �ʳ�...�ϴ��� ������
DP : ��ȭ��...�̶�⺸�� �޸������̼� ���� ���
1. N���� �ִ� ��� = N-1���� �� ��ο��� N���� ���� ���� �� �� �ִ��� ��
N-1���� �� ���= ...���ѹݺ�
Ʈ���� �׷����� � ��Ģ���� ��� ����ȭ�ؾ� �ϴ��� ���´�. 
*/

/*���� : 
1. �Է� ��������, 2�� for���� �̿��ؼ� �迭�� �ޱ�
2. DP ��ü�� ž�ٿ� ���
*/

/*������ : 
1. 1�����迭, 2�����迭�� Ư���� �ʱ�ȭ ��� fill_n �� ����� ��
2. �޸������̼ǿ����� ���� �迭�� 0�ʱ�ȭ/-1�ʱ�ȭ �ٸ��� �ؾߵ� ���� ����
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N; //�ﰢ���� ũ��
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


//y�� x��°������ �ִ��� ���� ã���ִ� dp�Լ�
int find_max_dp(int y,int x)
{
	//������ Ż�� 
	if (maxPath[y][x] != -1) return maxPath[y][x];
	//������ ����
	else {
		int temp;
		if (x == 0) { //���� ���� ��� �Ű��ߵ�
			temp = find_max_dp(y - 1, x) + triangle[y][x];
		}
		else if (x == y) { //������ ���� ��� �Ű��ߵ�
			temp = find_max_dp(y - 1, x - 1) + triangle[y][x];
		}
		else {
			temp = max(find_max_dp(y - 1,x - 1) + triangle[y][x], find_max_dp(y - 1, x) + triangle[y][x]);
		}
		//����
		maxPath[y][x] = temp;

		//��ȯ
		return temp;
	}
}
int main()
{
	input();
	//�� �޾����� Ȯ��
	//print_tri();
	
	//dp�迭 �ʱ�ȭ
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