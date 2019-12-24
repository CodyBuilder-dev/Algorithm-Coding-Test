//���� : ������ �����ֱ�
/*���� : N�� ���� ���̿� N-1�� �����ڸ� �������� ��,  �� ���� ����� ����Ͽ� �ִ밪 ã��
(�ߺ� ���ǰ�, ���� ������ �ִ� �����ڵ��� N-1�� ������ �� �ƴ°�.)
*/
//���� : N<=11, ������, �߰������ �ִ��ּҴ� +- 10���̹Ƿ� int ����

/*���̵��
1. + - * /�� ������ ������ �ִ�.
2. �� �����ļ� N-1���� �� �����ϴ� ����� ���� ���ϸ� �ȴ�.
(���� ���� �ִ� ����� ����. N-1!/+!-!*!/!)
(������ ���ϱ� ��� 
3. �� ��캰�� ������� �Լ��� ����� �����Ѵ�.
4. �ּҰ�, �ִ밪�� ���ذ��� ����Ѵ�.
*/

/*���� �� :
1.�������� �ִ� ����� ���� next_permutation���� ����
2.vector�� iterator�� ���� ���� ������ ��
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num;
	vector<char> operation;
	
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> temp;
		for (int j = 0;j<temp;++j)
			switch (i) {
			case 0: operation.push_back('+'); break;
			case 1: operation.push_back('-'); break;
			case 2: operation.push_back('*'); break;
			case 3: operation.push_back('/'); break;
			}
	}

	sort(operation.begin(), operation.end());

	/*������ �� �޾ҳ� Ȯ��
	for (int i = 0; i < operation.size(); ++i)
		cout << operation[i];
	*/

	//���⼭���� ������ �ڵ�
	
	int total;
	int min = 1000000000;
	int max = -1000000000;
	do
	{
		int idx = 0; //���ͷ����͸� ���� idx��
		total = num[idx];
		while (idx < N-1)
		{
			char op = operation[idx];
			switch (op) {
			case '+': total += num[idx + 1]; break;
			case '-': total -= num[idx + 1]; break;
			case '*': total *= num[idx + 1]; break;
			case '/': total /= num[idx + 1]; break;
			}
			idx++;
		}
		if (min > total) min = total;
		if (max < total) max = total;

	} while (next_permutation(operation.begin(), operation.end()));

	cout << max << '\n' << min;
	
	return  0;
}