#include <iostream>
//���ɰ� �ִ� 100�������� �� �� ����
//for �� �׳� ������ �ð��ʰ� ������ �߰� �Ǿ�����
//endl ���°͸����δ� ������

using namespace std;

int main() {
	int T;
	int A, B;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		//cin.tie(NULL);
		cout << A + B << "\n";
		ios::sync_with_stdio(false);
	}
}