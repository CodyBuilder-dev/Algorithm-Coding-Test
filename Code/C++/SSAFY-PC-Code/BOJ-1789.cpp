//���� : ������ ��
//���� : ���� �ٸ� N�� �ڿ����� ��S�� �˶�, N�� �ִ밪��?

/*���̵�� : 1���� ���ذ��°� N�� ���� �ִ�� �ø��� �ְ���?
1. ������ �׸��� �˰��� ���� ->�� Ǯ�� ��� ��å ã�ƾ� ��
2. 0/1 �ߺ������� ���� ���� -> �ʹ� ���� �ɸ��� ������
3. for���� ��͸� ���� �������� ���
*/

/*���� :
1. 1���� �ö󰡸鼭 ����
2. n�� ���ߴµ� �ʰ��� ��� n�� ���� cnt--�ϰ� �ٽ� n-1�� ���ư�
3. n-1, n�� �ǳʶٰ� n-2�� ���� �ݺ�?
1���� ���ذ��ٰ�. �ʰ��� ��� �� ���� ���ְ�, �� �� ���� �����ϸ� ��
*/

//������ : �׸��� ����, ������ üũ�ϸ� �ǹǷ� ���� �迭�� ������ �ʿ� ����

#include <iostream>
#include <vector>

using namespace std;

void find_max(long long n) //n�� ã���� �ϴ� ��
{
	vector<long long> idxStack;

	long long i = 1;
	long long sum = 0;
	while (sum <= n)
	{
		sum += i;
		idxStack.push_back(i);
		i++;
		if (sum > n) {
			idxStack.pop_back();
			cout << idxStack.size();
		}
		
	}
}
int main()
{
	long long N;
	cin >> N;
	find_max(N);
}