#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int *n_list;
	int result;

	cin >> N;
	n_list = new int[N + 1];
	n_list[0] = N;

	for (int i = 1; i <= N; i++)
	{
		cin >> n_list[i];
		// �迭 1������ ��� ���� ���, �̷����� ä���� ����ó�� ���ɼ�!!
	}
	sort(&n_list[1], &n_list[N]);
	result = n_list[1] * n_list[N];
	cout << result << '\n';

}