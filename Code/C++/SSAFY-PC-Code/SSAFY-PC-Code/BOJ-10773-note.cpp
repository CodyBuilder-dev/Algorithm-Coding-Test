//���� : ����
//���� : ���ÿ� �� �ְ�, ���ÿ��� ������ �� ���ϱ�
//������ : ������ pop�ϴ� ���� ������ �����ǹǷ�, �μ��� �ʰ� ���ÿ��� ���� ���ϱ� ����� �� ����
//������ �迭�� ���°� ���� �� ����
//�Ұ� : �̰Ŵ� stack ���� 20ms�� ����Ǵ��� �� �׷���?
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int K;
	int temp;
	int sum = 0;
	stack<int> numstack;

	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		cin >> temp;
		if (temp == 0) numstack.pop();
		else numstack.push(temp);
	}
	//�̰� �� �ȵǳ�
	//for (int i = 1; i <= numstack.size(); ++i)
	while(!numstack.empty())
	{
		sum += numstack.top();
		numstack.pop();
	}
	cout << sum;
}