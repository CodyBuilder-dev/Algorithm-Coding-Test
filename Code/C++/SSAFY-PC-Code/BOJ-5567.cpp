//���� : ��ȥ��
//���� : ģ�� ����Ʈ�� �а� �̷κ��� ��ȥ�Ŀ� �ʴ��� ����� ���� ���ϴ� ���α׷�
//���� : ģ���� �ִ� 500��, ����Ʈ�� �ִ� 10000��

/*���̵�� : �׷����� Ž���ϴٰ�, ���ǿ� ���缭 ���� �� �ִ°�...
(ģ�� ���踦 ������ ������ķ� ���� �� ����)
2. �ڽ��� ģ�� = ������Ŀ��� �ڱ����� ����� ģ��
3. ģ���� ģ�� = ��ĭ�� �ǳʴ� ���
*/

//������ : ������ Ž������ �˾Ҵµ�, �� �ܰ踸 �� �Ÿ� �ܼ� 2�� for������ Ž�� ����

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool chingu[500][500];
bool checked[500];


int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		chingu[a-1][b-1] = true;
		chingu[b-1][a-1] = true;
	}

	//���⼭���� �ڵ� ����

	for (int i = 1; i < N; ++i) //ģ���� ģ���� Ž��
	{
		if (chingu[0][i] == true)
		{
			checked[i] = true;
			for (int j = 1; j < N; ++j) {
				if (chingu[i][j] == true) checked[j] = true;
			}
		}
	}

	cout << count(checked, checked + N, true);

}