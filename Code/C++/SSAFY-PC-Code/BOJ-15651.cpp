//���� : N�� M(3)
//���� : �������� ������ ��� �Ǵ� ����
//���� : M,N�� 7���Ϸ� ũ�� ����.
//�׳� 7!�ص� 5õ������ ��������
/*
���̵�� : ��, �ߺ������� ���ϴ� ���̴�.
�̰� �ٵ� ���� �����,��ͷ� for�� ������ �ȴ�.
for�� ������ �������Ǹ� �� �����ϰ� ¥�ָ� ����
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> numvec;

void print_dupperm(int n, int r)
{
	if (r == 0) {
		for (int j = 0; j < numvec.size(); ++j)
			cout << numvec[j] << ' ';
		if (!numvec.empty() && (numvec.back() == n)) {
			do {
				numvec.pop_back();
			} while (numvec.back() == n);
			if(!numvec.empty())numvec.pop_back();
		}
		else numvec.pop_back();
		printf("\n"); return;
	}

	for (int i = 1; i <= n; ++i)
	{
		numvec.push_back(i);
		print_dupperm(n, r - 1);
		
	}
	
}

int main()
{

	cin >> N >> M;

	print_dupperm(N, M);
}