//���� :���ĺ� �Ÿ�
//���� :���ڿ����� ���ĺ� �Ÿ��� ���ϴ� ��
//���� : �׽�Ʈ���̽��� �ִ� 100��, ���ڿ� �ִ� 20

/*���̵�� : ���ڿ��� ���ĺ��� ���ڸ� �����ϰ�, �� ũ�⸦ ���� �� �ִ°�
*/
#include <iostream>
#include <string>

using namespace std;

int T;
string x, y;
int main()
{
	cin >> T;
	for(int j = 0; j<T;++j){
		cin >> x >> y;

		cout << "Distances: ";
		for (int i = 0; i < x.length(); ++i)
		{
			if (x[i] <= y[i]) cout << (int)(y[i] - x[i]) << ' ';
			else cout << (int)(y[i] + 26 - x[i]) << ' ';
		}
		cout << '\n';
	}
}