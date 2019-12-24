//���� : ����
//��ǥ : ������ �⺻���� ��ɾ�
//������ ����� ��� : ��ũ�� ����Ʈ�� �����? �迭�� �����?
//����� : STL���� �ѹ濡 �ȴ�!
//���̵�� : ��ɾ ���ڸ����� 2�ڸ����� �������� ���ڿ� ó�� �ʿ�
//�׳� ���ڿ�ó�� ���� ����, ��ɾ� ���� ����� 2ĭ¥���� �ѹ� �� ����
//��ɾ��� �迭�� ���� ���ϴ°� ������, �׳� getline�ؼ� �տ��͸� �Ľ��ϴ°� �´�.

//switch case ���� ���ڿ� ����ϱ�
//���������δ� map �̿��� string�� int�� ������Ű�� �� int�� switch�� ����

//1ĭ ��ɾ� : top,size,empty,pop
//2ĭ ��ɾ� : push 

//�Ұ� : map, stack�� ������ ��. �׷��� ���Ѱ� ��ؤ���
#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main()
{
	int N;
	stack<int> a;
	map<string, int> m;
	string first;
	int second;
	
	m.insert(make_pair("push", 1));
	m.insert(make_pair("pop", 2));
	m.insert(make_pair("size", 3));
	m.insert(make_pair("empty", 4));
	m.insert(make_pair("top", 5));
	//�ƴϸ�  m[Ű��] = ������; ���� �ʱ�ȭ�ص� ��

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> first;
		if (m[first] == 1) 
		{
			cin >> second;
		}
		switch (m[first])
		{
		case 1: a.push(second); break;
		case 2: 
			if (!a.empty()) {
				cout << a.top() << '\n';
				a.pop();
			}
			else cout << -1 << '\n';
			break;
		case 3:
			cout << a.size() << '\n'; break;
		case 4:
			cout << (a.empty() ? 1 : 0) << '\n'; break;
		case 5:
			if (!a.empty()) cout << a.top() << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}