//���� : ����� �賶
//���� : ���ǵ鿡 ���� ���Կ� ��ġ�� ������ ���� ��, ��ġ�� �ִ�ȭ�ϵ��� �賶�� �ִ� ��
/*���� : ���Դ� �ִ� 10��, ������ ���Ե� �ִ� 10��, ��ġ�� �ִ� 1õ
->��, ��ġ�� �ִ����� 1��
*/

/*���̵�� :
1.�̰� �׸���δ� �Ƹ� ���� �� Ǯ���� �س�������
2.��Ž�� O(2^N)�̶� �ȵɰ���
->DP�� Ǯ �ۿ�

���ǵ��� ���Ը� weight[]�� �����Ѵ� ġ�� ���Ը� k��ŭ �־�����
�ִ� ��ġ V(k) = max(V(k-weight[0]),V(k-weight[1]),V(k-weight[2]),...)
*/


//������ : pair�� �迭 ���� �Ẹ��

#include <iostream>
#include <utility>

using namespace std;

int N, K;
pair<int,int> goods[101];
int value[100001];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;
		goods[i] = make_pair(w, v);
	}

}
