//���� : ����
//���� : ���ڸ����� ������ �ڸ����� �����϶�

/*���̵�� : ���ڸ� ���ڸ��� �޾Ƽ� �迭�� ����
(������� �󸶳� ��������� ���� �� �ƴ���)
10�� �¼��� ���
*/

#include <iostream>
#include <cmath>
using namespace std;

int first[3];
int second[3];
int mult[3];
int main()
{
	scanf("%1d%1d%1d", &first[2], &first[1], &first[0]);

	scanf("%1d%1d%1d", &second[2], &second[1], &second[0]);

	
	for (int j = 0; j < 3; ++j) {//second ������
		for (int k = 0; k < 3; ++k) //first ������
			mult[j] += first[k] * pow(10, k) * second[j];

		cout << mult[j] << '\n';
	}
	int sum = 0;

	for (int i = 2; i >= 0; --i) {//�� �ڸ���	
		sum += mult[i] * pow(10, i);
	}
	cout << sum;
}
