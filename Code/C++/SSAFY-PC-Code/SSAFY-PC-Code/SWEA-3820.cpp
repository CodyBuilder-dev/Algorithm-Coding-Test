//���� : �ѷ��ڽ���
//���� : ���Ͽ� ������ �־����� �� �ӵ��� ���� ������ �ϴ� �ѷ��ڽ��� �����
/*���� : ���� ������ 2*10^5�̰� a,b�� ������ϰ� ũ��
dp/��Ʈ��ŷ�� ���ų�, �Ź� ��� ����� 1000000007�� ������ �ؾ� ��
*/

/*���̵�� : ���Ʈ
1. K���� ������ ������, K���� �迭�ϴ� ����� ���� K!
->Fail
*/

/*���̵��2 : ��ͷ� ¥�� ����
�ϳ� �̱�
�׳�b�� ������ a�� �� ���غ���
*/
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int T;
int N;
vector<pair<int, int>> railset;
int totalSum;
bool visited[200000];

void input()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> railset[i].first >> railset[i].second;
	}
}

//���, �Ѱ���� �� ����... ��� �̾ƾ� �ϴ°��� ���� ����
//�տ����� ������ �Ѱܾ��ϳ�?
void find_term_recur()
{
		
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();

		for(int j =0 ; j < N ; ++j)

		//���� ���
		cout << '#' << i << ' ';
	}
	return 0;
}
