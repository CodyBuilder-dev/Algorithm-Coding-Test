//���� : �Ǻ���ġ �Լ�
//���� : �Ǻ���ġ ���� ���ϴ� ���� �ƴ϶�, ��Ϳ��� ȣ�� Ƚ���� ���϶�
//���� : N = 40,

/*���̵�� : ���� ���� ���Ϸ� ���� ����, ����� �׳� ������
f(0) = 1f(0)+0f(1)
f(1) = 0f(0)+1f(1)
f(2) = 1 + 1;
f(3) = 

*/



#include <iostream>
#include <utility>
#include <vector>

using namespace std;

//�Ǻ���ġ �� �׵�(f(0),f(1),....f(n))�� �迭�� ����
//pair�� first�� f(0)�� ���, second�� f(1)�� ���
//f(n) = xf(0)+yf(1)�÷� ǥ��
pair<int, int> fibonacci[41];

int T;
int N;

int main()
{

	fibonacci[0] = make_pair(1, 0);
	fibonacci[1] = make_pair(0, 1);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		if (N == 0) cout << fibonacci[0].first << ' ' << fibonacci[0].second << '\n';
		else if(N==1) cout << fibonacci[1].first << ' ' << fibonacci[1].second << '\n';
		else {
			for (int j = 2; j <= N; ++j)
			{
				fibonacci[j].first = fibonacci[j - 1].first + fibonacci[j - 2].first;
				fibonacci[j].second = fibonacci[j - 1].second + fibonacci[j - 2].second;
			}
			cout << fibonacci[N].first << ' '<< fibonacci[N].second << '\n';
		}
	}
}