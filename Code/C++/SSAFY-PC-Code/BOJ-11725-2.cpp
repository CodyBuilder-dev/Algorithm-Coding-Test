//���� : Ʈ���� �θ� ã��
//���� : ���� tuple�Է¸����� Ʈ���� ��� ����� ����
//���� : ��� ����Ʈ����� ���� ����. ����� ������ �ִ� 10^5

/*���̵�� : 2�����迭�� �ȵǸ�, ��ũ�� ����Ʈ�� �����
*/

/*���̵�� : �׷����� �ƴϰ� Ʈ���� 2�����迭�� ���鷡�ϱ� �ȵ���
1. ����ü �����
2. �迭 �����
3. �� �� ������ �ֱ�
*/
#include <iostream>

using namespace std;

typedef struct {
	int left;
	int right;
	int value;
	int parent;
}NODE;

int N;
NODE* tree;
int main()
{
	cin >> N;
	//��Ʈ��1���̰� N���̹Ƿ� N+1ũ��� �����ؾ� ��
	tree = new NODE[N + 1];

	int a, b;
	
	pair<int, int>* pairArray; //pair�� �迭 ���� ����
	pairArray = new pair<int,int>[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		if (b < a) swap(a, b);
		pairArray[i] = make_pair(a, b);
	}

	for (int i = 0; i < N; ++i) //���ݺ��� pairArray�κ��� NODE�迭 ����
	{
		pairArray[i].first
	}

}
